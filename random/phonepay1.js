const Event = require("../../models/event.model.js");
const Receipt = require("../../models/tickets/receipt.model.js");
const asyncHandler = require("express-async-handler");
const shortid = require("shortid");
const crypto = require("crypto");
const ticketCategory = require("../../models/tickets/ticketcategory.model.js");
const cache = require("../../utils/nodeCache.js");
const checkStatus = require("../../utils/phonpeStatusCheck.js");
const attendee = require("./../attendee.service.js");
const {
  decreaseTicketCount,
  increaseTicketCount,
} = require("./../ticket.service.js");
const receiptEmail = require("../../utils/receiptEmail.util.js");

exports.paymentWithPhonePeInit = asyncHandler(async (req, res) => {
  const ticketId = req.body.ticketId;
  const eventId = req.body.eventId;
  const amount = req.body.amount; //in ruppes
  const transactionId = req.body.transactionId; //merchantTransactionId
  const userData = req.body.userData;
  const couponId = req.body.couponId ? req.body.couponId : "";
  const discount = req.body.discount ? req.body.discount : 0;
  const ticketData = await ticketCategory
    .findById(ticketId)
    .populate("eventId");
  console.log(ticketData);

  // try {
  const ticket = await ticketCategory.findById(ticketId);
  const event = await Event.findById(eventId);
  // console.log(ticket, "ticket");
  // if (!ticket || JSON.stringify(ticket.eventId) !== JSON.stringify(eventId)) {
  //   return res.status(400).json({ message: "Ticket not found" });
  // }
  if (!event) {
    return res.status(400).json({ message: "Event not found" });
  }
  if (!ticket) {
    return res.status(400).json({ message: "Ticket not found" });
  }

  const findTicketCategoryById = (ticketCategoryId) => {
    const ticketCategories = event.ticketCategories;
    return ticketCategories.find(
      (ticketCategory) => ticketCategory._id === ticketCategoryId
    );
  };

  findTicketCategoryById(ticketId);

  if (!findTicketCategoryById) {
    return res.status(400).json({ message: "Ticket not found in the event" });
  }

  const receipt = await Receipt.findOne({
    "payment.merchantTransactionId": transactionId,
  });
  if (receipt) {
    return res
      .status(400)
      .json({ message: "Internal Server Error! Please retry" });
  }
  var data = {
    merchantId: `${
      process.env.NODE_ENV === "development"
        ? process.env.PHONPE_MERCHANT_ID
        : process.env.PHONEPE_PROD_MERCHANT_ID
    }`,
    merchantTransactionId: transactionId,
    merchantUserId: "MUID123",
    amount: amount * 100,
    redirectUrl: `${
      process.env.NODE_ENV === "development"
        ? process.env.PHONEPE_REDIRECT_URL
        : process.env.PHONEPE_PROD_REDIRECT_URL
    }?transactionId=${transactionId}`,
    redirectMode: "REDIRECT",
    callbackUrl: `${
      process.env.NODE_ENV === "development"
        ? process.env.PHONEPE_CALLBACK_URL
        : process.env.PHONEPE_PROD_CALLBACK_URL
    }`,
    mobileNumber: ${process.env.PHONEPE_MERCHANT_NUMBER},
    paymentInstrument: {
      type: "PAY_PAGE",
    },
  };

  var encode = btoa(JSON.stringify(data));
  var saltKey = `${
    process.env.NODE_ENV === "development"
      ? process.env.PHONEPE_SALT_KEY
      : process.env.PHONEPE_PROD_SALT_KEY
  }`;
  var saltIndex = 1;
  var string = encode + "/pg/v1/pay" + saltKey;
  var sha256 = crypto.createHash("sha256").update(string).digest("hex");

  var checkSum = sha256 + "###" + saltIndex; //checkSum
  let ans;
  if (Array.isArray(userData)) {
    ans = await decreaseTicketCount(ticketId, couponId, userData.length);
  } else {
    ans = await decreaseTicketCount(ticketId, couponId);
  }
  if (!ans) return res.status(400).json({ message: "Ticket not available" });
  const cacheSuccess = cache.set(
    transactionId,
    {
      checkSum,
      amount: amount * 100,
      ticket: ticketId,
      userData: userData,
      couponId: couponId,
      discount,
      eventId,
      multiple: userData?.users ? Array.isArray(userData.users) : false,
    },
    10000
  );
  console.log(cacheSuccess, "cacheSuccess saved status");

  const response = await fetch(
    `${
      process.env.NODE_ENV === "development"
        ? process.env.PHONEPE_API_LINK
        : process.env.PHONEPE_PROD_API_LINK
    }/pg/v1/pay`,
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "X-VERIFY": checkSum,
      },
      body: JSON.stringify({
        request: encode,
      }),
    }
  );

  const result = await response.json();
  console.log(result, "result");
  if (result) {
    console.log(result, "result");
    res.send(result);
    console.log(result.data.instrumentResponse.redirectInfo.url);
  }
});

