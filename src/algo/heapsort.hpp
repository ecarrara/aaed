#ifndef ALG_HEAPSORT_H
#define ALG_HEAPSORT_H

#include <vector>

template <typename T>
void heap_rebuild(std::vector<T> &in, size_t left, size_t right) {
    size_t i = left;
    size_t j = (i * 2) + 1;
    size_t aux = in[i];

    while (j <= right) {
        if ((j < right) && (in[j] < in[j + 1]))
            j++;

        if (aux >= in[j])
            break;

        in[i] = in[j];
        i = j;
        j = (i * 2) + 1;
    }
    in[i] = aux;
}

/**
 * Constrói o heap máximo de `in`.
 */
template <typename T>
void heap_build(std::vector<T> &in) {
    for (long long i = in.size() / 2 - 1; i >= 0; i--) {
        heap_rebuild(in, i, in.size() - 1);
    }
}

template <typename T>
void heap_sort(std::vector<T> &in) {
    heap_build(in);

    size_t m = in.size() - 1;
    while (m > 0) {
        std::swap(in[0], in[m]);
        m = m - 1;
        heap_rebuild(in, 0, m);
    }
}

#endif /* ALGO_HEAPSORT_H */