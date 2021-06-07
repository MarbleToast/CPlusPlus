#include <iostream>

using namespace std;

class point {
    private:
        int x, y;
    public:
        point(){};
        void printPoint(){
            cout << x << ", " << y;
        }
};

class line : public point{
    private:
        point px, py;
    public:
        line(point pxx, point pyy) : px(pxx), py(pyy){};
        void printLine(){
            cout << px << py <<endl;
        }
};