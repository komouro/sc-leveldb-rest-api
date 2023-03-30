const sendResponse = require('./responseController.js');


function HealthCheck(res, db){
	try {
		sendResponse(res, "OK", [{"Server Status": "healthy", "Database Status": db.status}]);   // return healthy response
	} catch(err) {
		sendResponse(res, err.code, []);   // return error
	}
}


module.exports = HealthCheck
