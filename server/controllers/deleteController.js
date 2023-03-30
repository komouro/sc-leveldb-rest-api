const sendResponse = require('./responseController.js');


async function Delete(res, db, sublevels, entriesLst){
	try {
		var size = entriesLst.length;
		for (var i = 0; i < size; i++){
			await sublevels[entriesLst[i].type].del(entriesLst[i].key);   // delete entry on a sublevel
		}
		sendResponse(res, "OK", []);   // send response for successful operation
	} catch(err) {
		sendResponse(res, err.code, []);   // return error
	}
}


module.exports = Delete
