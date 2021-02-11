#include <iostream>

//Exercise#2   Name: Emanuel Dobra
double determineRate();
void printRate(double);

int main()
{
    double roomRate;
    
    roomRate = determineRate();
    printRate(roomRate);

    system("pause");	
}

double determineRate() {
    char roomType;
    double roomRate;
    std::cout << "Enter the guest's room type (G/P/L): ";
    std::cin >> roomType;
    roomType = toupper(roomType);
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
    return roomRate;
}

void printRate(double roomRate) {
    std::cout << "Room rate: " << roomRate << std::endl;
}