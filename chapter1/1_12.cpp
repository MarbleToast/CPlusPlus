#include <iostream>

int main() {
    int sum = 0;
    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;

    // Outputs 0; adds -100 through 100, which cancels out.
}