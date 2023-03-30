/////////////////////////////////////////////////////////////////////////////
// NAME:               communicator.h
//
// PURPOSE:            Definition of the class APICommunicator. This class 
//                     is responsible for the connection with the server, 
//                     the submission of requests to the server and the 
//                     the retrieval of responses from the server.
//
// METHODS:            delete_req()
//                     healthcheck_req()
//                     initialize_req()
//                     insert_req()
//                     queryAll_req()
//                     query_req()
//                     reset_req()
//                     open()
//                     send_request()
//                     close()
/////////////////////////////////////////////////////////////////////////////



#pragma once

#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define MAX( a, b ) ( ( a > b) ? a : b )
#define MIN( a, b ) ( ( a < b) ? a : b )



class APICommunicator{
public:
	APICommunicator(int p, std::string addr){
		port = p;   // initialize port
		ipv4 = addr;   // initialize IPv4 address
	}


	std::string delete_req(std::string type, std::string key){
		return send_request("PUT /sc-leveldb/api/delete?type=" + type + "&key=" + key, 0);   // send request for deletion
	}


	std::string healthcheck_req(){
		return send_request("GET /sc-leveldb/api/healthcheck", 0);   // send request for healthcheck
	}


	std::string initialize_req(std::string type){
		return send_request("POST /sc-leveldb/api/initialize/" + type, 0);   // send request for initialization
	}


	std::string insert_req(std::string type, std::string key, std::string value){
		return send_request("PUT /sc-leveldb/api/insert?type=" + type + "&key=" + key + "&value=" + value, 0);   // send request for insertion
	}


	std::string queryAll_req(std::string type){
		return send_request("GET /sc-leveldb/api/queryAll/" + type, 0);   // send request for all-entries query
	}


	std::string query_req(std::string type, std::string key){
		return send_request("GET /sc-leveldb/api/query?type=" + type + "&key=" + key, 0);   // send request for query
	}


	std::string reset_req(){
		return send_request("POST /sc-leveldb/api/reset", 0);   // send request for resetting
	}


	void open_comm(int totalCommChannels){
		nChannels = MIN(totalCommChannels, 100);
		nChannels = MAX(nChannels, 1);
		for (int i = 0; i < nChannels; i++){
			/* get file descriptor to access new socket */
			if ((sockfd[i] = socket(AF_INET, SOCK_STREAM, 0)) < 0){
				printf("--------------------- Socket Error ---------------------\n");
				exit(0);
			}

			struct sockaddr_in servaddr;
			bzero(&servaddr, sizeof(servaddr));
			servaddr.sin_family = AF_INET;
			servaddr.sin_port = htons(port);

			/* convert string for IPv4 address into binary format */
			if (inet_pton(AF_INET, ipv4.c_str(), &servaddr.sin_addr) <= 0){
				printf("--------------------- Inet_pton Error ---------------------\n");
				exit(0);
			}

			/* connect */
			if (connect(sockfd[i], (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
				printf("--------------------- Connection Error ---------------------\n");
				exit(0);
			}
		}
	}


	std::string send_request(std::string httpRequest, int channel){
		int ret;
		char reqBuffer[reqBufSize];
		char resBuffer[resBufSize] = { 0 };
		std::string host, responseStr;

		host = ipv4 + ":" + std::to_string(port);   // get host

		memset(reqBuffer, 0, reqBufSize);
		strcat(reqBuffer, httpRequest.c_str());
		strcat(reqBuffer, " HTTP/1.1\r\n");
		strcat(reqBuffer, "Host: ");
		strcat(reqBuffer, host.c_str());
		strcat(reqBuffer, "\r\n");
		strcat(reqBuffer, "\r\n");

		ret = send(sockfd[channel], reqBuffer, strlen(reqBuffer), MSG_NOSIGNAL);   // send data
		if(ret > 0){
			ret = read(sockfd[channel], resBuffer, resBufSize);   // read data
			if (ret > 0){
				responseStr = resBuffer;
			}
			else{
				printf("--------------------- Communication Error ---------------------\n");
				close (sockfd[channel]);
				exit(0);
			}
		}
		else{
			printf("--------------------- Communication Error ---------------------\n");
			close (sockfd[channel]);
			exit(0);
		}

		return responseStr;
	}


	void close_comm(){
		for (int i = 0; i < nChannels; i++){
			close(sockfd[i]);   // close socket
		}
	}


private:
	int port;   // port
	std::string ipv4;   // IPv4 address
	int sockfd[100];   // sockets
	int nChannels;   // number of communication channels (open sockets)

	const int minBufSize = 1024;   // constant buffer size
	const int reqBufSize = minBufSize * 4;   // buffer size for requests
	const int resBufSize = minBufSize * 25;   // buffer size for responses
};
