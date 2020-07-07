#ifndef ALGO_QUICKSORT_H
#define ALGO_QUICKSORT_H

#include <vector>

template <typename T>
void quick_sort_partition(std::vector<T> &in, int p, int r, int *q, int *t) {
    T x = in[r];
    size_t i = p - 1;
    size_t j = p;
    size_t k = r;

    while (j <= k - 1) {
        if (in[j] < x) {
            i = i + 1;
            std::swap(in[i], in[j]);
        } else if (in[j] == x) {
            k -= 1;
            std::swap(in[j], in[k]);
            j -= 1;
        }

        *q = i + 1;
        for (j = k; j <= r; j++) {
            i = i + 1;
            std::swap(in[i], in[j]);
        }
        *t = i;
    }
}

template <typename T>
void quick_sort_sort(std::vector<T> &in, int p, int r) {
    size_t q, t;
    while (p < r) {
        quick_sort_partition(in, p, r, &q, &t);

        if (q - p < r - t) {
            quick_sort_sort(in, p, q - 1);
            p = t + 1;
        } else {
            quick_sort_sort(in, t + 1, r);
            r = q - 1;
        }
    }
}

template <typename T>
void quick_sort(std::vector<T> &in) {
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

#endif /* ALGO_QUICKSORT_H */