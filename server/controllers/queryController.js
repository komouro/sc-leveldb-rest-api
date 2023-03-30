const sendResponse = require('./responseController.js');


async function Query(res, db, sublevels, entriesLst){
	try {
		var size = entriesLst.length;
		var keyValuePairs = new Array();
		for (var i = 0; i < size; i++){
			var tmp = await sublevels[entriesLst[i].type].get(entriesLst[i].key);   // retrieve entry from sublevel
			keyValuePairs.push({type: entriesLst[i].type, key: entriesLst[i].key, value: tmp});
		}
		sendResponse(res, "OK", keyValuePairs);   // return response for successful operation
	} catch(err) {
		sendResponse(res, err.code, []);   // return error
	}
}


module.exports = Query
