#include <events/DomainEvents.h>
#include <algorithm>
#include "Box.h"

using namespace id;
using namespace std;

namespace core {

const unsigned int Box::COMPARTMENT_AMOUNT = 5;

Box::Box() :
    Box(Id::random()) {
}

Box::Box(shared_ptr<Id> id) {
  this->id = id;

  for (unsigned int i = 0; i < Box::COMPARTMENT_AMOUNT; i++) {
    compartments.push_back(vector<shared_ptr<Id>>());
  }
}

Box::~Box() {
}

void Box::addCard(shared_ptr<Id> cardId) {
  compartments[0].push_back(cardId);
}

bool Box::containsCard(unsigned int compartmentNumber, shared_ptr<Id> cardId) {
  return find_if(compartments[compartmentNumber].begin(),
      compartments[compartmentNumber].end(), [&](shared_ptr<Id> const &e) {
        return *e == *cardId;
      }) != compartments[compartmentNumber].end();
}

} /* namespace core */
