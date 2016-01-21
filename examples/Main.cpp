/*
 * Main.cpp
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */


#include <string>
#include <iostream>
#include "Pthreads.h"
#include "Singleton.h"
#include "pthread.h"
#include <stdio.h>

void howtoCallSingleton(){
	Singleton *sing=Singleton::Instance();
	//sing->...
}
void howtoUsePthreadMutex(){
	Pthreads *pi=new Pthreads();
	pi->howtoPthreadMutex();
}
void howtoUserPthreadWithObject(){

	//Run thread with object
	Pthreads *pi=new Pthreads();										 	//Instantiate Object
	pthread_t pthread;														//Create PTHREAD Object
	int rc;
	if ((rc = pthread_create(&pthread, NULL, &Pthreads::runThread, pi))) { 	//Run thread
			printf("APDME : Experimenter thread creation failed: %d\n", rc);
	}
	pthread_join(pthread, NULL);

}
void howtoUserPthreadWithoutObject(){
	//Run thread with object
	Pthreads *pi=new Pthreads();											 //Instantiate Object
	pthread_t pthread;														//Create PTHREAD Object
	int rc;
	if ((rc = pthread_create(&pthread, NULL, &Pthreads::runThreadWithoutObject,
			NULL))) { //Run thread
		printf("APDME : Experimenter thread creation failed: %d\n", rc);
	}
	pthread_join(pthread, NULL);

}
int main(int argc, char *argv[]) {

std::cout<<"Hello Universe"<<std::endl;

}

