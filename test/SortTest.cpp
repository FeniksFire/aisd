#include "StdInc.h"
#include "SortContainer.h"

class SortTest : public testing::Test
{
public:
	SortContainer<int> container;
};

TEST_F(SortTest, bubbleSortIntegerArray)
{
	int array[] = {3,2,5,5,55,4,1,9,11,0};
	int sortedArray[] = {0, 1, 2, 3, 4, 5, 5, 9, 11, 55};
	
	container = SortContainer<int>(array, 10);
	container.bubbleSort();
	for(int i = 0; i<10; i++)
		ASSERT_EQ(container.valueAt(i), sortedArray[i]);
}

TEST_F(SortTest, innerSortIntegerArray)
{
	int array[] = {6, 3, 7, 5, 1};
	int sortedArray[] = {1, 3, 5, 6, 7};
	
	container = SortContainer<int>(array, 5);
	container.innerSort();
	for(int i = 0; i<5; i++)
		ASSERT_EQ(container.valueAt(i), sortedArray[i]);
}

TEST_F(SortTest, selectionSortIntegerArray)
{
	int array[] = {6, 3, 7, 0, 1};
	int sortedArray[] = {0, 1, 3, 6, 7};
	
	container = SortContainer<int>(array, 5);
	container.selectionSort();
	for(int i = 0; i<5; i++)
		ASSERT_EQ(container.valueAt(i), sortedArray[i]);
}

TEST_F(SortTest, partitionZeroOne)
{
	int array[] = {0, 1, 0, 0, 1, 1, 0, 1, 0};
	int segregated[] = {0, 0, 0, 0, 0, 1, 1, 1, 1};
	
	container = SortContainer<int>(array, 9);
	container.partition(0, container.getSize()-1, [](int a) { return a == 0; });
	for(int i = 0; i<9; i++)
		ASSERT_EQ(container.valueAt(i), segregated[i]);
}

TEST_F(SortTest, partitionZeroOneTwo)
{
	int array[] = {2, 0, 0, 2, 1, 2, 0, 1, 0};
	int segregated[] = {0, 0, 0, 0, 1, 1, 2, 2, 2};
	
	container = SortContainer<int>(array, 9);
	container.threeWayPartition([](int a) { return a > 1; }, [](int a) { return a == 1; });
	for(int i = 0; i<9; i++)
		ASSERT_EQ(container.valueAt(i), segregated[i]);
}

TEST_F(SortTest, quickSort)
{
	int array[] = {6, 3, 7, 5, 1};
	int sortedArray[] = {1, 3, 5, 6, 7};
	
	container = SortContainer<int>(array, 5);
	
	container.quickSort(0, 4);
	
	for(int i = 0; i<5; i++)
		ASSERT_EQ(container.valueAt(i), sortedArray[i]);
}