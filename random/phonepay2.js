const crypto = require('crypto');
const axios = require('axios');

const checkStatus = async ( merchantTransactionId , salt, index = 1) => {
  console.log("checkStatus 1")
  const merchantId = ${process.env.NODE_ENV === "development" ? process.env.PHONPE_MERCHANT_ID: process.env.PHONEPE_PROD_MERCHANT_ID }
  const string =
    /pg/v1/status/${merchantId}/${merchantTransactionId} + salt;

    console.log(string, "checkStatus 2");
  var sha256 = crypto.createHash("sha256").update(string).digest("hex");
  sha256 = sha256 + ###${index};
  try {
    var result = await apiCall(merchantId, merchantTransactionId, sha256);
  console.log(result, "checkStatus 44")
    return result;
  } catch (error) {}
};

const apiCall = async (merchantId, merchantTransactionId, sha256) => {
  try{
    console.log(process.env.NODE_ENV, "apiCall 58");
    const url = ${process.env.NODE_ENV === "development"? process.env.PHONEPE_API_LINK : process.env.PHONEPE_PROD_API_LINK}/pg/v1/status/${merchantId}/${merchantTransactionId};
    const options = {
    method: "GET",
    headers: {
      accept: "application/json",
      "Content-Type": "application/json",
      "X-VERIFY": sha256,
      "X-MERCHANT_ID": merchantId,
    }
  };
  
  const response = await axios.get(url, {headers:options.headers});
  console.log(response, "apiCall 63");
  
  
  
  return response.data;
}catch(error){
  console.log(error, "apiCall 72")
}
};

function sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

module.exports = checkStatus;