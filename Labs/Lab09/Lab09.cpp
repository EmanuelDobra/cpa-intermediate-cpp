#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Emanuel Dobra

const int SIZE = 25;

int main()
{
    string bird[SIZE];
    int birdSightings;
    ifstream myFile("birds.dat");

    if (!myFile.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    ofstream outFile("birds.rpt");

    if (!outFile.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (int pos = 0; pos < SIZE; pos++) {
        getline(myFile, bird[pos]);

        if (myFile.eof()) 
            break;

        outFile << bird[pos] << "\t";

        for (int innerPos = 0; innerPos <3; innerPos++) {
            myFile >> birdSightings;
            outFile << birdSightings << "\t";
        }

        outFile << endl;
        myFile.ignore(80, '\n');
    }

    system("type birds.rpt");
}

/* Output
Blue Heron      25      50      4
Cardinal        25      0       25
King Fisher     3       44      0
Pink Flamingo   0       40      2
Baltimore Oriole        53      8       7
*/
