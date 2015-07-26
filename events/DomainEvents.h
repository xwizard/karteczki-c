#ifndef DOMAINEVENTS_H_
#define DOMAINEVENTS_H_

#include <vector>
#include "Event.h"

using namespace std;

namespace events {

class DomainEvents {
public:
	static vector<Event> events;
};

} /* namespace events */

#endif /* DOMAINEVENTS_H_ */
