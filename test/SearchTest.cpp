#include "StdInc.h"
#include "SearchContainer.h"
#include "PatternFinder.h"

class SearchTest : public testing::Test
{
public:
	SearchContainer<int> container;
	PatternFinder pattern;
	
	void linear(int searchedIndex, int result)
	{
		ASSERT_EQ(container.linearSearch(searchedIndex), result);
	};
	
	void iterative(int searched, int result)
	{
		ASSERT_EQ(container.iterativeBinarySearch(searched), result);
	};
	
	void recursive(int searched, int result)
	{
		ASSERT_EQ(container.recursiveBinarySearch(searched, 0, container.getSize() - 1), result);
	};
};

TEST_F(SearchTest, linearSearch)
{
	int array[] = {3,2,5,5,55,4,1,9,11,0};
	
	container = SearchContainer<int>(array, 10);
	
	linear(3,0);
	linear(11,8);
	linear(55,4);
	linear(1, 6);
	linear(0, 9);
}

TEST_F(SearchTest, iterativeBinarySearch)
{
	int array[] = {0, 2, 3, 7, 34};
	
	container = SearchContainer<int>(array, 5);
	iterative(0,0);
	iterative(2,1);
	iterative(3,2);
	iterative(7,3);
	iterative(34,4);

}

TEST_F(SearchTest, recursiveBinarySearch)
{
	int array[] = {-3, -1, 3, 7, 9};
	
	container = SearchContainer<int>(array, 5);
	iterative(-3,0);
	iterative(-1,1);
	iterative(3,2);
	iterative(7,3);
	iterative(9,4);
}

TEST_F(SearchTest, patternKMP)
{
	ASSERT_THAT(pattern.KMP("ABXABABXAB", "ABXAB"), testing::ElementsAre(0, 5));
	ASSERT_THAT(pattern.KMP("AABAACAADAABAABA", "AABA"), testing::ElementsAre(0, 9, 12));
}

TEST_F(SearchTest, patternBoyerMoore)
{
	ASSERT_THAT(pattern.BoyerMoore("GCAATGCCTATGTGACC", "TATGTG"), testing::ElementsAre(8));
	ASSERT_THAT(pattern.BoyerMoore("ABXABABXAB", "ABXAB"), testing::ElementsAre(0, 5));
	ASSERT_THAT(pattern.BoyerMoore("AABAACAADAABAABA", "AABA"), testing::ElementsAre(0, 9, 12));
	ASSERT_THAT(pattern.BoyerMoore("ABAAAABAACD", "ABA"), testing::ElementsAre(0, 5));
}

TEST_F(SearchTest, patternRabinKarp)
{
	ASSERT_THAT(pattern.KarpRabin("GCAATGCCTATGTGACC", "TATGTG"), testing::ElementsAre(8));
}