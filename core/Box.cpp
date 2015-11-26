#include <events/DomainEvents.h>
#include <algorithm>
#include "Box.h"

using namespace id;
using namespace std;

namespace core {

const unsigned int Box::COMPARTMENT_AMOUNT = 5;

Box::Box() : Box(Id::random()) {}

Box::Box(shared_ptr<Id> id) {
	this->id = id;

  for (unsigned int i = 0; i < Box::COMPARTMENT_AMOUNT; i++) {
    compartments.push_back(vector<shared_ptr<Id>>());
  }
}

Box::~Box() {}

void Box::addCard(shared_ptr<Id> cardId) {

}

bool Box::containsCard(unsigned int compartmentNumber, std::shared_ptr<Id> cardId)
{
  return find(compartments[compartmentNumber].begin(), compartments[compartmentNumber].end(), cardId) != compartments[compartmentNumber].end();
}

} /* namespace core */
