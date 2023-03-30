const deleteRoute = require('./deleteRouter.js');
const healthcheckRoute = require('./healthcheckRouter.js');
const initializeRoute = require('./initializeRouter.js');
const insertRoute = require('./insertRouter.js');
const queryAllRoute = require('./queryAllRouter.js');
const queryRoute = require('./queryRouter.js');
const resetRoute = require('./resetRouter.js');


module.exports = function(app, db, sublevels){
	deleteRoute(app, db, sublevels);   // router for deletion
	healthcheckRoute(app, db);   // router for healthcheck
	initializeRoute(app, db, sublevels);   // router for initialization
	insertRoute(app, db, sublevels);   // router for insertion
	queryAllRoute(app, db, sublevels);   // router for retrieval of all entries on a sublevel
	queryRoute(app, db, sublevels);   // router for retrieval of one entry on a sublevel
	resetRoute(app, db);   // router for resetting (clearing database)
}
