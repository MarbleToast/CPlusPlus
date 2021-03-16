#include <iostream>

int main() {
    int a = 0, c = 50;
    while (c <= 100) {
        a += c;
        c++;
    }
    std::cout << a << std::endl;
    return 0;
}