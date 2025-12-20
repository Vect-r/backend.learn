#include <iostream>
#include <string>
#include <conio.h> // Non-standard, Windows-specific

int main() {
    std::string password;
    char ch;
    std::cout << "Enter password: ";

    while ((ch = _getch()) != 13) { // 13 is the ASCII code for Carriage Return (Enter)
        if (ch == 8) { // Handle backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Move back, overwrite with space, move back again
            }
        } else {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << "\nPassword received." << std::endl;
    return 0;
}
