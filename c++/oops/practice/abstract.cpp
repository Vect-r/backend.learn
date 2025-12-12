#include <iostream>

// Abstract Base Class
class Shape {
public:
    // Pure virtual function (makes the class abstract)
    // Subclasses *must* implement this.
    virtual double calculateArea() = 0;

    void displayMessage() {
        std::cout << "This is a shape." << std::endl;
    }
};

// Concrete Class
class Circle : public Shape {
private:
    double radius;
    double diameter;
public:
    Circle(double r) : radius(r), diameter(r*2){}

    // Implementation details are hidden from the user who just calls calculateArea()
    double calculateArea() {
        return 3.14159 * radius * radius;
    }

    double getDiameter(){
        return diameter;
    }
};

int main() {
    // Shape s; // Error: Cannot instantiate abstract class
    Circle c(5.0);

    // User only knows calculateArea() exists and returns the area.
    // They don't know the exact formula (the implementation detail).
    std::cout << "Area of Circle: " << c.calculateArea() << std::endl;
    std::cout << "Diameter of Circle: " << c.getDiameter() << std::endl;
    c.displayMessage();

    return 0;
}
