const deleteController = require('./../controllers/deleteController.js');


module.exports = function(app, db, sublevels){
	app.put('/sc-leveldb/api/delete', (req, res) => {
		deleteController(res, db, sublevels, [{type: req.query.type, key: req.query.key}]);   // controller for deletion
	});
};
