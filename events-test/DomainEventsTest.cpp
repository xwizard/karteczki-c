#include <string>
#include <memory>
#include <events/DomainEvents.h>
#include "DomainEventsTest.h"
#include "StubEventHandler.h"

using namespace std;
using namespace events;

DomainEventsTest::DomainEventsTest() {}

DomainEventsTest::~DomainEventsTest() {}

void DomainEventsTest::SetUp() {
	stringHandler = make_shared<StubEventHandler<string>>();
	intEventHandler = make_shared<StubEventHandler<int>>();

	DomainEvents<string>::registerHandler(stringHandler);
	DomainEvents<int>::registerHandler(intEventHandler);
}

TEST_F(DomainEventsTest, DomainEventsHandleStringEvent) {
	DomainEvents<string>::raise("dupa");
	EXPECT_EQ(1, stringHandler->countHandledEvents());
	EXPECT_EQ(0, intEventHandler->countHandledEvents());
}
