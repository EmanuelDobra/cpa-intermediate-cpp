#include <iostream>
#include <string>

/***************************************************************************
Emanuel Dobra   
Lab 1 (but it's the 2nd lab) 
***************************************************************************/

void displayEndingMsg();
char getValidRoomType();

int main()
{
    std::string guestName;
    char roomType;
    std::cout << "Welcome to the CPA Resort Hotel" << std::endl;
    // add 31 char(240) characters (≡ x 31)
    std::cout << std::string (31, char(240)) << std::endl; 
    std::cout << "What is your name? ";
    std::getline(std::cin, guestName);
    getValidRoomType();
    switch(roomType) {
        case 'G':
            std::cout << "You have chosen: Garden View\n";
            break;
        case 'P':
            std::cout << "You have chosen: Pool View\n";
            break;
        case 'L':
            std::cout << "You have chosen: Lake View\n";
            break;
        default:
            std::cout << "Unknown room type\n"; 
    }
    displayEndingMsg();
    system("pause");
}

/**
 * Display a program ended message
*/
void displayEndingMsg() {
    std::cout << "\nProgram has ended successfully.\n";
}

/**
 * Get and validate user inputed room type
 * @return the valid room type
*/
char getValidRoomType() {
    char roomType; 
    std::cout << "Enter your room type (G/P/L): ";
    std::cin >> roomType;
    roomType = toupper(roomType);
    while ((roomType != 'G' && roomType != 'P' && roomType != 'L') || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "Wrong input, enter G P or L: ";
        std::cin >> roomType;
    }
    return roomType;
}


char getValidRoomType() {
    char roomType;
    std::cout << "Enter your room type (G/P/L): ";
    std::cin >> roomType;
    roomType = toupper(roomType);
    while ((roomType != 'G' && roomType != 'P' && roomType != 'L') || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "Invalid retry: " << std::endl;
        std::cin >> roomType;
        roomType = toupper(roomType);
    }
    return roomType;
}

/* Output
Welcome to the CPA Resort Hotel
≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
What is your name? Test
Enter your room type (G/P/L): r
Wrong input, enter G P or L: U
Wrong input, enter G P or L: g
You have chosen: Garden View

Program has ended successfully.
Press any key to continue . . .
*/