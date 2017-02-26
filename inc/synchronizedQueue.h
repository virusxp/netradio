/*
 * synchronizedQueue.h
 *
 *  Created on: 26.02.2017
 *      Author: virusxp
 */

#ifndef INC_SYNCHRONIZEDQUEUE_H_
#define INC_SYNCHRONIZEDQUEUE_H_

#include <queue>
#include <mutex>

class SynchronizeQueue : public std::queue
{
	public:
		std::mutex quMtx;

	private:
		SynchronizeQueue();
		virtual ~SynchronizeQueue();


};

#endif /* INC_SYNCHRONIZEDQUEUE_H_ */
