#include "StdInc.h"
#include "DoubleLinkedList.h"

class DoubleLinkedListTest : public testing::Test
{
public:
	DoubleLinkedList<int> list;
};


TEST_F(DoubleLinkedListTest, isFrontAndBackEqual)
{
	list.insert(0, -3);
	EXPECT_EQ(list.back()->getValue(), -3);
	EXPECT_EQ(list.front()->getValue(), -3);
	list.insert(3, 6);
	EXPECT_EQ(list.get(1)->getValue(), 6);
	EXPECT_EQ(list.get(1)->getPrev()->getValue(), -3);
}

TEST_F(DoubleLinkedListTest, previousElement)
{
	list.insert(0, -3);
	EXPECT_EQ(list.get(0)->getPrev(), nullptr);
	list.insert(1, 6);
	EXPECT_EQ(list.get(1)->getPrev()->getValue(), -3);
}

TEST_F(DoubleLinkedListTest, nextElement)
{
	list.insert(0, -3);
	EXPECT_EQ(list.get(0)->getNext(), nullptr);
	list.insert(1, 6);
	EXPECT_EQ(list.get(0)->getNext()->getValue(), 6);
}

TEST_F(DoubleLinkedListTest, insertInPlace)
{
	list.insert(0, -3);
	list.insert(1, 5);
	list.insert(2, 0);
	list.insert(0, 99);
	EXPECT_EQ(list.get(1)->getValue(), 99);
}


TEST_F(DoubleLinkedListTest, replace)
{
	list.insert(0, -3);
	list.insert(1, 5);
	list.insert(2, 0);
	list.replace(1, 3);
	list.replace(0, 15);
	EXPECT_EQ(list.get(0)->getValue(), 15);
	EXPECT_EQ(list.get(1)->getValue(), 3);
	EXPECT_EQ(list.get(2)->getValue(), 0);
}

TEST_F(DoubleLinkedListTest, removeFrom) {
	list.insert(0, -3);
	list.insert(1, 0);
	list.insert(2, 2);
	list.insert(3, 5);
	list.insert(4, 8);
	
	list.remove(0);
	list.remove(1);
	list.remove(2);
	
	EXPECT_EQ(list.front()->getValue(), 0);
	EXPECT_EQ(list.back()->getValue(), 5);
	EXPECT_EQ(list.size(), 2);
}


TEST_F(DoubleLinkedListTest, find) {
	list.insert(0, -3);
	list.insert(1, -44);
	list.insert(2, 13);
	list.insert(3, 14);
	
	EXPECT_EQ(list.find(-44), 1);
	EXPECT_EQ(list.find(13), 2);
	EXPECT_EQ(list.find(14), 3);
}

TEST_F(DoubleLinkedListTest, findRemove) {
	list.insert(0, -3);
	list.insert(1, 0);
	list.insert(2, 2);
	list.insert(3, 5);
	list.insert(4, 8);
	
	
	list.removeFind(3);
	
	list.removeFind(8);
	list.removeFind(0);
	list.removeFind(-3);
	
	EXPECT_EQ(list.front()->getValue(), 2);
	EXPECT_EQ(list.back()->getValue(), 5);
	EXPECT_EQ(list.size(), 2);
}