#include "algo/bubblesort.hpp"
#include "algo/cartesiantreesort.hpp"
#include "algo/heapsort.hpp"
#include "algo/insertionsort.hpp"
#include "algo/mergesort.hpp"
#include "algo/quicksort.hpp"
#include "algo/selectionsort.hpp"
#include "testset.hpp"
#include <fstream>
#include <string>

template <typename T>
void print_vector(const std::vector<T> &v);

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
 * ./p1 <algoritmo> <testset>
 * 
 *  Exemplo:
 *    ./p1 insertion ./results/testset/10_1.0_t_t.bin
 */
int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <algoritmo> <testset>" << std::endl;
        return -1;
    }

    std::string algo = std::string(argv[1]);

    std::ifstream input_file(argv[2], std::ios::binary);
    std::vector<int> testset = deserialize_vector<int>(input_file);
    // print_vector(testset);

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

    // print_vector(testset);
    clobber();

    return 0;
}

template <typename T>
void print_vector(const std::vector<T> &v) {
    for (int a : v) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}
