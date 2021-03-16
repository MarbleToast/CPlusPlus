#include <iostream>

int main() {
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" /* "/*" */;

    // This final statement will not compile.
    // std::cout << /* "*/" */;
    return 0;
}