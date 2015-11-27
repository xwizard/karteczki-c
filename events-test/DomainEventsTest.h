#ifndef EVENTS_TEST_DOMAINEVENTSTEST_H_
#define EVENTS_TEST_DOMAINEVENTSTEST_H_

#include <memory>
#include <gtest/gtest.h>
#include "StubEventHandler.h"

class DomainEventsTest: public ::testing::Test {
public:
  DomainEventsTest();
  ~DomainEventsTest();
protected:
  shared_ptr<StubEventHandler<string>> stringHandler;
  shared_ptr<StubEventHandler<int>> intEventHandler;
  virtual void SetUp();
  virtual void TearDown();
};

#endif /* EVENTS_TEST_DOMAINEVENTSTEST_H_ */
