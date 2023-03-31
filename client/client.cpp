#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <thread>

#include "communicator.h"

using namespace std;


void execute(int task, int channel, APICommunicator * communicator){
	if (task == 0){
		/* first task (healthcheck request) */
		cout << communicator->healthcheck_req(channel) << endl;
	}
	else if (task == 1){
		/* second task (query requests) */
		cout << communicator->query_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa") << endl;
		cout << communicator->query_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854") << endl;
		cout << communicator->query_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33") << endl;
		cout << communicator->query_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7") << endl;
		cout << communicator->query_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304") << endl;
		cout << communicator->query_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a") << endl;
		cout << communicator->query_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661") << endl;
		cout << communicator->query_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1") << endl;
	}
	else if (task == 2){
		/* third task (update requests) */
		cout << communicator->insert_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa", "0") << endl;
		cout << communicator->insert_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854", "0") << endl;
		cout << communicator->insert_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33", "0") << endl;
		cout << communicator->insert_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7", "0") << endl;
		cout << communicator->insert_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304", "0") << endl;
		cout << communicator->insert_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a", "0") << endl;
		cout << communicator->insert_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661", "0") << endl;
		cout << communicator->insert_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1", "0") << endl;
	}
	else if (task == 3){
		/* fourth task (query requests) */
		cout << communicator->query_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa") << endl;
		cout << communicator->query_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854") << endl;
		cout << communicator->query_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33") << endl;
		cout << communicator->query_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7") << endl;
		cout << communicator->query_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304") << endl;
		cout << communicator->query_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a") << endl;
		cout << communicator->query_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661") << endl;
		cout << communicator->query_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1") << endl;
	}
	else if (task == 4){
		/* fifth task (deletion requests) */
		cout << communicator->delete_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa") << endl;
		cout << communicator->delete_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854") << endl;
		cout << communicator->delete_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33") << endl;
		cout << communicator->delete_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7") << endl;
		cout << communicator->delete_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304") << endl;
		cout << communicator->delete_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a") << endl;
		cout << communicator->delete_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661") << endl;
		cout << communicator->delete_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1") << endl;
	}
	else if (task == 5){
		/* sixth task (query requests) */
		cout << communicator->query_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa") << endl;
		cout << communicator->query_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854") << endl;
		cout << communicator->query_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33") << endl;
		cout << communicator->query_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7") << endl;
		cout << communicator->query_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304") << endl;
		cout << communicator->query_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a") << endl;
		cout << communicator->query_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661") << endl;
		cout << communicator->query_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1") << endl;
	}
	else if (task == 6){
		/* seventh task (insertion requests) */
		cout << communicator->insert_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa", "1") << endl;
		cout << communicator->insert_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854", "1") << endl;
		cout << communicator->insert_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33", "1") << endl;
		cout << communicator->insert_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7", "1") << endl;
		cout << communicator->insert_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304", "1") << endl;
		cout << communicator->insert_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a", "1") << endl;
		cout << communicator->insert_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661", "1") << endl;
		cout << communicator->insert_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1", "1") << endl;
	}
	else if (task == 7){
		/* eighth task (query requests) */
		cout << communicator->query_req(channel, "account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa") << endl;
		cout << communicator->query_req(channel, "account", "b15171d6454e2ceec194ec78358877fc6a4b8c3bb11faa168957024c73d4b854") << endl;
		cout << communicator->query_req(channel, "account", "e151884d8f559f8420fdd64cdaeb38e5a57e727d9a56f3ad16046e802fd75a33") << endl;
		cout << communicator->query_req(channel, "account", "e2c15d57a410d4f01fb03c3433bbfc2bc6c8cc3a87d51ce514c0db919e58c0b7") << endl;
		cout << communicator->query_req(channel, "account", "cd923a6ba2c2b6ce9a468b599b3230a47a5fde96aef79c40e9817e22e3411304") << endl;
		cout << communicator->query_req(channel, "account", "78bd3f00d987cdcc2fd24f02bd3a608df94be5edcde68ae238482a77f4f1ea3a") << endl;
		cout << communicator->query_req(channel, "account", "1fe4a3ea77b283c594e4dfb2a9ab2349e2394e865f76b6e81ca0920529e08661") << endl;
		cout << communicator->query_req(channel, "account", "c06b77b9648909b41aa6005f48f61e1f3657754a4d27db092633459f2363b0e1") << endl;
	}
}


int main(int argc, char ** argv){
	const int N = 8;   // number of tasks
	const char * usageMsg = "Usage: ./client [s | p] nThreads";   // usage message in case of error

	string execType = "s";   // default execution type (serial)
	int nThreads = 2;   // default number of threads for parallel execution (2)
	if (argc > 1){
		execType = argv[1];   // argument for execution type
	}
	if (argc > 2){
		nThreads = atoi(argv[2]);   // argument for number of threads
	}
	nThreads = MIN(nThreads, 100);
	nThreads = MAX(1, nThreads);

	APICommunicator communicator(12121, "127.0.0.1");   // initialize communicator

	if (execType == "s"){
		/* serial execution */
		communicator.open_comm(1);   // open communication channel
		cout << communicator.initialize_req(0, "*") << endl;   // initialize database

		for (int i = 0; i < N; i++){
			execute(i, 0, &communicator);   // execute task
		}

		cout << communicator.reset_req(0) << endl;   // reset database
	}
	else if (execType == "p"){
		/* parallel execution */
		communicator.open_comm(nThreads);   // open communication channels
		cout << communicator.initialize_req(0, "*") << endl;   // initialize database

		thread T[nThreads];   // threads
		int done = 0;
		while (done < N){
			for (int i = 0; i < nThreads; i++){
				T[i] = thread(execute, done + i, i, &communicator);   // fork (execute task on thread)
			}
			for (int i = 0; i < nThreads; i++){
				T[i].join();   // join
			}
			done += nThreads;   // update counter of done tasks
		}

		cout << communicator.reset_req(0) << endl;   // reset database
	}
	else{
		/* invalid execution type */
		cout << "Error: Execution can be serial or parallel" << endl;
		cout << usageMsg << endl;
	}

	return 0;
}
