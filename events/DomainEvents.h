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
	static void unregisterHandlers();
private:
	static vector<EventHandler<Event>> eventHandlers;
};

template<class Event>
void DomainEvents<Event>::raise(Event event) {
	for (auto eventHandler : eventHandlers) {
		eventHandler.handle(event);
	}
}

template<class Event>
void DomainEvents<Event>::registerHandler(EventHandler<Event> eventHandler) {
	eventHandler.push_back(eventHandler);
}

template<class Event>
void DomainEvents<Event>::unregisterHandlers() {
	eventHandlers.clear();
}

} /* namespace events */

#endif /* DOMAINEVENTS_H_ */
