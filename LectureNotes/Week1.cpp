#include <string>
#include <iostream>

/***************************************************************************
your name
Assignment # ?
Short narrative stating the purpose of the program
***************************************************************************/
int main() {
    int test = 0;
    do {
        std::cout << test << "\n";
        test++;
    } while (test < 10);

    std::cout << "used std::";

    switch(test) {
        case 1: 
            std::cout << "One";
        case 2:
            std::cout << "Two";
        case 3:
            std::cout << "Three";
        default:
            std::cout << "Try Again!";
    }

    displayMessage("Test");
}

/**
 * Displays a message with an endline added at the end
 * @param message The message to be displayed
*/
void displayMessage(std::string message) {
    std::cout << message << "\n";
}

/**
    Returns the area of a circle with the specified radius.
    @param radius The radius of the circle.
    @return The area of the circle.
*/
double area(double radius);