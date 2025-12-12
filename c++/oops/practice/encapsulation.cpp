#include <iostream>
using namespace std;

class Employee{
    int salary;

public:
    void setSalary(int salary){
        this->salary = salary;
    }
    int getSalary(){
        return salary;
    }
};

int main(){
    Employee p1;
    p1.setSalary(50000);
    cout<<p1.getSalary();
}
