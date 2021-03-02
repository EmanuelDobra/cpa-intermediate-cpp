/* Name: Emanuel Dobra
The following program manages yearly 
subscriptions for a magazine distributor */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

const int SIZE = 10;

int loadArrays(string[], double[]);
double findHighest(double[]);
void printMagazines(string[], double[], int);
int addMagazine(string[], double[], int);
double validatePrice(double price);
int removeMagazine(string[], double[], int);




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
    int length;
    ifstream myFile("magazine.dat");

    for (length = 0; length < SIZE; length++) {
        // store magazine name
        getline(myFile, names[length]);
        // if eof print number of records and break out
        if (myFile.eof()) {
            break;
        }
        // store price and ignore enter
        myFile >> prices[length];
        myFile.ignore(80, '\n');
        // print current magazine info
        // cout << "Magazine: " << names[length] << ", Price: " << prices[length] << endl;
    }
    return length;
}

// return subscript of the highest price
double findHighest(double prices[]) {
    double highestPrice = 0;
    int highestPriceIndex;

    for (int index = 0; index < SIZE; index++) {
        if (prices[index] > highestPrice) {
            // store highest price and it's index
            highestPrice = prices[index];
            highestPriceIndex = index;
        }
    }
    return highestPrice;
}

// Print magazines info
void printMagazines(string names[], double prices[], int noMagazines) {
    double highestPrice = findHighest(prices);
    cout << left << setw(15) << "\nName " << right << setw(33) << "Price \n\n";
    for (int index = 0; index < noMagazines; index++) {
        cout << left << setw(15) << names[index]
            << right << setw(30) << prices[index];
        if (prices[index] == highestPrice)
            cout << right << setw(25) << "** highest price ** \n";
        else
            cout << endl;
    }
	cout << "Number of magazines: " << noMagazines;
}

/* Write a function called addMagazine() that will add a new magazine to the arrays,
- maintaining the ascending order by name [????]
- Ensure the array is not overfilled. [DONE]
- Do not add a magazine that already exists [DONE]
- Display an appropriate error message and don’t allow the user to reenter another magazine if it already exists. [DONE]
- Ask the user to enter the name of the magazine and price [DONE]
- Search the array for the appropriate insertion point in the arrays [????]
- Return the updated number of magazines  [DONE]
- Call the validatePrice function to validate the price. No validation is required for the magazine name [DONE]*/
int addMagazine(string names[], double prices[], int noMagazines) {
    if (noMagazines == SIZE) {
        cout << "Array is already at max capacity." << endl;
        return noMagazines;
    }
    else {
        string magName;
        double magPrice;
        cout << "Please enter the name of the magazine to add: ";
        getline(cin, magName);
        if (true) { // find(0, SIZE, magName) <-- doesn't work
            cout << "Error: Magazine with this name already exists." << endl;
            return noMagazines;
        }
        else {
            cout << "Please enter the price of the magazine: ";
            cin >> magPrice;
            validatePrice(magPrice);
            // Add magazine at correct index (WIP)
            names[noMagazines++] = magName;
            prices[noMagazines++] = magPrice;
            return noMagazines++;
        }
    }
}

// validate price
double validatePrice(double price) {
    while (price <= 0 || price > 999 || cin.fail()) {
        cout << "Invalid price (1-999), please re-enter: ";
        cin >> price;
    }
    return price;
}

/*
Write a function called removeMagazine() that will remove a magazine from the arrays. 
- Ask the user for the name of the magazine [DONE]
- Search the array to find the magazine to remove. [????]
- Print a user friendly message if the magazine is not found. [DONE]
- Bump the remaining elements up. Return the updated number of magazines. [????]
*/
int removeMagazine(string names[], double prices[], int noMagazines) {
	string magName;
    cout << "Please enter the name of the magazine to remove: ";
    getline(cin, magName);
	if (true) { // !find(0, SIZE, magName) <-- doesn't work
		cout << "Error: Magazine with this does not exist." << endl;
		return noMagazines;
	} else {
		// Idk yet
		return noMagazines--;
	}
}



