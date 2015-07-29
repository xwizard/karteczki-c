#include <gtest/gtest.h>
#include <events-test/DomainEventsTest.h>

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
