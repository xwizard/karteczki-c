#include <string>
#include <events/DomainEvents.h>
#include "DomainEventsTest.h"

using namespace std;
using namespace events;

void DomainEventsTest::SetUp() {
	StubEventHandler<string> stringHandler;
	StubEventHandler<int> eventHandler;

	DomainEvents<StubEventHandler<string>>::registerHandler(stringHandler);
}
