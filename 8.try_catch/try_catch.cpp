#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include <iostream>

void testFunction() {
    try {
        throw 100;  // Throwing an integer exception
    }
    catch (int e) {
        std::cout << "Caught in testFunction: " << e << std::endl;
        throw;  // Re-throw the exception
    }
}

int main() {
    string str("foo");

    try {
    str.at(10); // access element, may throw std::out_of_range
    } catch (const std::out_of_range& e) {
    // what() is inherited from std::exception and contains an explanatory message
    cout << e.what()<<endl;
    }
//---------------------------throw keyword use----------------------------------

    try {
        testFunction();
    }
    catch (int e) {
        std::cout << "Caught in main: " << e << std::endl;
    }

    return 0;
}