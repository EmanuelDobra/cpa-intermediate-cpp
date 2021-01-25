#include <iostream>
#include <string>

/**
 * E1 fn
*/
void function2(int, std::string, double, char); // Protoype -- definition 

void function2(int var1, std::string test, double num, char z) { // Formal parameters -- describing params
    std::cout << "before fn2: " << var1;
    var1 = 22;
    std::cout << "function2: " << var1;
}



/**
 * E2 namespaces 
*/
namespace namespace1 {
    int namespace1Var = 1;

    bool isValid(std::string user, std::string pass) {
        return false;
    }

    // Function overloading, using diff params
    bool isValid(std::string user, std::string pass, int num) {
        return false;
    }
}

namespace namespace2 {
    bool isValid(std::string user, std::string pass) {
        return true;
    }

    int globalVar = 99;
}

// global variable example
int globalVar = 15;

using namespace namespace1;
using namespace namespace2; 

int main() {
    /**
     * E1 main
    */
    int var1 = 5;
    std::cout << "Main: " << var1; 
    std::string test = "teststring";
    char z = 'c';
    double num = 5.0;
    // Actual parameters -- data being passed
    function2(var1, test, num, z); // no pointer passed, local variables not affected by function calling
    std::cout << "Main After: " << var1;

    /**
     * E2 main
    */ 
    // isValid("test", "test"); // fails due to abiguous functions
    // Specifiying namespace works
    namespace1::isValid("test", "test");
    namespace2::isValid("test", "test");
    isValid("test", "test", 15); // succeds due to overloading 
    int globalVar = 2;
    std::cout << ::globalVar; // prints 15 from global vatiable globalVar
    std::cout << globalVar; // prints 2 from local variable globalVar
    std::cout << namespace2::globalVar; // prints 99 from namepsace2 local variable globalVar
 }

