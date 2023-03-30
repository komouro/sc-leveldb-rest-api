const insertController = require('./../controllers/insertController.js');


module.exports = function(app, db, sublevels){
	app.put('/sc-leveldb/api/insert', (req, res) => {
		insertController(res, db, sublevels, [{type: req.query.type, key: req.query.key, value: req.query.value}]);   // controller for insertion
	});
};
