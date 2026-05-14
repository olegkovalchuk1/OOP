#pragma once
#include <vector>
#include <algorithm> // для std::swap
#include <iterator>

// Алгоритм сортування всіх елементів
template <typename Iterator>
void custom_sort(Iterator first, Iterator last) {
    if (first == last) return;
    for (Iterator i = first; i != last; ++i) {
        Iterator min_iter = i;
        for (Iterator j = std::next(i); j != last; ++j) {
            if (*j < *min_iter) {
                min_iter = j;
            }
        }
        std::swap(*i, *min_iter);
    }
}

// Алгоритм сортування елементів за умовою (функтором)
template <typename Iterator, typename Predicate>
void custom_sort_if(Iterator first, Iterator last, Predicate pred) {
    std::vector<Iterator> valid_iters;
    for (Iterator i = first; i != last; ++i) {
        if (pred(*i)) {
            valid_iters.push_back(i);
        }
    }

    if (valid_iters.empty()) return;

    for (size_t i = 0; i < valid_iters.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < valid_iters.size(); ++j) {
            if (*valid_iters[j] < *valid_iters[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(*valid_iters[i], *valid_iters[min_idx]);
    }
}