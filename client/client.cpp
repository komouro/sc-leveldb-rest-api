#include <iostream>
#include <chrono>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <thread>
#include <queue>
#include <stdio.h>
#include <unistd.h>

#include "communicator.h"

using namespace std;


int main(){
	APICommunicator communicator(12121, "127.0.0.1");

	communicator.open_comm(1);

	cout << communicator.initialize_req("*") << endl;
	cout << communicator.query_req("account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa");
	cout << communicator.reset_req() << endl;
	cout << communicator.query_req("account", "faea467513aa99cbb81325082290d11aeb73a38a4381e66b4d3ee7c527f7b4aa");

	communicator.close_comm();

	return 0;
}
