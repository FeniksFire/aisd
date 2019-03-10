#include "StdInc.h"
#include "Queue.h"

class QueueTest : public testing::Test
{
public:
	Queue<int> queue;
};

TEST_F(QueueTest, isEmptyWhenCreated)
{
	EXPECT_TRUE(queue.empty());
}

TEST_F(QueueTest, isNoEmptyWhenElementPushed)
{
	queue.push(23);
	EXPECT_FALSE(queue.empty());
}

TEST_F(QueueTest, haveOneSizeWhenElementPushed)
{
	queue.push(-3);
	EXPECT_EQ(queue.size(), 1);
}

TEST_F(QueueTest, isFrontAndBackEqual)
{
	queue.push(-3);
	EXPECT_EQ(queue.back(), -3);
	EXPECT_EQ(queue.front(), -3);
}

TEST_F(QueueTest, popElement)
{
	queue.push(-3);
	queue.push(8);
	queue.push(3);
	queue.push(0);
	queue.pop();
	EXPECT_EQ(queue.back(), 0);
	EXPECT_EQ(queue.front(), 8);
}