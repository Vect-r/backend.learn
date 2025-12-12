#include<iostream>
using namespace std;

class Vehical{
    int speed;
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
    int speed = 10;
    public:
    void VehicalName() {
        cout<<"I am Car"<<endl;
    }

    int getSpeed(){
        return speed;
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


--------------------------

#include <iostream>
using namespace std;

class Math {
public:
    int num;

    // Constructor with default value = 0
    Math(int n = 0) {
        num = n;
    }

    // Operator overloading
    Math operator + (Math o) {
        return Math(this->num + o.num);
    }

    void show() {
        cout << "Operator overload: " << this->num;
    }
};

int main() {
    Math obj1, obj2;  // num = 0 automatically

    obj1.num = 10;
    obj2.num = 20;

    Math obj3 = obj1 + obj2;

    obj3.show();   // Output: 30

    return 0;
}
