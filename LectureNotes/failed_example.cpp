#include <string>
#include <iostream>
#include <ctime>

void printWinner(char, char);
char getUserInput();
// Scraps from a lecture example
int main() {
    srand(std::time(NULL));

    std::cout << "Enter rps: ";
    std::string userChoiceStr;
    std::getline(std::cin, userChoiceStr);
    char userChoice = userChoiceStr[0], computerChoice = 'r';

    // rand between 0 and 2
    int choice = rand() % 3;
    switch(choice) {
        case 1: 
            computerChoice = 'p';
            break;
        case 2:
            computerChoice = 's';
            break;
    }

    printWinner(userChoice, computerChoice);

}

char getUserInput() {
    std::string userChoiceStr;
    std::getline(std::cin, userChoiceStr);

    while(userChoiceStr.length() != 1 ||
        (userChoiceStr[0] != 'r') &&
        (userChoiceStr[0] != 'p') &&
        (userChoiceStr[0] != 's')) {    
            break; //...
    }
}
void printWinner(char userChoice, char computerChoice) {
    std::string winner = "Player";

    if(userChoice == computerChoice) {
        winner = "Tie";
    } else if(userChoice == 'r' && computerChoice == 's') {
        winner = "Player";
    } else if(userChoice == 's' && computerChoice == 'r') {
        winner = "Computer";
    } else if(userChoice == 'p' && computerChoice == 'r') {
        winner = "Player";
    } else if(userChoice == 'r' && computerChoice == 'p') {
        winner = "Computer";
    } 
}