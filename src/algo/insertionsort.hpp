#ifndef ALGO_INSERTIONSORT_H
#define ALGO_INSERTIONSORT_H

#include <vector>

template <typename T>
void insertion_sort(std::vector<T> &in) {
    for (size_t i = 1; i < in.size(); i++) {
        T aux = in[i];

        long j = i - 1;
        while ((j >= 0) && (aux < in[j])) {
            in[j + 1] = in[j];
            j--;
        }

        in[j + 1] = aux;
    }
}

#endif /* ALGO_INSERTIONSORT_H */