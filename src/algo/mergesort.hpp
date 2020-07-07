#ifndef ALGO_MERGESORT_H
#define ALGO_MERGESORT_H

#include <algorithm> // std::inplace_merge
#include <vector>

template <typename Iterator>
void merge_sort(Iterator first, Iterator last) {
    if (last - first > 1) {
        auto middle = first + ((last - first) / 2);
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

template <typename T>
void merge_sort(std::vector<T> &in) {
    merge_sort(in.begin(), in.end());
}

#endif /* ALGO_MERGESORT_H */