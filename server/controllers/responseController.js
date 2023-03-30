
function ResponseHandler(res, code, data){
	if (code == "OK"){
		/* successful operation */
		var statusCode = 200;
		var description = "Operation was successfully completed.";
		res.status(200);
	}
	else if (code == "LEVEL_NOT_FOUND"){
		/* key not found */
		var statusCode = 404;
		var description = "Key was not found.";
		res.status(404);
	}
	else if (code == "LEVEL_DATABASE_NOT_OPEN"){
		/* closed or closing database */
		var statusCode = 503;
		var description = "Database is closing or closed.";
		res.status(503);
	}
	else if (code == "LEVEL_DATABASE_NOT_CLOSED"){
		/* failure to close database */
		var statusCode = 500;
		var description = "Database failed to close (unknown cause of failure).";
		res.status(500);
	}
	else if (code == "LEVEL_ITERATOR_NOT_OPEN"){
		/* closed or closing iterator */
		var statusCode = 503;
		var description = "Iterator is closing or closed.";
		res.status(503);
	}
	else if (code == "LEVEL_ITERATOR_BUSY"){
		/* busy iterator */
		var statusCode = 503;
		var description = "Iterator is busy. An iterator method was called while a previous call was still in progress.";
		res.status(503);
	}
	else if (code == "LEVEL_BATCH_NOT_OPEN"){
		/* closed or closing batch */
		var statusCode = 503;
		var description = "Chained batch is closing or closed.";
		res.status(503);
	}
	else if (code == "LEVEL_ENCODING_NOT_FOUND" || code == "LEVEL_ENCODING_NOT_SUPPORTED"){
		/* encoding not supported */
		var statusCode = 501;
		var description = "Encoding for key or value does not exist or is not supported by the database.";
		res.status(501);
	}
	else if (code == "LEVEL_DECODE_ERROR"){
		/* failure to decode key or value */
		var statusCode = 500;
		var description = "Decoding of keys or values failed (unknown cause of failure).";
		res.status(500);
	}
	else if (code == "LEVEL_INVALID_KEY"){
		/* invalid key */
		var statusCode = 404;
		var description = "Invalid key was found";
		res.status(404);
	}
	else if (code == "LEVEL_INVALID_VALUE"){
		/* invalid value */
		var statusCode = 404;
		var description = "Invalid value was found";
		res.status(404);
	}
	else if (code == "LEVEL_CORRUPTION"){
		/* corrupted data */
		var statusCode = 500;
		var description = "Data could not be read (from an underlying store) due to a corruption.";
		res.status(500);
	}
	else if (code == "LEVEL_IO_ERROR"){
		/* I/O error */
		var statusCode = 500;
		var description = "Data could not be read (from an underlying store) due to an I/O error.";
		res.status(500);
	}
	else if (code == "LEVEL_INVALID_PREFIX"){
		/* invalid sublevel */
		var statusCode = 400;
		var description = "Sublevel prefix contains characters outside of the supported byte range.";
		res.status(400);
	}
	else if (code == "LEVEL_NOT_SUPPORTED"){
		/* feature not supported */
		var statusCode = 501;
		var description = "A module needs a certain feature which is not available.";
		res.status(501);
	}
	else if (code == "LEVEL_LEGACY"){
		/* removed feature */
		var statusCode = 501;
		var description = "A method, option or other property was used that has been removed from the API.";
		res.status(501);
	}
	else if (code == "LEVEL_LOCKED"){
		/* locked database */
		var statusCode = 400;
		var description = "An attempt was made to open a database that is already open in another process or instance.";
		res.status(400);
	}
	else if (code == "LEVEL_READONLY"){
		/* invalid write on read-only data */
		var statusCode = 400;
		var description = "An attempt was made to write data to a read-only database.";
		res.status(400);
	}
	else if (code == "LEVEL_CONNECTION_LOST"){
		/* connection lost */
		var statusCode = 503;
		var description = "Database relies on a connection to a remote party and that connection has been lost.";
		res.status(503);
	}
	else if (code == "LEVEL_REMOTE_ERROR"){
		/* remote error */
		var statusCode = 500;
		var description = "A remote party encountered an unexpected condition (unknown cause of failure).";
		res.status(500);
	}
	else{
		/* unknown error */
		var statusCode = 500;
		var description = "System failed (unknown cause of failure).";
		res.status(500);
	}
	var responseBody = [{"Status-Code": statusCode, "DB-Code": code, "Description": description, "Data": data}];
	return res.send(responseBody);
}


module.exports = ResponseHandler
