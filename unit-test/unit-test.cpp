#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ConsoleApplication4/myclass.h"
#include "ConsolePatterns/Prototype.h"

using namespace ::testing;

class MockMyClass : public IMyClass
{
public:
	MOCK_METHOD0(someAction, int());
};

//class MockPrototype : public Prototype
//{
//public:
//	MOCK_METHOD0(run, void());
//};


TEST(testcase, testname01)
{
	EXPECT_EQ(1, 1);
	ASSERT_EQ(1, 1);
}

TEST(mocktestcase, mockname01)
{
	MockMyClass myClass;
	EXPECT_CALL(myClass, someAction())              // #3
		.Times(AtLeast(1));
	myClass.someAction();

	//MockPrototype myPrototype;
	//EXPECT_CALL(myPrototype, run())              // #3
	//	.Times(AtLeast(1));
	//myClass.someAction();

}

int main(int argc, char** argv) {
	std::cout << "Running main() from gmock_main.cc\n";
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
