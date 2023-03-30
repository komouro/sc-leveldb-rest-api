const express = require('express');
const { Level } = require('level');

const app = express();
app.use(express.json());
const db = new Level('./LevelDB');


const accountDB = db.sublevel('account');   // sublevel for accounts
const productDB = db.sublevel('product');   // sublevel for products
const proposalDB = db.sublevel('proposal');   // sublevel for proposals
const voterDB = db.sublevel('voter');   // sublevel for voters
const sublevels = {account: accountDB, product: productDB, proposal: proposalDB, voter: voterDB};   // level structure


const port = 12121;   // port

require('./routes')(app, db, sublevels);   // require all routers

app.listen(port, () => {
	console.log("Listening on port " + port);   // listening on our port for requests
});
