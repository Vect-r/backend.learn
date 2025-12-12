#include <iostream>
using namespace std;

class Car{
public:
    string brand;
    string model;

    Car(){
        brand = "?";
        model = "?";
    }

    Car(string brand,string model){
        this->brand = brand;
        this->model = model;
    }

    void info(){
        cout<<brand<<" "<<model<<endl;
    }
};

int main(){
    Car car1,car2("BMW", "X5");
    car1.info();
    car2.info();
}
