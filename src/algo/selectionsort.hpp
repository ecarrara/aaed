#ifndef ALGO_SELECTIONSORT_H
#define ALGO_SELECTIONSORT_H

#include <vector>

template <typename T>
void selection_sort(std::vector<T> &in) {
    for (int i = 0; i < in.size() - 1; i++) {
        size_t min = i;

        for (size_t j = i + 1; j < in.size(); j++) {
            if (in[j] < in[min]) {
                min = j;
            }
        }

        std::swap(in[i], in[min]);
    }
}

#endif /* ALGO_SELECTIONSORT_H */