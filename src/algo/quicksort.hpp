#ifndef ALGO_QUICKSORT_H
#define ALGO_QUICKSORT_H

#include <iostream>
#include <vector>

template <typename T>
void quick_sort_partition(std::vector<T> &in, size_t p, size_t r, long long *q, long long *t) {
    T x = in[r];
    long long i = p - 1;
    long long j = p;
    long long k = r;

    while (j <= k - 1) {
        if (in[j] < x) {
            i++;
            std::swap(in[i], in[j]);
        } else if (in[j] == x) {
            k--;
            std::swap(in[j], in[k]);
            j--;
        }
        j++;
    }

    *q = i + 1;
    for (j = k; j <= r; j++) {
        i++;
        std::swap(in[i], in[j]);
    }
    *t = i;
}

template <typename T>
void quick_sort_sort(std::vector<T> &in, long long p, long long r) {
    long long q, t;
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
    quick_sort_sort(in, 0, in.size() - 1);
}

#endif /* ALGO_QUICKSORT_H */