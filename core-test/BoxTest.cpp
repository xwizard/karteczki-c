#include <stdexcept>
#include "BoxTest.h"

using namespace id;
using namespace std;

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

TEST_F(BoxTest, BoxShouldThrowInvalidExceptionWhenAddingNullCardId) {
  ASSERT_THROW(box->addCard(shared_ptr<Id>(NULL)), invalid_argument);
}

TEST_F(BoxTest, BoxShouldntAllowContainsCardForNotExistingCompartment) {
  ASSERT_THROW(box->containsCard(10000000, Id::random()), invalid_argument);
}

TEST_F(BoxTest, BoxShouldntAllowAddingCardToNotExistingCompartment) {
  ASSERT_THROW(box->addCard(10000, Id::random()), invalid_argument);
}

TEST_F(BoxTest, BoxShouldHoldCardsProperly) {
  box->addCard(0, Id::fromString("0"));
  box->addCard(1, Id::fromString("1"));

  ASSERT_TRUE(box->containsCard(0, Id::fromString("0")));
  ASSERT_TRUE(box->containsCard(1, Id::fromString("1")));
}

TEST_F(BoxTest, BoxShouldDegradeCardToFristCompartment) {
  box->addCard(1, Id::fromString("0"));

  box->degradeCard(Id::fromString("0"));

  ASSERT_TRUE(box->containsCard(0, Id::fromString("0")));
}

} /* namespace core */
