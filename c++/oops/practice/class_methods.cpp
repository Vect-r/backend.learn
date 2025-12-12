#include <iostream>
using namespace std;

class Car{
    int maxSpeed;
    public:
        string name;
        void setMaxSpeed(int speed);
        void info();
};

void Car::setMaxSpeed(int speed){
    maxSpeed = speed;
}

void Car::info(){
    cout<<"Car: "<<name<<"; "<<"Max Speed: "<<maxSpeed<<endl;
}

int main(){
    Car car1;
    car1.name = "Volvo XC90";
    car1.setMaxSpeed(200);
    car1.info();
}
