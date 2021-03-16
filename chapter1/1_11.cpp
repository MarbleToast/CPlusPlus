#include <iostream>

int main() {
    int a, b = 0;
    std::cout << "Enter two numbers to see all numbers in their range (inclusive):" << std::endl;
    std::cin >> a >> b;
    while (a <= b) {
        std::cout << a++ << std::endl;
    }
    return 0;
}