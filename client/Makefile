client: client.cpp communicator.h
	g++ -o client client.cpp -Wall -Werror -O2 -lpthread


run_serial: client
	./client s


run_parallel: client
	./client p 2


clean: client
	rm client
