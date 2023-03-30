const queryAllController = require('./../controllers/queryAllController.js');


module.exports = function(app, db, sublevels){
	app.get('/sc-leveldb/api/queryAll/:type', (req, res) => {
		queryAllController(res, db, sublevels, req.params.type);   // controller for retrieval of all entries on a sublevel
	});
};
