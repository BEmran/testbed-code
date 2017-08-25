/* 
 * File:   Navio_Threads.cpp
 * Author: Bara Emran
 * Created on August 25, 2017, 10:16 AM
 */

#include "Navio_Threads.hpp"

int main(int argc, char** argv) {
    // Welcome msg
    printf("Start Program\n"); 
    signal(SIGINT, ctrlCHandler);
    
    // Define main variables
    struct dataStruct data;

    // Start threads
    pthread_create(&_Thread_Con, NULL, conThread, (void *) &data);
    pthread_create(&_Thread_Sen, NULL, senThread, (void *) &data);
    pthread_create(&_Thread_Tcp, NULL, tcpThread, (void *) &data);

    // Main loop to read encoders value
    while (!_CloseRequested)
    {
            printf("main\n");
            sleep(1);
    }

    // Exit procedure
    pthread_cancel(_Thread_Con);
    pthread_cancel(_Thread_Sen);
    pthread_cancel(_Thread_Tcp);
    printf("Close program\n");        
    return 0;
}



// ********************************************************** //
// Detect ctrl+c
void ctrlCHandler(int signal)
{
	_CloseRequested = true;
	printf("Ctrl+c have been detected\n");
}

// ********************************************************** //
// Control thread
void *conThread(void *data)
{
	printf("Start control thread\n");

	struct dataStruct *my_data;
	my_data = (struct dataStruct *) data;

	// Main loop to read encoders value
	while (!_CloseRequested)
	{       
                printf("control thread\n");
		usleep(200000);
	}
	// Exit procedure
	printf("Exit control thread\n");
	pthread_exit(NULL);
}

// ********************************************************** //
// Sensor thread
void *senThread(void *data)
{
	printf("Start sensor thread\n");

	struct dataStruct *my_data;
	my_data = (struct dataStruct *) data;

	// Main loop to read encoders value
	while (!_CloseRequested)
	{       
                printf("sensor thread\n");
		usleep(500000);
	}
	// Exit procedure
	printf("Exit sensor thread\n");
	pthread_exit(NULL);
}

// ********************************************************** //
// TCP thread
void *tcpThread(void *data)
{
	printf("Start tcp thread\n");

	struct dataStruct *my_data;
	my_data = (struct dataStruct *) data;

	// Main loop to read encoders value
	while (!_CloseRequested)
	{       
                printf("tcp thread\n");
		usleep(50000);
	}
	// Exit procedure
	printf("Exit tcp thread\n");
	pthread_exit(NULL);
}