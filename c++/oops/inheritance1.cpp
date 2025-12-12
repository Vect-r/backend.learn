#include <iostream>
using namespace std;

class A{
    public:
        void a(){
            cout<<"This is A."<<endl;
        }
};

class B{
    public:
        void b(){
            cout<<"This is B."<<endl;
        }
};

class C: public A, public B{
    public:
        void override a(){
            cout<<"Hello"<<endl;
        }
        void c(){
            a();
            b();
            cout<<"This is C."<<endl;
        }
};


int main(){
    C obj;
    obj.c();
}
