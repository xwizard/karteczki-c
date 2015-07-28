#ifndef DOMAINEVENTS_H_
#define DOMAINEVENTS_H_

#include <vector>
#include "EventHandler.h"

using namespace std;

namespace events {

template<class Event>
class DomainEvents {
public:
	static void raise(Event event);
	static void registerHandler(EventHandler<Event> eventHandler);
private:
	static vector<EventHandler<Event>> events;
};

template<class Event>
void DomainEvents<Event>::raise(Event event) {
}

template<class Event>
void DomainEvents<Event>::registerHandler(EventHandler<Event> eventHandler) {
	events.push_back(eventHandler);
}

} /* namespace events */

#endif /* DOMAINEVENTS_H_ */