exports.paymentWithPhonePeCallbackVerify = async (req, res) => {
  const header = req.headers["x-verify"];
  console.log(header, "req.headers");
  const { response } = req.body;

  try {
    // convert base64 to json
    const responseJson = JSON.parse(atob(response));
    console.log(responseJson, "responseJson");
    const cachedData = cache.get(responseJson.data.merchantTransactionId);
    console.log(cachedData, "cachedData-id");
    if (cachedData == undefined) {
      console.log("cant find cache");
      return;
    }
    if (
      // cachedData.checkSum !== header ||
      cachedData.amount !== responseJson.data.amount
    ) {
      console.log(cachedData.checkSum, " cachedData.checkSum");
      console.log(header, "header");
      console.log(cachedData.amount, "cachedData.amount");
      console.log(responseJson.data.amount, "responseJson.data.amount");
      console.log("cant match amount or  checksum");
      return;
    }
    if (responseJson.code === "PAYMENT_SUCCESS") {
      const paymentReceipt = {
        merchantTransactionId: responseJson.data.merchantTransactionId,
        transactionId: responseJson.data.transactionId,
        paymentType: responseJson.data.paymentInstrument.type,
        amount: responseJson.data.amount / 100,
        status: responseJson.code,
      };
      const ticket = await ticketCategory
        .findById(cachedData.ticket)
        .populate("eventId");
      console.log(paymentReceipt, "paymentReceipt saved 280");
      const eventId = cachedData.eventId;
      const event = await Event.findById(eventId);

      if (!ticket) {
        return;
      }
      const url = await receiptEmail({
        email: cachedData?.multiple
          ? cachedData.userData.email
          : cachedData.userData[0].email,
        merchantTransactionID: responseJson.data.merchantTransactionId,
        eventName: event.title,
        ticketName: ticket.name,
        amount: responseJson.data.amount / 100,
        discount: cachedData.discount,
      });
      const receipt = new Receipt({
        payment: paymentReceipt,
        ticketCategoryId: cachedData.ticket,
        purchasePrice: responseJson.data.amount / 100,
        couponId: cachedData?.couponId || "",
        receiptUrl: url,
        numberOfTickets: cachedData?.multiple
          ? cachedData.userData.users.length
          : 1,
        status: "SUCCESS",
        merchantTransactionId: responseJson.data.merchantTransactionId,
      });
      if (!ticket.eventId) {
        ticket.eventId = event._id;

        await ticket.save();
      }

      await receipt.save();
      event.receipts.push(receipt._id);
      await event.save();
      console.log(receipt, "receipt saved 293");

      // cache.del(responseJson.data.merchantTransactionId);
      // return res.status(200).json({ message: "Payment verified successfully" });
    } else {
      //pending or failed
      const paymentReceipt = {
        merchantTransactionId: responseJson.data.merchantTransactionId,
        transactionId: responseJson.data.transactionId,
        // paymentType: data.data.paymentInstrument.type,
        amount: responseJson.data.amount / 100,
        status: responseJson.code,
      };
      console.log(paymentReceipt, "paymentReceipt 301");
      const receipt = new Receipt({
        payment: paymentReceipt,
        purchasePrice: responseJson.data.amount / 100,
        ticketCategoryId: cachedData.ticket,
        couponId: cachedData?.couponId || "",
        numberOfTickets: cachedData?.multiple
          ? cachedData.userData.users.length
          : 1,
        status: "FAILED",
        merchantTransactionId: responseJson.data.merchantTransactionId,
      });

      await receipt.save();
    }
    console.log(receipt, "receipt 313");
    return;
  } catch (error) {}
};

