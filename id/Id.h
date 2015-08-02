#ifndef ID_H
#define ID_H

#include <string>

using namespace std;

namespace id {

class Id {
public:
  static Id random();
  static Id fromString(string str);
  string value();
  virtual ~Id();
  bool operator==(const Id& id);
  bool operator!=(const Id& id);
private:
  Id();
  Id(const string str);
  string value_ = "";
  static const char alphanum[];
  static const int len;
};

} /* namespace id */

#endif
