#ifndef EVENTS_TEST_STUBEVENTHANDLER_H_
#define EVENTS_TEST_STUBEVENTHANDLER_H_

#include <vector>
#include <events/EventHandler.h>

using namespace std;

template <class Event>
class StubEventHandler: public events::EventHandler<Event> {
public:
	virtual ~StubEventHandler();
	virtual void handle(Event event);
	int countHandledEvents();
private:
	vector<Event> events;
};

template<class Event>
StubEventHandler<Event>::~StubEventHandler() {}

template<class Event>
void StubEventHandler<Event>::handle(Event event) {
	events.push_back(event);
}

template<class Event>
int StubEventHandler<Event>::countHandledEvents() {
	return events.size();
}

#endif /* EVENTS_TEST_STUBEVENTHANDLER_H_ */
