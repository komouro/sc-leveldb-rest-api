const sendResponse = require('./responseController.js');


async function Insert(res, db, sublevels, entriesLst){
	try {
		var size = entriesLst.length;
		var keyValuePairs = new Array();
		for (var i = 0; i < size; i++){
			await sublevels[entriesLst[i].type].put(entriesLst[i].key, entriesLst[i].value);   // insert (or update) entry on a sublevel
		}
		sendResponse(res, "OK", []);   // send response for successful operation
	} catch(err) {
		sendResponse(res, err.code, []);   // send error
	}
}


module.exports = Insert
