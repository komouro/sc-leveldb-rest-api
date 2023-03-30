const initializeController = require('./../controllers/initializeController.js');


module.exports = function(app, db, sublevels){
	app.post('/sc-leveldb/api/initialize/:type', (req, res) => {
		initializeController(res, db, sublevels, req.params.type);   // controller for initialization
	});
};
