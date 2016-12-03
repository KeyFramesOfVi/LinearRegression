#include "../include/LinearRegression.hpp"

int main(int argc, const char * argv[]){
	if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    LinearRegression tester(argv[1]);
	return 0;
}


//clang++ -std=c++11 -stdlib=libc++ -I/opt/local/include/ -I/usr/local/include/eigen3 -L/opt/local/lib/ main.cpp LinearRegression.cpp Utils.cpp -o csvparser 
//g++ -std=c++0x `pkg-config --cflags eigen3` main.cpp LinearRegression.cpp Utils.cpp -o test