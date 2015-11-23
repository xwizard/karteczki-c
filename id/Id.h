#ifndef ID_H
#define ID_H

#include <string>
#include <memory>

namespace id {

class Id {
public:
  static std::shared_ptr<Id> random();
  static std::shared_ptr<Id> fromString(std::string str);
  std::string value();
  virtual ~Id();
  bool operator==(const Id& id);
  bool operator!=(const Id& id);
private:
  Id();
  Id(const std::string str);
  std::string value_ = "";
  static const char alphanum[];
  static const int len;
};

} /* namespace id */

#endif
