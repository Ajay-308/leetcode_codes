const axios = require("axios");

// Function to generate a random string
function generateRandomString(length) {
  const characters =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  let result = "";
  for (let i = 0; i < length; i++) {
    result += characters.charAt(Math.floor(Math.random() * characters.length));
  }
  return result;
}

// Generate random merchantId and transactionId
const merchantId = generateRandomString(12); // Simulated random merchant ID (should be provided by PhonePe)
const transactionId =
  "txn_" + new Date().getTime() + "_" + Math.floor(Math.random() * 1000000);

const options = {
  method: "post",
  url: "https://api-preprod.phonepe.com/apis/pg-sandbox/pg/v1/pay",
  headers: {
    accept: "text/plain",
    "Content-Type": "application/json",
  },
  data: {
    merchantId: merchantId,
    transactionId: transactionId,
    amount: {
      value: "10000",
      currency: "INR",
    },
    redirectUrl: "https://your-redirect-url.com",
    callbackUrl: "https://your-callback-url.com",
    productInfo: "Test product",
    customerInfo: {
      name: "John Doe",
      email: "john.doe@example.com",
      phone: "1234567890",
    },
  },
};

axios
  .request(options)
  .then(function (response) {
    console.log(response.data);
  })
  .catch(function (error) {
    console.error(error);
  });
