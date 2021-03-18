#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Emanuel Dobra

const int SIZE = 10;

int loadArrays(string[], double[]);
void printMagazines(string[], double[], int);
int removeMagazine(string[], double[], int);


int main()
{
    string names[SIZE];
    double prices[SIZE];
    int arrLength = loadArrays(names, prices);
    
    cout << "Array before removal:\n";
    cout << "Arrays Length: " << arrLength << endl;
    printMagazines(names, prices, arrLength);

    cout << "\nArray after removal of first element:\n";
    arrLength = removeMagazine(names, prices, arrLength);
    cout << "Arrays Length: " << arrLength << endl;
    printMagazines(names, prices, arrLength);
}

int loadArrays(string names[], double prices[]) {
    int length;
    ifstream myFile("magazine.dat");
    if (!myFile.is_open()) {
        cout << "error opening file";
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

// Remove first magazine and price from arrays
int removeMagazine(string names[], double prices[], int noMagazines) {
    if (noMagazines == 0) {
        cout << "Array is empty, there is nothing to remove!\n";
        return noMagazines;
    }
    else {
        for (int index = 0; index < noMagazines; index++) {
            names[index] = names[index+1];
            prices[index] = prices[index+1];
        }
        return --noMagazines;
    }
}

/* Output:
Array before removal:
Arrays Length: 8
Name: Flare, Price: 33.5
Name: Whig Standard, Price: 124.96
Name: Macleans, Price: 12.75
Name: Uber, Price: 95.21
Name: Vaas, Price: 135.41
Name: Valt, Price: 57.23
Name: Xert, Price: 52.32
Name: Zeno, Price: 122.93

Array after removal of first element:
Arrays Length: 7
Name: Whig Standard, Price: 124.96
Name: Macleans, Price: 12.75
Name: Uber, Price: 95.21
Name: Vaas, Price: 135.41
Name: Valt, Price: 57.23
Name: Xert, Price: 52.32
Name: Zeno, Price: 122.93
*/