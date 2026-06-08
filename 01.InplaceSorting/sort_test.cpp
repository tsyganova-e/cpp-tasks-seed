#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting.h"

TEST(BubbleSortTest, Sorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(BubbleSortTest, Reverse) {
    std::vector<int> v = {5, 4, 3, 2, 1};
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, Sorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, Reverse) {
    std::vector<int> v = {5, 4, 3, 2, 1};
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(BubbleSortTest, Empty) {
    std::vector<int> v;
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(QuickSortTest, Empty) {
    std::vector<int> v;
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(BubbleSortTest, Single) {
    std::vector<int> v = {42};
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(QuickSortTest, Single) {
    std::vector<int> v = {42};
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(BubbleSortTest, Duplicates) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, Duplicates) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}