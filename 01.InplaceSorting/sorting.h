#ifndef SORTING_H
#define SORTING_H

// Header-only

// Для swap
#include "collvalue.h"
#include <iterator>

// ----------------------------- Пузырёк (например) --------------------------------------
template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end)
{
    if (begin == end) return;

    for (auto i = begin; i != end; ++i)
    {
        bool swapped = false;
        auto limit = end;
        for (auto j = begin; j != limit; ++j)
        {
            auto next = std::next(j);
            if (next == limit) break;

            if (*next < *j)
            {
                using std::swap;
                swap(*j, *next);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


// --------------------------- QuickSort (например) ---------------------------------------
template <typename Iterator>
void quick_sort(Iterator begin, Iterator end)
{
    if (begin == end) return;
    if (std::next(begin) == end) return;

    auto pivot_iter = std::prev(end);
    auto pivot_value = *pivot_iter;
    auto i = begin;

    for (auto j = begin; j != pivot_iter; ++j)
    {
        if (*j < pivot_value)
        {
            if (i != j)
            {
                using std::swap;
                swap(*i, *j);
            }
            ++i;
        }
    }

    using std::swap;
    swap(*i, *pivot_iter);

    // Рекурсивно сортируем левую и правую части
    quick_sort(begin, i);
    quick_sort(std::next(i), end);
}

#endif // SORTING_H