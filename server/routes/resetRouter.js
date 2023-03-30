const resetController = require('./../controllers/resetController.js');


module.exports = function(app, db){
	app.post('/sc-leveldb/api/reset', (req, res) => {
		resetController(res, db);   // controller for resetting (clearing database)
	});
};
