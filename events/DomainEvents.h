#ifndef DOMAINEVENTS_H_
#define DOMAINEVENTS_H_

#include <vector>
#include <memory>
#include "EventHandler.h"

using namespace std;

namespace events {

template<class Event>
class DomainEvents {
public:
	static void raise(Event event);
	static void registerHandler(shared_ptr<EventHandler<Event>> eventHandler);
private:
	static vector<shared_ptr<EventHandler<Event>>> eventHandlers;
};

template<class Event>
vector<shared_ptr<EventHandler<Event>>> DomainEvents<Event>::eventHandlers;

template<class Event>
void DomainEvents<Event>::raise(Event event) {
	for (auto eventHandler : eventHandlers) {
		eventHandler->handle(event);
	}
}

template<class Event>
void DomainEvents<Event>::registerHandler(shared_ptr<EventHandler<Event>> eventHandler) {
	eventHandlers.push_back(eventHandler);
}

} /* namespace events */

#endif /* DOMAINEVENTS_H_ */
