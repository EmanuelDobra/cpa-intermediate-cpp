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
    bool extraBed, enterGuest = true;
    double totalCharge;
    std::string roomTypeOutput; 
    std::ofstream fout("charges.txt");
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
        totalCharge = computeRoomCharge(roomType, daysAmount, extraBed);
        // Output entry to file
        fout << std::right << std::setw(15) << guestName 
            << std::right << std::setw(15) << roomTypeOutput
            << std::left << std::setw(20) << totalCharge << std::endl;
        // Ask for next entry
        enterGuest = validateReply("Do you want to enter another guest? Answer yes/no: ");
    } while (enterGuest);

}

/**
 * Get and validate user inputed room type
 * @return the valid room type
*/
char getValidRoomType() {

}

/**
 * Get the room rate based on the room type
 * @param roomType the type of room
 * @return the room rate 
*/
double determineRate(char roomType) {

}

/**
 * Ask user to input the amount of days the guest will rest
 * @return the amount of days guest stayed
*/
int getValidDays() {

}

/**
 * Ask for the user's answer to a yes/no question
 * @param response message to show the user
 * @return the user's answer as a boolean
*/
bool validateReply(std::string message) {
    
}

/**
 * Compute the 
*/
double computeRoomCharge(char roomType, int restDays, bool extraBed) {

}