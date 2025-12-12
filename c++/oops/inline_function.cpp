#include <iostream>
using namespace std;

// Function defined as inline
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 10); // Compiler replaces 'add(5, 10)' with 'return 5 + 10;'
    cout << "Result: " << result << endl;
    return 0;
}
