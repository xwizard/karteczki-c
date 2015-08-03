#ifndef SRC_BOX_H_
#define SRC_BOX_H_

#include <memory>
#include <vector>
#include <id/Id.h>

using namespace std;

namespace core {

class Box {
public:
	Box();
	Box(shared_ptr<id::Id> id);
	virtual ~Box();
private:
	shared_ptr<id::Id> id;
	vector<vector<shared_ptr<id::Id>>> compartments;
};

} /* namespace core */

#endif /* SRC_BOX_H_ */
