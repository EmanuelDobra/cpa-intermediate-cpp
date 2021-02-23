/* Name: Emanuel Dobra
The following program manages yearly 
subscriptions for a magazine distributor */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// 
#include <sstream>

const int SIZE = 10;

void printMagazines(string[], double[], int);
int removeMagazine(string[], double[], int);
int loadArrays(string[], double[]);
int addMagazine(string[], double[], int);

/*
 * Use the following main() for your 2nd assignment.
 * This code will replace your main()
 * Do not make any changes to this code!
 * You will need to add the required header files.
 *
 * Add your name and a short narrative explaining the purpose of the program.
 * Add a global constant called SIZE to represent the maximum number of magazines for use in your functions.
 *
 * Follow the instructions below when adding and deleting magazines.
 * */

int main()
{
	string name[SIZE];
	double price[SIZE];
	int noMagazines = 0;

	cout << "\nDelete an empty list:\n\n" << endl;
	printMagazines(name, price, noMagazines);
	noMagazines = removeMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nInitial array load:\n\n" << endl;
	noMagazines = loadArrays(name, price);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nAdd a new magazine:\n\n" << endl;
	noMagazines = addMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nAdd the same magazine:\n\n" << endl;
	noMagazines = addMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nAdd a magazine to the beginning of the array:\n\n" << endl;
	noMagazines = addMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nAdd a magazine to the end of the array:\n\n" << endl;
	noMagazines = addMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nAdd a magazine to middle of array:\n\n" << endl;
	noMagazines = addMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nDelete a magazine from start of array:\n\n" << endl;
	noMagazines = removeMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nDelete the same magazine\n\n" << endl;
	noMagazines = removeMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nDelete a magazine from middle of array:\n\n" << endl;
	noMagazines = removeMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nDelete a magazine from the end of the array:\n\n" << endl;
	noMagazines = removeMagazine(name, price, noMagazines);
	printMagazines(name, price, noMagazines);
	cout << "# magazines = " << noMagazines << endl;
	cout << "\nProgram ended successfully" << endl;
	system("type magazines.dat");
	system("pause");

}

int loadArrays(string names[], double prices[]) {
	// read from file and store into arrays
	string textScan;
	int noOfLines;
	ifstream readFile("magazines.dat");
	
	// ignore first line
	getline(readFile, textScan);
	//readFile >> textScan;

	while (!readFile.eof()) {
		for (int index = 0; index < SIZE; index++) {
			getline(readFile, names[index], ',');

		}
	}


	for (int line = 0; line < SIZE; line++) {
		if (!readFile.eof()) {

			//readFile >> textScan;
			//names[line] = textScan;
		}
	}
	

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(readFile, textScan)) {
		// Output the text from the file
		cout << textScan;
	}

	// close file
	readFile.close();
}

int addMagazine(string[], double[], int);
void printMagazines(string[], double[], int);
int removeMagazine(string[], double[], int);