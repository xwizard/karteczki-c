#include <events/DomainEvents.h>
#include "Box.h"

using namespace id;

namespace core {

Box::Box() {
	id = Id::random();
}

Box::Box(shared_ptr<Id> id) {
	this->id = id;
}

Box::~Box() {}

} /* namespace core */
