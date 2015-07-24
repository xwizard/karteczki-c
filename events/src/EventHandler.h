/*
 * EventHandler.h
 *
 *  Created on: 24 lip 2015
 *      Author: Mateusz
 */

#ifndef SRC_EVENTHANDLER_H_
#define SRC_EVENTHANDLER_H_

namespace events {

template <class event>
class EventHandler {
public:
	virtual ~EventHandler();
	EventHandler();
};

} /* namespace events */

#endif /* SRC_EVENTHANDLER_H_ */
