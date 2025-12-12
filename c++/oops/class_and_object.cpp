#include <iostream>
using namespace std;
// syntax:
// class ClassName{
    // Access specifiers
    // attributes or properties [Data member]
    // Behaviour or method [Member function]
// };

// ClassName obj1, obj2..,objn;


class Person{
    public:
    string name;
    int age;
    
    void info(){
        cout<<"My Name is : "<<name<<endl;
        cout<<"My Age is : "<<age<<endl;
    }
};

int main() {
    Person p1;
    p1.name = "Brijesh";
    p1.age = 29;
    
    // cout<<p1.name<<endl;
    // cout<<p1.age;
    p1.info();
    return 0;
}