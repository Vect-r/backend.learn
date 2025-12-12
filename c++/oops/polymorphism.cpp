// // polymorphsm
//     - static binding. | compiletime
//         - function overloading
//         - operator overloading
//     - dynamic binding. | runtime 
//         - function overriding

#include <iostream>
using namespace std;

class Math{
    public:
    int add(int num1, int num2){
        return num1 + num2;
    }
    int add(int num1, int num2, int num3){
        return num1 + num2 + num3;
    }
};

int main() {
    Math obj;
    cout<<obj.add(10, 20, 30);
    return 0;
}


--------------------------------
#include <iostream>
using namespace std;

class Math{
    public:
    int num;
    
    Math operator + (Math o){
        Math temp;
        temp.num = this->num + o.num;
        return temp;
    }
    void show(){
        cout<<"Operator overload: "<<this->num;
    }
};

int main() {
    Math obj1, obj2;
    obj1.num = 10;
    obj2.num = 20;
    Math obj3 = obj1 + obj2;
    
    obj3.show();
   
    return 0;
}
-------------------------------------------
#include<iostream>
using namespace std;

class Vehical{
    public:
    virtual void VehicalName() = 0;
    void vehical(){
        cout<<"I am vehical"<<endl;
    }
};

class Truck: public Vehical{
    public:
    void VehicalName() {
        cout<<"I am Truck"<<endl;
    }
};
class Car: public Vehical{
    public:
    void VehicalName() {
        cout<<"I am Car"<<endl;
    }
};

int main(){
    
    Vehical* truck = new Truck();
    Vehical* car = new Car();
    
    truck->VehicalName();
    car->VehicalName();
    truck->vehical();
    car->vehical();
    
}