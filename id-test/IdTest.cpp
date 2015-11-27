#include <id/Id.h>
#include "IdTest.h"

#include <vector>
#include <memory>

using namespace std;

namespace id {

IdTest::IdTest() {
}
IdTest::~IdTest() {
}

TEST_F(IdTest, FromStringSetsProperValue) {
  shared_ptr<Id> id = Id::fromString("test");
  EXPECT_EQ("test", id->value());
}

TEST_F(IdTest, RandomIdIsRandomEnough) {
  const int times = 5000;
  vector<shared_ptr<Id>> ids;

  for (int i = 0; i < times; i++) {
    ids.push_back(Id::random());
  }

  for (int i = 0; i < times; i++) {
    for (int j = 0; j < times; j++) {
      bool areEqual = *ids[i] == *ids[j];
      if (i == j) {
        ASSERT_TRUE(areEqual);
      } else {
        ASSERT_FALSE(areEqual);
      }
    }
  }
}

TEST_F(IdTest, OperatorEquals) {
  shared_ptr<Id> id1 = Id::fromString("1");
  shared_ptr<Id> id2 = Id::fromString("1");
  shared_ptr<Id> id3 = Id::fromString("3");

  EXPECT_TRUE(*id1 == *id2);
  EXPECT_TRUE(*id2 == *id1);

  EXPECT_TRUE(*id3 == *id3);

  EXPECT_TRUE(*id2 != *id3);
  EXPECT_TRUE(*id1 != *id3);
}

}
