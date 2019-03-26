#include "StdInc.h"
#include "Container.h"

class ContainerTest : public testing::Test
{
public:
	Container<int> container;
	void count(int value, int result)
	{
		ASSERT_EQ(container.count(value), result);
	};
};

TEST_F(ContainerTest, isEmpty)
{
	EXPECT_TRUE(container.empty());
}

TEST_F(ContainerTest, reserveSize)
{
	container.reserve(7);
	EXPECT_EQ(container.getSize(), 7);
	
	container.reserve(3);
	EXPECT_EQ(container.end() - container.begin(), 3);
}

TEST_F(ContainerTest, getValue)
{
	int array[] = {1, 7, 5, 4, 3, 8};
	
	container = Container<int>(array, 6);
	
	EXPECT_EQ(container.valueAt(0), 1);
	EXPECT_EQ(container.valueAt(4), 3);
	EXPECT_EQ(container.valueAt(5), 8);
}

TEST_F(ContainerTest, isDynamic)
{
	int array[] = {1, 7, 5, 4, 3, 8};
	
	container = Container<int>(array, 6);
	EXPECT_FALSE(container.isDynamic());
	
	container.reserve(7);
	EXPECT_TRUE(container.isDynamic());
}

TEST_F(ContainerTest, count)
{
	int array[] = {0, 1, 0, 3, 0, 3, 1, 1, 3, 0, 1, 0};
	
	container = Container<int>(array, 12);
	
	count(0,5);
	count(1,4);
	count(3,3);
}