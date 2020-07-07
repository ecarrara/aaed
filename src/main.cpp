#include "algo/bubblesort.hpp"
#include "algo/cartesiantreesort.hpp"
#include "algo/heapsort.hpp"
#include "algo/insertionsort.hpp"
#include "algo/mergesort.hpp"
#include "algo/quicksort.hpp"
#include "algo/selectionsort.hpp"
#include "testset.hpp"
#include <string>

template <typename T>
void print_vector(std::vector<T> v);

// Indica ao compilador que um código assembly vai realizar
// uma leitura de memória (em qualquer endereço).
// O compilador (GCC e LLVM) não analisam as instruçoes assembly
// para verificar qual endenreo vai ser lido.
// Isso é útil para evitar otimizações, em especial para quando
// o compilador detecta que uma variável não vai ser usada e
// remove o código que operava nela (caso da variável `testset`
// da função `main()` ).
static void clobber() {
    asm volatile(""
                 :
                 :
                 : "memory");
}

/**
 * ./p1 <algoritmo> <n> <f> <ascendente> <aleatório>
 * 
 *  Parâmetros:
 *    size_t n - número de elementos no arranjo
 *    float f - percentual de elementos em ordem (1.0 arranjo ordenado)
 *    bool ascending - true para ordenação ascendente, false para descendente
 *    bool random - gera números aleatórios se `true`, caso contrário, números sequências.
 * 
 *  Exemplo:
 *    ./p1 insertion 100000 0.0 f t
 */
int main(int argc, char **argv) {
    if (argc < 2 || argc > 6) {
        std::cerr << "Usage: " << argv[0] << " <algoritmo> [n (1 - +inf)] [f (0 - 1)] [ascending (t/f)] [random (t/f)]" << std::endl;
        return -1;
    }

    std::string algo = std::string(argv[1]);

    size_t n = argc >= 3 ? std::stoll(argv[2]) : 10000;
    float f = argc >= 4 ? std::stof(argv[3]) : 0.0;
    bool ascending = argc >= 5 ? std::string(argv[4]) == "t" : true;
    bool random = argc >= 6 ? std::string(argv[5]) == "t" : true;

    std::cout << "Parâmetros da execuçao:" << std::endl
              << "  algoritmo: " << algo << std::endl
              << "  número de elementos: " << n << std::endl
              << "  % de aleatórios: " << (f * 100.0) << "%" << std::endl
              << "  ordenação: " << ascending << std::endl
              << "  aleatório: " << random << std::endl;

    std::vector<int> testset = generate_set(n, f, ascending, random);

    if (algo == "insertion") {
        insertion_sort(testset);
    } else if (algo == "selection") {
        selection_sort(testset);
    } else if (algo == "bubble") {
        bubble_sort(testset);
    } else if (algo == "heap") {
        heap_sort(testset);
    } else if (algo == "merge") {
        merge_sort(testset);
    } else if (algo == "quick") {
        quick_sort(testset);
    } else if (algo == "cartesiantree") {
        cartesiantree_sort(testset);
    } else {
        std::cerr
            << "Método não suportado." << std::endl
            << "Os métodos suportados são: insertion, selection, bubble, heap, merge, quick e cartesiantree.";
        return -1;
    }

    clobber();

    return 0;
}

template <typename T>
void print_vector(std::vector<T> v) {
    for (int a : v) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}

void debug_generate_set() {
    std::cout << "(i) Arranjos ordenados números sequenciais:" << std::endl;
    std::vector<int> a = generate_set(15, 1.0);
    for (int v : a) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::cout << "(ii) Arranjos inversamento ordenados com números sequenciais:" << std::endl;
    a = generate_set(15, 1.0, false);
    for (int v : a) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::cout << "(iv) Arranjos com 80% ou mais dos elementos ordenados:" << std::endl;
    a = generate_set(15, 0.8);
    for (int v : a) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::cout << "(iv) Arranjos aleatórios:" << std::endl;
    a = generate_set(15, 0.0, true, true);
    for (int v : a) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}
