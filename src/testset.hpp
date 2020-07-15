#ifndef TESTSET_H
#define TESTSET_H

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/**
 *  Gera arranjo quase ordenado (iii).
 *
 *  Parâmetros:
 *    size_t n - número de elementos no arranjo
 *    float f - percentual de elementos em ordem (1.0 arranjo ordenado)
 *    bool ascending - true para ordenação ascendente, false para descendente
 *    bool random - gera números aleatórios se `true`, caso contrário, números sequências.
 *  Retorno:
 *    std::vector<int> de tamanho `n` com `f` % de elementos ordenados.
 *
 *  Exemplos de uso:
 *    (i) Arranjos ordenados números sequenciais: generate_set(100, 1.0)
 *    (ii) Arranjos inversamento ordenados com números sequenciais: generate_set(100, 1.0, false)
 *    (iii) Arranjos com 70% ou mais dos elementos ordenados: generate_set(100, 0.7)
 *    (iv) Arranjos aleatórios: generate_set(100, 0.0, true, true)
 */
std::vector<int> generate_set(size_t n, float f = 0.0, bool ascending = true, bool random = false) {
    std::vector<int> S(n);
    std::random_device rd;

    for (size_t i = 0; i < n; i++) {
        if (random) {
            S[i] = rd();
        } else {
            S[i] = ascending ? i : n - i - 1;
        }
    }

    // ordena elementos no caso do conjunto aleatório
    if (random) {
        if (ascending) {
            std::sort(S.begin(), S.end(), std::less<>());
        } else {
            std::sort(S.begin(), S.end(), std::greater<>());
        }
    }

    // realiza (1.0 - f)% de trocas para tirar de ordem
    for (int i = 0; i < n * (1.0 - f); i++) {
        size_t a = rd() % n;
        size_t b = rd() % n;
        std::swap(S[a], S[b]);
    }

    return S;
}

/** Serializa vetor para um stream. */
template <typename T>
void serialize_vector(const std::vector<T> &in, std::ostream &s) {
    size_t n = in.size();
    s.write(reinterpret_cast<const char *>(&n), sizeof(size_t));
    s.write(reinterpret_cast<const char *>(in.data()), sizeof(T) * n);
}

/** Deserializa vetor em um stream. */
template <typename T>
std::vector<T> deserialize_vector(std::istream &s) {
    size_t n;
    s.read(reinterpret_cast<char *>(&n), sizeof(n));

    std::vector<T> out;
    out.reserve(n);

    while (n--) {
        T el;
        s.read(reinterpret_cast<char *>(&el), sizeof(T));
        out.push_back(el);
    }
    return out;
}

#endif /* TESTSET_H */
