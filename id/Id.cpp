#include <cstdlib>
#include "Id.h"

namespace id {

Id::Id() {}

Id::~Id() {}

const char Id::alphanum[] =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";

const int Id::len = 16;

Id::Id(const string str) {
  value_ = str;
}

bool Id::operator==(const Id& id) {
  return value_ == id.value_;
}

bool Id::operator!=(const Id& id) {
  return value_ != id.value_;
}

shared_ptr<Id> Id::random() {
  // http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
  char s[len];
  for (int i = 0; i < len; ++i) {
    s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  s[len - 1] = 0;
  return shared_ptr<Id>(new Id(string(s)));
}

shared_ptr<Id> Id::fromString(string str) {
  return shared_ptr<Id>(new Id(str));
}

string Id::value() {
  return value_;
}

}
