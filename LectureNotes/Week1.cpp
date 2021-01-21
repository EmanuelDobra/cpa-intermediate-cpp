#include <string>
#include <iostream>

/***************************************************************************
your name
Assignment # ?
Short narrative stating the purpose of the program
Date: Jan19, Jan21
***************************************************************************/

// Prototypes example
void displayMessage(std::string);
double area(double);

int main() {
    int test = 0;
    // Do while loop example, do gets executed AT LEAST once.
    do {
        std::cout << test << "\n";
        test++;
    } while (test < 10);

    std::cout << "use std::"; // instead of using namespace std;

    // Switch example
    switch(test) {
        case 1: 
            std::cout << "One";
            break; // do not fall through to next case, break out
        case 2:
            std::cout << "Two";
            break;
        case 3:
            std::cout << "Three";
            break;
        default:
            std::cout << "Try Again!"; // has no need for a break
    }

    // for loop
    for (int i = 0; i < 5; i++) { 
        // if statement
        if(i == 3) {
            break;
        }
    }

    std::cout << "Enter r, p or s: ";


    // Calling functions 
    displayMessage("Test");
}

// Documentation example

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