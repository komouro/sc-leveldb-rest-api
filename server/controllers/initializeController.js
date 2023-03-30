const fs = require('fs');
const util = require('util');

const sendResponse = require('./responseController.js');


const accountsFileName = "./dataset/accounts.txt";   // name of file for accounts in dataset
const productsFileName = "./dataset/products.txt";   // name of file for products in dataset
const proposalsFileName = "./dataset/proposals.txt";   // name of file for proposals in dataset
const votersFileName = "./dataset/voters.txt";   // name of file for voters in dataset

var rawData = new Array();


async function InitializeDatabase(res, db, sublevels,  type){
	try {
		/* prepare data */
		var accountEntries = rawData[0];
		var accountSize = rawData[0].length;
		var accountInfo = {entries: accountEntries, size: accountSize}
		var productEntries = rawData[1];
		var productSize = rawData[1].length;
		var productInfo = {entries: productEntries, size: productSize}
		var proposalEntries = rawData[2];
		var proposalSize = rawData[2].length;
		var proposalInfo = {entries: proposalEntries, size: proposalSize}
		var voterEntries = rawData[3];
		var voterSize = rawData[3].length;
		var voterInfo = {entries: voterEntries, size: voterSize}
		var dataInfo = {account: accountInfo, product: productInfo, proposal: proposalInfo, voter: voterInfo};

		if (type == "*"){
			/* initialize all sublevels of storage */
			for (var i = 0; i < accountSize; i++){
				await sublevels.account.put(accountEntries[i].key, accountEntries[i].value);   // insert account
			}
			for (var i = 0; i < productSize; i++){
				await sublevels.product.put(productEntries[i].key, productEntries[i].value);   // insert product
			}
			for (var i = 0; i < proposalSize; i++){
				await sublevels.proposal.put(proposalEntries[i].key, proposalEntries[i].value);   // insert proposal
			}
			for (var i = 0; i < voterSize; i++){
				await sublevels.voter.put(voterEntries[i].key, voterEntries[i].value);   // insert voter
			}

			sendResponse(res, "OK", []);   // send response for successful operation
		}
		else if (!(type in sublevels)){
			/* invalid sublevel */
			sendResponse(res, "LEVEL_INVALID_PREFIX", []);   // send error (invalid sublevel)
		}
		else{
			/* initialize a specific sublevel */
			for (var i = 0; i < dataInfo[type].size; i++){
				await sublevels[type].put(dataInfo[type].entries[i].key, dataInfo[type].entries[i].value);
			}

			sendResponse(res, "OK", []);   // send response for successful operation
		}
	} catch(err) {
		sendResponse(res, err.code, []);   // send error
	}
}


function ReadDataset(fn, res, db, sublevels, type, flag){
	const readFile = util.promisify(fs.readFile);

	function GetStuff() {
		return readFile(fn, 'utf8');   // read raw data from file
	}

	GetStuff().then(data => {
		let j = JSON.parse(data);   // parse raw data
		rawData.push(j);   // push raw data into array

		if (flag == 0){
			ReadDataset(productsFileName, res, db, sublevels, type, 1);   // read products from dataset
		}
		else if (flag == 1){
			ReadDataset(proposalsFileName, res, db, sublevels, type, 2);   // read proposals from dataset
		}
		else if (flag == 2){
			ReadDataset(votersFileName, res, db, sublevels, type, 3);   // read voters from dataset
		}
		else{
			InitializeDatabase(res, db, sublevels, type);   // initialize key-value storage
		}
	})
}


function Initialize(res, db, sublevels, type){
	ReadDataset(accountsFileName, res, db, sublevels, type, 0);   // read accounts from dataset
}


module.exports = Initialize
