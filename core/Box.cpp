#include <events/DomainEvents.h>
#include <algorithm>
#include "Box.h"

using namespace id;
using namespace std;

namespace core {

const int Box::COMPARTMENT_AMOUNT = 5;

Box::Box() :
  Box(Id::random()) {
}

Box::Box(shared_ptr<Id> id) {
  this->id = id;

  for (int i = 0; i < Box::COMPARTMENT_AMOUNT; i++) {
    compartments.push_back(shared_ptr<vector<shared_ptr<Id>>>(new vector<shared_ptr<Id>>()));
  }
}

Box::~Box() {
}

void Box::addCard(shared_ptr<Id> cardId) {
  assertCardIdNotNull(cardId);

  addCard(0, cardId);
}

void Box::addCard(const int compartment, std::shared_ptr<Id> cardId) {
  assertCorrectCompartment(compartment);

  compartments[compartment]->push_back(cardId);
}

bool Box::containsCard(int compartmentNumber, shared_ptr<Id> cardId) {
  assertCorrectCompartment(compartmentNumber);

  return findCard(compartmentNumber, cardId) != compartments[compartmentNumber]->end();
}

void Box::degradeCard(shared_ptr<Id> cardId) {
  assertCardIdNotNull(cardId);

  int compartmentNum = findCompartmentContaining(cardId);
  assertCorrectCompartment(compartmentNum);

  auto compartment = compartments[compartmentNum];
  
  auto position = findCard(compartmentNum, cardId);

  compartment->erase(position);
  compartments[0]->push_back(cardId);
}

vector<shared_ptr<Id>>::iterator Box::findCard(int compartmentNumber, shared_ptr<Id> cardId) {
  return find_if(compartments[compartmentNumber]->begin(),
    compartments[compartmentNumber]->end(), [&](shared_ptr<Id> const &e) {
    return *e == *cardId;
  });
}

void Box::assertCorrectCompartment(const int compartment) {
  if (compartment > COMPARTMENT_AMOUNT || compartment < 0) throw invalid_argument("compartmentNumber cannot be greater than " + COMPARTMENT_AMOUNT);
}

void Box::assertCardIdNotNull(std::shared_ptr<id::Id> cardId) {
  if (cardId == nullptr) throw invalid_argument("cardId cannot be NULL.");
}

int Box::findCompartmentContaining(std::shared_ptr<id::Id> cardId) {
  for (int i = 0; i < COMPARTMENT_AMOUNT; i++) {
    if (containsCard(i, cardId)) {
      return i;
    }
  }
  return -1;
}

void Box::advanceCard(shared_ptr<Id> cardId) {
  int compartmentNum = findCompartmentContaining(cardId);
  assertCorrectCompartment(compartmentNum);

  auto compartment = compartments[compartmentNum];

  auto position = findCard(compartmentNum, cardId);

  compartments[distance(compartment->begin(), position)]->push_back(cardId);
  compartment->erase(position);
}

} /* namespace core */
