#include <iostream>

int main() {
    /*
        The code fragment:
            std::cout << "The sum of " << v1;
                      << " and " << v2;
                      << ... etc.
        is not legal, as the output operator has no ostream object
        to output the operands to, as the semicolon on the first
        line terminate the statement. To fix this, removing all
        semicolons before the last will make the statement legal.
    */
    int x = 5, y = 10;
    std::cout   << "The sum of " << x
                << " and " << y
                << " is " << x+y 
                << std::endl;
}