#ifndef BOXTEST_H_
#define BOXTEST_H_

#include <gtest/gtest.h>
#include <core/Box.h>

namespace core {

class BoxTest : public ::testing::Test {
public:
	BoxTest();
	virtual ~BoxTest();
  virtual void TearDown();
  virtual void SetUp();
protected:
	Box* box;
};

} /* namespace core */

#endif /* BOXTEST_H_ */
