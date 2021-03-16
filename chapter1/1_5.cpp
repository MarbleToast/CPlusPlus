#include <iostream>

int main() {
    int a, b = 0;
    std::cout << "Enter two numbers to see their product:" << std::endl;
    std::cin >> a >> b;
    std::cout << "The product of ";
    std::cout << a;
    std::cout << " and ";
    std::cout << b;
    std::cout << " is ";
    std::cout << a*b;
    std::cout << std::endl;
    return 0;
}