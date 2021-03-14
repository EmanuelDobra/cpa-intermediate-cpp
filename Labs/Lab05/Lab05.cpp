#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Emanuel Dobra

const int SIZE = 10;

int loadArrays(string[], double[]);
void printMagazines(string[], double[], int);


int main()
{
    string names[SIZE];
    double prices[SIZE];
    int arrLength = loadArrays(names, prices);
    cout << "Arrays Length: " << loadArrays(names, prices) << endl;
    printMagazines(names, prices, arrLength);
}

int loadArrays(string names[], double prices[]) {
    int length;
    ifstream myFile("magazine.dat");
    if (!myFile.is_open()) {
        std::cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (length = 0; length < SIZE; length++) {
        getline(myFile, names[length]);
        if (myFile.eof()) {
            break;
        }
        myFile >> prices[length];
        myFile.ignore(80, '\n');
    }
    return length;
}

// Print magazines info
void printMagazines(string names[], double prices[], int noMagazines) {
    for (int index = 0; index < noMagazines; index++) {
        cout << "Name: " << names[index] << ", "
            << "Price: " << prices[index] << endl;
    }
}