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
  bool containsCard(unsigned int compartmentNumber, std::shared_ptr<id::Id> cardId);
private:
	std::shared_ptr<id::Id> id;
	std::vector<std::vector<std::shared_ptr<id::Id>>> compartments;
  static const unsigned int COMPARTMENT_AMOUNT;
};

} /* namespace core */

#endif /* SRC_BOX_H_ */
