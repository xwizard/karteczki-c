/*
 * EventHandler.h
 *
 *  Created on: 24 lip 2015
 *      Author: Mateusz
 */

#ifndef SRC_EVENTHANDLER_H_
#define SRC_EVENTHANDLER_H_

#include <vector>

namespace events {

using namespace std;

template <class Event>
class EventHandler {
public:
	virtual ~EventHandler();
	virtual void handle(Event);
};

} /* namespace events */

#endif /* SRC_EVENTHANDLER_H_ */
