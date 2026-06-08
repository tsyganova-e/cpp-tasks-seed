#include <gtest/gtest.h>

#include "sorting.h"
#include <vector>
#include <algorithm>  // для std::is_sorted
#include <numeric>    // для std::iota

// Bubble Sort
TEST(BubbleSortSuite, EmptyArray)
{
    std::vector<int> arr;
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(arr.empty());
}

TEST(BubbleSortSuite, SingleElement)
{
    std::vector<int> arr = {42};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 42);
}

TEST(BubbleSortSuite, AlreadySorted)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 3, 4, 5}));
}

TEST(BubbleSortSuite, ReverseSorted)
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 3, 4, 5}));
}

TEST(BubbleSortSuite, RandomUnsorted)
{
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

TEST(BubbleSortSuite, AllEqualElements)
{
    std::vector<int> arr = {8, 8, 8, 8, 8};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {8, 8, 8, 8, 8}));
}

TEST(BubbleSortSuite, NegativeNumbers)
{
    std::vector<int> arr = {-5, 3, -2, 0, -10, 8};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {-10, -5, -2, 0, 3, 8}));
}

TEST(BubbleSortSuite, DuplicatesInMiddle)
{
    std::vector<int> arr = {5, 3, 3, 1, 2, 2, 4};
    bubble_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 2, 3, 3, 4, 5}));
}


// Quick Sort
TEST(QuickSortSuite, EmptyArray)
{
    std::vector<int> arr;
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(arr.empty());
}

TEST(QuickSortSuite, SingleElement)
{
    std::vector<int> arr = {42};
    quick_sort(arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 42);
}

TEST(QuickSortSuite, AlreadySorted)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 3, 4, 5}));
}

TEST(QuickSortSuite, ReverseSorted)
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 3, 4, 5}));
}

TEST(QuickSortSuite, RandomUnsorted)
{
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

TEST(QuickSortSuite, AllEqualElements)
{
    std::vector<int> arr = {8, 8, 8, 8, 8};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {8, 8, 8, 8, 8}));
}

TEST(QuickSortSuite, NegativeNumbers)
{
    std::vector<int> arr = {-5, 3, -2, 0, -10, 8};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {-10, -5, -2, 0, 3, 8}));
}

TEST(QuickSortSuite, DuplicatesInMiddle)
{
    std::vector<int> arr = {5, 3, 3, 1, 2, 2, 4};
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr, (std::vector<int> {1, 2, 2, 3, 3, 4, 5}));
}

TEST(QuickSortSuite, LargeArray)
{
    std::vector<int> arr(1000);
    std::iota(arr.begin(), arr.end(), 1);
    std::reverse(arr.begin(), arr.end());
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

TEST(QuickSortSuite, AlreadySortedLarge)
{
    std::vector<int> arr(1000);
    std::iota(arr.begin(), arr.end(), 1);
    quick_sort(arr.begin(), arr.end());
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}