exports.paymentWithPhonePeVerify = async (req, res) => {
  const merchantTransactionId = req.params.merchantTransactionId;
  console.log(merchantTransactionId, "merchantTransactionId");
  try {
    const receipt = await Receipt.findOne({
      "payment.merchantTransactionId": merchantTransactionId,
    });

    if (!receipt) {
      return res
        .status(400)
        .json({ message: "Invalid transaction Id! Please retry" });
    }

    if (receipt.user) {
      return res.status(400).json({
        message: "Payment already verified",
        status: receipt.payment.status,
        url: receipt.receiptUrl,
      });
    }

    console.log(receipt, "saved receipt 332");

    const cachedData = cache.get(merchantTransactionId);

    const ticket = await ticketCategory
      .findById(cachedData.ticket)
      .populate("eventId");

    if (receipt.payment.status === "PAYMENT_SUCCESS") {
      if (cachedData?.multiple) {
        //todo
        req.body.users = cachedData.userData.users;
        req.body.eventId = cachedData.eventId;
        req.body.type = "ticket";
        req.body.receiptId = receipt._id;
        const response = await attendee.registerGroupForEvent(req, res);
        receipt.user = response[0]._id;
      } else {
        req.body = cachedData.userData;
        req.body.eventId = cachedData.eventId;
        req.body.type = "ticket";
        req.body.receiptId = receipt._id;
        const response = await attendee.registerAttendeeForEvent(req, res);
        console.log(response);
        receipt.user = response._id;
      }
      await receipt.save();
      return res.status(200).json({
        message: "Payment verified successfully",
        url: receipt.receiptUrl,
      });
    } else {
      var saltKey = `${
        process.env.NODE_ENV === "development"
          ? process.env.PHONEPE_SALT_KEY
          : process.env.PHONEPE_PROD_SALT_KEY
      }`;
      const result = await checkStatus(merchantTransactionId, saltKey);
      const cachedData = cache.get(merchantTransactionId);
      const eventId = cachedData.eventId;
      let response;
      const event = await Event.findById(eventId);

      if (!ticket.eventId) {
        ticket.eventId = event._id;

        await ticket.save();
      }

      if (result.code !== "PAYMENT_PENDING") {
        if (cachedData?.multiple) {
          req.body.users = cachedData.userData.users;
          req.body.eventId = cachedData.eventId;
          req.body.type = "ticket";
          req.body.receiptId = receipt._id;
          req.body.success = result.code === "PAYMENT_SUCCESS" ? true : false;
          const response = await attendee.registerGroupForEvent(req, res);
          receipt.user = response[0]._id;
        } else {
          req.body = cachedData.userData;
          req.body.eventId = cachedData.eventId;
          req.body.type = "ticket";
          req.body.receiptId = receipt._id;
          req.body.success = result.code === "PAYMENT_SUCCESS" ? true : false;
          response = await attendee.registerAttendeeForEvent(req, res);
          receipt.user = response._id;
        }
        event.receipts.push(receipt._id);
        await event.save();
      }

      if (result.code === "PAYMENT_SUCCESS") {
        receipt.payment.status = "PAYMENT_SUCCESS";
        receipt.payment.paymentType = result.data.paymentInstrument.type;
        receipt.status === "SUCCESS";
        receipt.merchantTransactionId = merchantTransactionId;

        const url = await receiptEmail({
          email: cachedData?.multiple
            ? cachedData.userData.email
            : cachedData.userData[0].email,
          merchantTransactionID: merchantTransactionId,
          eventName: event.title,
          ticketName: ticket.name,
          amount: result.data.amount / 100,
          discount: cachedData.discount,
        });
        receipt.receiptUrl = url;

        await receipt.save();
        cache.del(merchantTransactionId);
        return res
          .status(200)
          .json({ message: "Payment verified successfully", url: url });
      } else if (result.code === "PAYMENT_ERROR") {
        const url = await receiptEmail({
          email: cachedData?.multiple
            ? cachedData.userData.email
            : cachedData.userData[0].email,
          merchantTransactionID: merchantTransactionId,
          eventName: event.title,
          ticketName: ticket.name,
          amount: result.data.amount / 100,
          discount: cachedData.discount,
          type: "FAILURE",
        });
        receipt.payment.status = result.code;
        receipt.receiptUrl = url;
        receipt.status = "FAILED";
        receipt.merchantTransactionId = merchantTransactionId;
        await receipt.save();

        increaseTicketCount(cachedData.ticket, cachedData.couponId);

        cache.del(merchantTransactionId);
        return res.status(400).json({ message: "Payment failed", url: url });
      } else if (result.code === "PAYMENT_DECLINED") {
        const url = await receiptEmail({
          email: cachedData?.multiple
            ? cachedData.userData.email
            : cachedData.userData[0].email,
          merchantTransactionID: merchantTransactionId,
          eventName: ticket.eventId.title,
          ticketName: ticket.name,
          amount: result.data.amount / 100,
          discount: cachedData.discount,
          type: "FAILURE",
        });

        receipt.payment.status = result.code;
        receipt.receiptUrl = url;
        receipt.status = "FAILED";
        receipt.merchantTransactionId = merchantTransactionId;
        await receipt.save();

        increaseTicketCount(cachedData.ticket, cachedData.couponId);

        cache.del(merchantTransactionId);
        return res.status(400).json({ message: "Payment declined", url: url });
      } else if (result.code === "PAYMENT_PENDING") {
        return res
          .status(400)
          .json({ message: "Payment pending", retry: true });
      } else {
        const url = await receiptEmail({
          email: cachedData?.multiple
            ? cachedData.userData.email
            : cachedData.userData[0].email,
          merchantTransactionID: merchantTransactionId,
          eventName: event.title,
          ticketName: ticket.name,
          amount: result.data.amount / 100,
          discount: cachedData.discount,
          type: "FAILURE",
        });
        receipt.payment.status = result.code;
        receipt.receiptUrl = url;
        receipt.status = "FAILED";
        receipt.merchantTransactionId = merchantTransactionId;
        await receipt.save();

        increaseTicketCount(cachedData.ticket, cachedData.couponId);
        cache.del(merchantTransactionId);
        return res.status(400).json({ message: "Payment failed", url: url });
      }
    }
  } catch (error) {}
};

