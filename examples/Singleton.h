/*
 * Singleton.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton {
	private:
	static Singleton* singleton_Instance;
public:
	Singleton();
	virtual ~Singleton();

	/**
	* Create only one instance of this class.
	* \return the same reference of the created object in case it is invoked by other objects.
	*/
	static Singleton* Instance();

	void helloUniverse();


};

#endif /* SINGLETON_H_ */
