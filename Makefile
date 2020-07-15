p1: ./src/main.cpp ./src/testset.hpp ./src/graph.hpp $(wildcard src/algo/*.hpp)
	$(CXX) -O3 --std=c++17 ./src/main.cpp -o ./p1

generate_set: ./src/generate_set.cpp ./src/testset.hpp
	$(CXX) -O3 --std=c++17 ./src/generate_set.cpp -o ./generate_set