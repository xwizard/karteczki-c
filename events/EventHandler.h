#ifndef SRC_EVENTHANDLER_H_
#define SRC_EVENTHANDLER_H_

namespace events {

using namespace std;

template <class Event>
class EventHandler {
public:
	virtual ~EventHandler();
	virtual void handle(Event event) = 0;
};

template <class Event>
EventHandler<Event>::~EventHandler() {}

} /* namespace events */

#endif /* SRC_EVENTHANDLER_H_ */
