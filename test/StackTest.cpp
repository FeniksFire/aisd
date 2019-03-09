#include "StdInc.h"
#include "Stack.h"

class StackTest : public testing::Test
{
public:
	Stack<int> stack;
};

TEST_F(StackTest, isEmptyWhenCreated)
{
	EXPECT_TRUE(stack.empty());
	EXPECT_EQ(stack.size(), 0);
}

TEST_F(StackTest, pushElement)
{
	stack.push(23);
	EXPECT_EQ(stack.top(), 23);
	
	stack.push(-3);
	EXPECT_EQ(stack.top(), -3);
	EXPECT_EQ(stack.size(), 2);
}

TEST_F(StackTest, popElement)
{
	stack.push(33);
	stack.push(9);
	stack.push(85);
	stack.pop();
	EXPECT_EQ(stack.top(), 9);
	stack.pop();
	EXPECT_EQ(stack.top(), 33);
	EXPECT_EQ(stack.size(), 1);
}