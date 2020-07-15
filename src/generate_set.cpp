#include "testset.hpp"
#include <fstream>
#include <string>

/**
 * ./generate_set <output_filepath> <n> <f> <ascendente> <aleatório>
 * 
 *  Parâmetros:
 *    char* output_filepath - caminho do arquivo de testes
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
        std::cerr << "Usage: " << argv[0] << " <output-filepath> [n] [f] [ascending (t/f)] [random (t/f)]" << std::endl;
        return -1;
    }

    size_t n = argc >= 3 ? std::stoll(argv[2]) : 10000;
    float f = argc >= 4 ? std::stof(argv[3]) : 0.0;
    bool ascending = argc >= 5 ? std::string(argv[4]) == "t" : true;
    bool random = argc >= 6 ? std::string(argv[5]) == "t" : true;

    std::cout << "Parâmetros da execuçao:" << std::endl
              << "  número de elementos: " << n << std::endl
              << "  % de aleatórios: " << (f * 100.0) << "%" << std::endl
              << "  ordenação: " << ascending << std::endl
              << "  aleatório: " << random << std::endl;

    std::vector<int> testset = generate_set(n, f, ascending, random);

    std::ofstream out_file(argv[1], std::ofstream::binary);
    serialize_vector(testset, out_file);

    for (int v : testset) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    return 0;
}
