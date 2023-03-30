const sendResponse = require('./responseController.js');


async function QueryAll(res, db, sublevels, type){
	try {
		if (type == "*"){
			/* return all entries from every sublevel */
			var keyValuePairs = new Array();
			for await (const [key, value] of sublevels.account.iterator()){
				keyValuePairs.push({type: "account", key: key, value: value});   // retrieve account
			}
			for await (const [key, value] of sublevels.product.iterator()){
				keyValuePairs.push({type: "product", key: key, value: value});   // retrieve product
			}
			for await (const [key, value] of sublevels.proposal.iterator()){
				keyValuePairs.push({type: "proposal", key: key, value: value});   // retrieve proposal
			}
			for await (const [key, value] of sublevels.voter.iterator()){
				keyValuePairs.push({type: "voter", key: key, value: value});   // retrieve voter
			}
			sendResponse(res, "OK", keyValuePairs);   // send response for successful operation
		}
		else if (!(type in sublevels)){
			/* invalid sublevel */
			sendResponse(res, "LEVEL_INVALID_PREFIX", []);   // send error (invalid sublevel)
		}
		else {
			/* return all entries from a specific sublevel */
			var keyValuePairs = new Array();
			for await (const [key, value] of sublevels[type].iterator()){
				keyValuePairs.push({type: type, key: key, value: value});
			}
			sendResponse(res, "OK", keyValuePairs);   // send response for successful operation
		}
	} catch(err) {
		sendResponse(res, err.code, []);   // send error
	}
}


module.exports = QueryAll
