#include <iostream>

using namespace std;

class BalanceSheet{
    public:
    int value;
    int get() const;
    void initialise();
};

void BalanceSheet::initialise(){
    value = 10;
}
int BalanceSheet::get() const{
    return value;
}
int getValue(const BalanceSheet*sheet) {
    return sheet->get();
}
int main(){
    BalanceSheet*newSheet = new BalanceSheet;
    newSheet->initialise();
    cout << getValue(newSheet);
};