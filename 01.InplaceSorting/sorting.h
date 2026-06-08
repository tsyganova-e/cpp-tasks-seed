#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
#include <utility>

template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end)
{
    if (begin == end) return;
    bool swapped;
    do {
        swapped = false;
        Iterator it = begin;
        for (Iterator next = begin; ++next != end; ++it) {
            if (*next < *it) {
                std::swap(*it, *next);
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename Iterator>
void quick_sort(Iterator begin, Iterator end)
{
    if (end - begin <= 1) return;
    Iterator pivot = begin + (end - begin) / 2;
    std::swap(*pivot, *(end - 1));
    pivot = end - 1;
    Iterator left = begin;
    for (Iterator right = begin; right != pivot; ++right) {
        if (*right < *pivot) {
            std::swap(*left, *right);
            ++left;
        }
    }
    std::swap(*left, *pivot);
    quick_sort(begin, left);
    quick_sort(left + 1, end);
}

#endif