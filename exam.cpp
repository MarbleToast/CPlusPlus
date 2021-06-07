#include <iostream>
using namespace std;
int main(int argc, const char*argv[]) {
    // A base class
    class BaseClass{
        int classID;
        public:
        BaseClass(int id):classID(id){}; 
        //Question i
        int getID(){return classID;}
    };

    class DerivedClass : BaseClass{
        public:
        DerivedClass(int id):classID(id){};
         // Question ii
        int getDerivedID(){return getID();} 
        // Question iii20
    };


    struct BaseStruct{
        int getID(){return structID;}
        BaseStruct(int id):structID(id){};
        private:
        int structID;
        };
    struct DerivedStruct : BaseStruct{
        DerivedStruct(int id):BaseStruct(id){};
            //Question iv34
    };
        // Create one class instance and one struct instance
        DerivedClass classInstance(1);
        DerivedStruct structInstance(2);
        cout<<"Print the derived class ID: "<<classInstance.getDerivedID()<<endl;
        cout<<"Print the derived struct ID: "<<structInstance.getID() //Question v44
        <<endl;
        return 0;
        }