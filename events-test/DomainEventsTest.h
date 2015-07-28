#ifndef EVENTS_TEST_DOMAINEVENTSTEST_H_
#define EVENTS_TEST_DOMAINEVENTSTEST_H_

#include <gtest/gtest.h>

#include "StubEventHandler.h"

class DomainEventsTest: public ::testing::Test {
protected:
  virtual void SetUp();
};

#endif /* EVENTS_TEST_DOMAINEVENTSTEST_H_ */
