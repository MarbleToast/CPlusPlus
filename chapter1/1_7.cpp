#include <iostream>

int main() {
    /*
        Nested multi-line comments
        /**\
        do not compile.
    */
    int x = 5, y = 10;
    std::cout   << "The sum of " << x
                << " and " << y
                << " is " << x+y 
                << std::endl;
    return 0;
}