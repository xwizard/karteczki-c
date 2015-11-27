#include <string>
#include <memory>
#include <events/DomainEvents.h>
#include "DomainEventsTest.h"
#include "StubEventHandler.h"

using namespace std;
using namespace events;

DomainEventsTest::DomainEventsTest() {
}

DomainEventsTest::~DomainEventsTest() {
}

void DomainEventsTest::SetUp() {
  stringHandler = make_shared<StubEventHandler<string>>();
  intEventHandler = make_shared<StubEventHandler<int>>();

  DomainEvents<string>::registerHandler(stringHandler);
  DomainEvents<int>::registerHandler(intEventHandler);
}

void DomainEventsTest::TearDown() {
  stringHandler->clearHandledEvents();
  intEventHandler->clearHandledEvents();
}

TEST_F(DomainEventsTest, DomainEventsHandleEvents) {
  DomainEvents<string>::raise("event");
  EXPECT_EQ(1, stringHandler->countHandledEvents());
  EXPECT_EQ(0, intEventHandler->countHandledEvents());

  DomainEvents<string>::raise("other event");
  EXPECT_EQ(2, stringHandler->countHandledEvents());
  EXPECT_EQ(0, intEventHandler->countHandledEvents());
}

TEST_F(DomainEventsTest, DomainEventsTwoHandlersSameEvent) {
  shared_ptr<StubEventHandler<string>> handler1 = make_shared<
      StubEventHandler<string>>();
  shared_ptr<StubEventHandler<string>> handler2 = make_shared<
      StubEventHandler<string>>();
  DomainEvents<string>::registerHandler(handler1);
  DomainEvents<string>::registerHandler(handler2);

  DomainEvents<string>::raise("event");

  EXPECT_EQ(1, handler1->countHandledEvents());
  EXPECT_EQ(1, handler2->countHandledEvents());
}
