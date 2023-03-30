const sendResponse = require('./responseController.js');


async function Reset(res, db){
	try {
		await db.clear();   // clear database
		sendResponse(res, "OK", []);   // return response for successful operation
	} catch(err) {
		sendResponse(res, err.code, []);   // return error
	}
}


module.exports = Reset
