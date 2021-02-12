#include <iostream>
#include <string>
#include <iomanip>

/***************************************************************************
Emanuel Dobra   
Lab 03  
Hotel Resort Guest Logger
***************************************************************************/

void displayEndingMsg();
char getValidRoomType();
double determineRate(char);

int main()
{
    std::string guestName;
    char roomType;
    double roomRate;
    std::cout << "Enter the guest's name: ";
    std::getline(std::cin, guestName);
    roomType = getValidRoomType();
    roomRate = determineRate(roomType);

    std::cout << std::right << std::setw(40) << "CPA Resort Hotel Room Charge\n"
        << std::right << std::setw(36) << "********************\n"
        << std::left << std::setw(20) << "Guest Name"
        << std::left << std::setw(20) << "Room Type"
        << std::right << std::setw(20) << "Room Charge\n\n";
    
    std::cout << std::left << std::setw(20) << guestName
        << std::left << std::setw(20) << roomType
        << std::right << std::setw(18) << roomRate << std::endl;
    
    displayEndingMsg();
    system("pause");
}

void displayEndingMsg() {
    std::cout << "\nProgram has ended successfully.\n";
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

double determineRate(char roomType) {
    double roomRate;
    int daysAmount;
    std::cout << "Enter the amount of days the guest stayed: ";
    std::cin >> daysAmount;
    switch (roomType) {
    case 'G':
        roomRate = 125.00;
        break;
    case 'P':
        roomRate = 145.00;
        break;
    case 'L':
        roomRate = 180.00;
        break;
    default:
        std::cout << "Undefined room type";
    }
    return roomRate*daysAmount;
}