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

} /* namespace core */
