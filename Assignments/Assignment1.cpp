#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

/**
 * Due Feb19 2021. 
*/

/***************************************************************************
Emanuel Dobra   
Assignment 1
Generates a report file for hotel guests.
***************************************************************************/

// Prototypes
char getValidRoomType();
double determineRate(char);
int getValidDays();
bool validateReply(std::string);
double computeRoomCharge(char, int, bool);

int main() {
    std::string guestName;
    char roomType;
    int daysAmount;
    bool extraBed, enterGuest;
    double roomCharges, totalCharges = 0;
    std::string roomTypeOutput; 
    // Open output file
    std::ofstream fout("charges.txt");
    if (!fout.is_open()) {
        std::cout << "error opening file";
        system("pause");
        exit(-1);
    }
    // Write title to file
    fout << std::fixed << std::setprecision(2);
    fout << std::left << std::setw(40) << "CPA Resort Hotel Room Charge\n"
        << std::left << std::setw(50) << "****************\n"
        << std::right << std::setw(15) << "Guest Name" 
        << std::right << std::setw(15) << "Room Type"
        << std::left << std::setw(20) << "Room Charge\n\n";
    do {
        std::cout << "Enter the guest's name: ";
        std::cin >> guestName; 
        // Get room type
        roomType = getValidRoomType();
        // Set room type output
        switch(roomType) {
            case 'G':
                roomTypeOutput = "Garden View";
                break;
            case 'P':
                roomTypeOutput = "Pool View";
                break;
            case 'L':
                roomTypeOutput = "Lake View";
                break;
            default:
                std::cout << "Unknown room type\n"; 
        }
        // Get total days
        daysAmount = getValidDays();
        // Check if user asked for an extra bed
        extraBed = validateReply("Did the guest ask for an extra bed? Answer yes/no: ");
        // Calculate total charge
        roomCharges = computeRoomCharge(roomType, daysAmount, extraBed);
        totalCharges += roomCharges;
        // Output entry to file
        fout << std::right << std::setw(15) << guestName 
            << std::right << std::setw(15) << roomTypeOutput
            << std::left << std::setw(20) << roomCharges << std::endl;
        // Ask for next entry
        enterGuest = validateReply("Do you want to enter another guest? Answer yes/no: ");
    } while (enterGuest);

    fout << std::right << std::setw(30) << "Total Charges: " 
        << std::left << std::setw(20) << totalCharges << std::endl;

    system("type charges.txt");
    system("pause");
}

/**
 * Get and validate user inputed room type
 * @return the valid room type
*/
char getValidRoomType() {
    char roomType; 
    std::cout << "Enter the guest's room type (G/P/L): ";
    std::cin >> roomType;
    roomType = toupper(roomType);
    while ((roomType != 'G' && roomType != 'P' && roomType != 'L') || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "Wrong input, enter G P or L: ";
        std::cin >> roomType;
        roomType = toupper(roomType);
    } 
    return roomType;
}

/**
 * Get the room rate based on the room type
 * @param roomType the type of room
 * @return the room rate 
*/
double determineRate(char roomType) {
    double roomRate;
    switch(roomType) {
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
    return roomRate;
}

/**
 * Ask user to input the amount of days the guest will rest
 * @return the amount of days guest stayed
*/
int getValidDays() {
    int daysAmount;
    std::cout << "Enter the amount of days the guest stayed: ";
    std::cin >> daysAmount;
    while (daysAmount < 0 || daysAmount > 31 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "Wrong input, enter a number between 0 and 31: ";
        std::cin >> daysAmount;
    } 
    return daysAmount;
}

/**
 * Ask for the user's answer to a yes/no question
 * @param message message to show the user
 * @return the user's answer as a boolean
*/
bool validateReply(std::string message) {
    std::string answer;
    std::cout << message;
    std::getline(std::cin, answer);
    while ((answer != "yes" && answer != "no") || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(80,'\n');
        std::cout << "Inavlid input, enter yes or no: ";
        std::getline(std::cin, answer);
    }
    if (answer == "yes") 
        return true;
    else 
        return false;
}

/**
 * Compute the total room charge of the guest
 * @param roomType the room type of the guest
 * @param restDays total days guest stayed
 * @param extraBed whether or not the guest wanted an extra bed
 * @return 
*/
double computeRoomCharge(char roomType, int restDays, bool extraBed) {
    double roomRate;
    roomRate = determineRate(roomType);
    if (extraBed) {
        switch (roomType) {
            case 'L':
                roomRate += 20;
                break;
            default:
                roomRate += 15;
        }
    }
    return (roomRate * restDays);
}