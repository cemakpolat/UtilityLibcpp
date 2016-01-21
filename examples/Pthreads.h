/*
 * Pthreads.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef PTHREADS_H_
#define PTHREADS_H_
#include <string>
#include <vector>
class Pthreads {
public:
	pthread_mutex_t mutex_window;							/**< Pthread Mutex for window synchronization */
	static std::vector<double> NumberWindow;				/**< Number Window */

	Pthreads();
	virtual ~Pthreads();
	/**
	 * Thread
	 */
	static void* runThread(void*);
	/**
	 *
	 */
	static void* runThreadWithoutObject(void*);
	void howtoPthreadMutex();
};

#endif /* PTHREADS_H_ */
