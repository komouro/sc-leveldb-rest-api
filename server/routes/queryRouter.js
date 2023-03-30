const queryController = require('./../controllers/queryController.js');


module.exports = function(app, db, sublevels){
	app.get('/sc-leveldb/api/query', (req, res) => {
		queryController(res, db, sublevels, [{type: req.query.type, key: req.query.key}]);   // controller for retrieval of one entry on a sublevel
	});
};
