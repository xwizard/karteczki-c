#ifndef SRC_BOX_H_
#define SRC_BOX_H_

#include <memory>
#include <vector>
#include <id/Id.h>

namespace core {

class Box {
public:
  Box();
  Box(std::shared_ptr<id::Id> id);
  virtual ~Box();
  void addCard(std::shared_ptr<id::Id> cardId);
  void addCard(const int compartment, std::shared_ptr<id::Id> cardId);
  bool containsCard(int compartmentNumber, std::shared_ptr<id::Id> cardId);
  void degradeCard(std::shared_ptr<id::Id> cardId);
  std::vector<std::shared_ptr<id::Id>>::iterator findCard(int compartmentNumber, std::shared_ptr<id::Id> cardId);
  void advanceCard(std::shared_ptr<id::Id> cardId);
private:
  std::shared_ptr<id::Id> id;
  std::vector<std::shared_ptr<std::vector<std::shared_ptr<id::Id>>>> compartments;
  static const int COMPARTMENT_AMOUNT;
  void assertCorrectCompartment(const int compartment);
  void assertCardIdNotNull(std::shared_ptr<id::Id> cardId);
  signed int findCompartmentContaining(std::shared_ptr<id::Id> cardId);
};

}
/* namespace core */

#endif /* SRC_BOX_H_ */
