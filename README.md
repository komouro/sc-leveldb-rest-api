# sc-leveldb-rest-api

## Description
We have implemented a RESTful API that manages a key-value storage based on LevelDB. This code was inspired by a premature version of the concurrent execution engine presented in the diploma thesis on https://dspace.lib.ntua.gr/xmlui/handle/123456789/56334. While this code was not used for the experimental part of the concurrent engine, it is included in this repository for educational purposes with a focus on the REST API architecture, concurrency and sockets.

## Components
**Database**: The storage layer includes a key-value database. More specifically, we employ the Universal abstract-level database for Node.js and browsers. More details about the database can be found on https://github.com/Level/level.<br />
**Dataset**: The database can be initialized with entries that can be found in text files in the ./server directory. Each file contains key-value pairs that correspond to account balances, voting weights, proposal votes or product prices. The dataset represents part of the state of a blockchain node that executes smart contract transactions.<br />
**Server**: The management of the database is done by a central server, implemented using Node JS and Express in the ./server directory. The server accepts multiple requests from multiple clients, performs read and write operations on the database and send a response back to each client, based on the final status of the requested set of operations.<br />
**Client**: A basic client is implemented in C++ for the submission of requests in order to test the fundamental functionality of the server. The client can be executed using a serial or a parallel version (fork-join). The communication between the threads of the client and the server is achieved by sockets.

## Installation - Execution
The development of the applcation was done using the Node Package Manager (npm). In particular, we used npm 7.18.1 and g++ 7.5.0 on a Linux system. Inside the ./server directory, we open a terminal and run the following command:
```
npm install
```
The server is activated on port 12121 by running the following command:
```
npm run server
```
The testing script of the client can be built by running the following command inside the ./client directory:
```
make
```
For the serial execution of the script, we can run:
```
make run_serial
```
and for the parallel:
```
make run_parallel
```
