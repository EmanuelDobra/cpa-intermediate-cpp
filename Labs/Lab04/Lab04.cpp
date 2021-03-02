#include <iostream>
#include <string>
#include <fstream>

// Emanuel Dobra

int main()
{
    std::string magName;
    double price;
    int length;
    std::ifstream myFile("magazine.dat");
 
    for (length = 0; length < 5; length++) {
        // store magazine name
        getline(myFile, magName);
        // if eof print number of records and break out
        if (myFile.eof()) {
            std::cout << "\nNumber of records: " << length << std::endl;
            break;
        }
        // store price and ignore enter
        myFile >> price;;
        myFile.ignore(80, '\n');
        // print current magazine info
        std::cout << "Magazine: " << magName << ", Price: " << price << std::endl;
    }
}
