#include "BoxTest.h"

using namespace id;

namespace core {

BoxTest::BoxTest() {
  // TODO Auto-generated constructor stub
}

BoxTest::~BoxTest() {
  // TODO Auto-generated destructor stub
}

void BoxTest::SetUp() {
  box = new Box();
}

void BoxTest::TearDown() {
  delete box;
}

TEST_F(BoxTest, BoxShouldHaveCardAferAddCard) {
  box->addCard(Id::fromString("1"));

  ASSERT_TRUE(box->containsCard(0, Id::fromString("1")));
  ASSERT_FALSE(box->containsCard(1, Id::fromString("1")));
}

} /* namespace core */