exports.initRefund = async (req, res) => {
  const originalTransactionId = req.body.transactionId;
  const amount = req.body.amount;
  const merchantTransactionId = originalTransactionId + "ref";
  try {
    const data = {
      merchantId: "MERCHANTUAT",
      merchantUserId: "User123",
      originalTransactionId: originalTransactionId,
      merchantTransactionId: merchantTransactionId,
      amount: amount * 100,
      callbackUrl: "https://webhook.site/callback-url",
    };
    var encode = btoa(JSON.stringify(data));
    var saltKey = 099eb0cd-02cf-4e2a-8aca-3e6c6aff0399;
    var saltIndex = 1;
    var string = encode + "/pg/v1/refund" + saltKey;
    var sha256 = crypto.createHash("sha256").update(string).digest("hex");

    var checkSum = sha256 + "###" + saltIndex;

    cache.set(merchantTransactionId, {
      checkSum: checkSum,
    });
    const options = {
      method: "POST",
      headers: {
        accept: "application/json",
        "Content-type": "application/json",
        "X-VERIFY": checkSum,
      },
      body: JSON.stringify({ request: encode }),
    };

    const response = await fetch(
      "https://api-preprod.phonepe.com/apis/pg-sandbox/pg/v1/refund",
      options
    );

    const result = await response.json();

    console.log(result);

    const res = await checkStatus(result.data.merchantTransactionId, saltKey);

    res.send(res);
  } catch (error) {}
};