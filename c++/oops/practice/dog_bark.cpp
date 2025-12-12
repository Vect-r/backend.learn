#include <iostream>
using namespace std;

class Dog{
public:
    string name;
    void bark();
};

void Dog::bark(){
    cout<<name<<": Woof";
}

int main(){
    Dog d1;
    d1.name="Rocco";
    d1.bark();
}
