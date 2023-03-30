const healthcheckController = require('./../controllers/healthcheckController.js');


module.exports = function(app, db){
	app.get('/sc-leveldb/api/healthcheck', (req, res) => {
		healthcheckController(res, db);   // controller for healthcheck
	});
};
