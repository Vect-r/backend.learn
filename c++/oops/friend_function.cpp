#include <iostream>
using namespace std;

class Math {
private:
    int num;

public:
    Math(int n) {
        num = n;
    }

    // Declaring friend function
    friend void showData(Math);
};

void showData(Math m) {
    cout << "Value: " << m.num << endl; // accessing private data
}

int main() {
    Math obj(10);
    showData(obj);

    return 0;
}
