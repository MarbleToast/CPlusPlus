#include <iostream>
using namespace std;

class Student{
    public:
    int id;
    Student(int n){
        id = n;
    }
};

class Fresher : public Student{
    public:
    Fresher():Student(1){
        marks = 70;
    }int marks;
    private:
    
};

int main() {
    Fresher Tom;
    cout << Tom.id <<" receives " << Tom.marks <<".\n";
}