#include <iostream>
#include <conio.h>   // Required for _getch() and _kbhit()
#include <vector>
#include <string>
#include <ncurses.h>

// Define key codes for clarity
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r' // Carriage return character

void displayMenu(const std::vector<std::string>& options, int selectedIndex) {
    // Clear screen (platform-specific, system("cls") works on Windows)
    system("cls");

    std::cout << "Select an option using arrow keys:" << std::endl << std::endl;

    for (size_t i = 0; i < options.size(); ++i) {
        if (i == selectedIndex) {
            // Highlight the selected option (e.g., using an arrow)
            std::cout << " -> " << options[i] << std::endl;
        } else {
            std::cout << "    " << options[i] << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> menuOptions = {"Option 1", "Option 2", "Option 3", "Exit"};
    int selectedIndex = 0;
    bool selecting = true;
    char key;

    while (selecting) {
        displayMenu(menuOptions, selectedIndex);

        key = _getch(); // Get the first character of the keypress

        if (key == (char)224 || key == (char)0) {
            // If it's an extended key (like an arrow key)
            key = _getch(); // Get the second character for the specific key

            switch (key) {
                case KEY_UP:
                    if (selectedIndex > 0) {
                        selectedIndex--;
                    } else {
                        selectedIndex = menuOptions.size() - 1; // Wrap around to bottom
                    }
                    break;
                case KEY_DOWN:
                    if (selectedIndex < menuOptions.size() - 1) {
                        selectedIndex++;
                    } else {
                        selectedIndex = 0; // Wrap around to top
                    }
                    break;
            }
        } else if (key == KEY_ENTER) {
            // Enter key was pressed, stop selecting
            selecting = false;
        }
    }

    system("cls");
    std::cout << "You selected: " << menuOptions[selectedIndex] << std::endl;

    // Perform action based on selectedIndex
    // e.g., if (selectedIndex == 3) { return 0; }

    return 0;
}
