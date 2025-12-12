#include <iostream>
using namespace std;

class ATM {
private:
    int pin;

public:

    // Default constructor
    ATM() {
        pin = 0; 
    }

    // Parameterized constructor
    ATM(int p) {
        pin = p;
    }

    // Copy constructor
    ATM(const ATM &obj) {
        pin = obj.pin;
        cout << "Copy constructor called!" << endl;
    }

    void show() {
        cout << "Your Pin number is: " << pin << endl;
    }

    // Destructor
    ~ATM() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    ATM p1(1111);   // initializes PIN
    ATM p2 = p1;    // calls copy constructor

    p2.show();      // shows copied PIN

    return 0;
}
