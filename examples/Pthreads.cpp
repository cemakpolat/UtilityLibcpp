/*
 * Pthreads.cpp
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#include "Pthreads.h"
#include "pthread.h"
#include <iostream>
Pthreads::Pthreads() {
	// TODO Auto-generated constructor stub

}

Pthreads::~Pthreads() {
	// TODO Auto-generated destructor stub
}

void* Pthreads::runThreadWithoutObject(void* ) {

	while (true) {
		try {
			std::cout<<"Thread without Object is called"<<std::endl;
		}  catch (std::exception& e) {

		}
	}
	pthread_exit(NULL);
}
void* Pthreads::runThread(void* obj){
	Pthreads *sing=(Pthreads *)obj;
	while(true){
		//do something
		std::cout<<"Thread with Object is called"<<std::endl;
	}
}
//STATIC ASSIGNEMENTS
std::vector<double> Pthreads::NumberWindow;
void Pthreads::howtoPthreadMutex(){

	pthread_mutex_lock(&this->mutex_window);//mutex list
	this->NumberWindow.push_back( 0);
	pthread_mutex_unlock(&this->mutex_window);
}
