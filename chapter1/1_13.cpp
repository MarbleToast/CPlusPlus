#include <iostream>

int main() {
    for (int a = 10; a >= 0; a--) {
        std::cout << a-- << std::endl;
    }

    int a, b = 0;
    std::cout << "Enter two numbers to see all numbers in their range (inclusive):" << std::endl;
    std::cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
        std::cout << i << std::endl;
    }
    
    return 0;
}