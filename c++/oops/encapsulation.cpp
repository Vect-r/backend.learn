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
    string name;
    int age;
    
    public:
    void setData(int a, string n){
        name = n;
        age = a;
    }
    
    void getData(){
        cout<<"My Name is : "<<name<<endl;
        cout<<"My Age is : "<<age<<endl;
    }
    
};

int main() {
    Person p1;
    p1.setData(29, "Brijesh");
    p1.getData();
   
    return 0;
}