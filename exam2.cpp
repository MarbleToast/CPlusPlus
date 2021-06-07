#include <iostream>
using namespace std;


void getType(int a, int b) {
    cout << a << " and " << b << " are integers";
}
void getType(double a, double b) {
    cout << a << " and " << b << " are doubles";
}
int main(){
    const char* letter = "A";
    letter[0] = "a";
    cout <<*letter;
}

