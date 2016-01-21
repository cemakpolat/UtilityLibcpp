/*
 * Singleton.cpp
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#include "Singleton.h"
#include <iostream> //Required for NULL


/**
 * singleton Pattern
 */
Singleton* Singleton::singleton_Instance = NULL;
Singleton* Singleton::Instance() {
	if (!singleton_Instance) {
		singleton_Instance = new Singleton();
	}
	return singleton_Instance;
}

Singleton::Singleton() {
	// TODO Auto-generated constructor stub

}

Singleton::~Singleton() {
	// TODO Auto-generated destructor stub
}
void Singleton::helloUniverse(){
	std::cout<<"Hello Universe, Singleton is working"<<std::endl;
}
