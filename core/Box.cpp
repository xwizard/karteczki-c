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
    compartments.push_back(shared_ptr<vector<shared_ptr<Id>>>(new vector<shared_ptr<Id>>()));
  }
}

Box::~Box() {
}

void Box::addCard(shared_ptr<Id> cardId) {
  if (cardId == nullptr) throw invalid_argument("cardId cannot be NULL.");

  addCard(0, cardId);
}

void Box::addCard(const unsigned int compartment, std::shared_ptr<id::Id> cardId) {
  assertCorrectCompartment(compartment);

  compartments[compartment]->push_back(cardId);
}

bool Box::containsCard(unsigned int compartmentNumber, shared_ptr<Id> cardId) {
  assertCorrectCompartment(compartmentNumber);

  return find_if(compartments[compartmentNumber]->begin(),
    compartments[compartmentNumber]->end(), [&](auto &e) {
    return *e == *cardId;
  }) != compartments[compartmentNumber]->end();
}

void Box::degradeCard(std::shared_ptr<id::Id> cardId) {
  unsigned int compartmentNum = (unsigned int)findCompartmentContaining(cardId);
  auto compartment = compartments[compartmentNum];
  
  auto position = find_if(compartment->begin(),
    compartment->end(), [&](shared_ptr<Id> const &e) {
    return *e == *cardId;
  });

  compartment->erase(position);
  compartments[0]->push_back(cardId);
}

void Box::assertCorrectCompartment(const unsigned int compartment) {
  if (compartment > COMPARTMENT_AMOUNT) throw invalid_argument("compartmentNumber cannot be greater than " + COMPARTMENT_AMOUNT);
}

int Box::findCompartmentContaining(std::shared_ptr<id::Id> cardId) {
  for (unsigned int i = 0; i < COMPARTMENT_AMOUNT; i++) {
    if (containsCard(i, cardId)) {
      return (int)i;
    }
  }
  return -1;
}

} /* namespace core */
