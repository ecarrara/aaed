#ifndef ALG_BUBBLESORT_H
#define ALG_BUBBLESORT_H

#include <vector>

template <typename T>
void bubble_sort(std::vector<T> &in) {
    for (size_t i = 0; i < in.size() - 1; i++) {
        bool changed = false;

        for (size_t j = 1; j < in.size() - i; j++) {
            if (in[j] < in[j - 1]) {
                std::swap(in[j], in[j - 1]);
                changed = true;
            }
        }

        if (!changed)
            break;
    }
}

#endif /* ALGO_BUBBLESORT_H */