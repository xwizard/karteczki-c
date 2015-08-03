#include <events/DomainEvents.h>
#include "Box.h"

namespace core {

Box::Box() {
	id = id::Id::random();
}

Box::Box(shared_ptr<id::Id> id) {
	this->id = id;
}

Box::~Box() {}

} /* namespace core */
