p1: ./src/main.cpp ./src/testset.hpp $(wildcard src/algo/*.hpp)
	$(CXX) -O3 --std=c++17 ./src/main.cpp -o ./p1