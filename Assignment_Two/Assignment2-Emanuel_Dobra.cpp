#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

/* Name: Emanuel
 * Date: 2021-04-02
 * Details: Program for a magazine distributor for the
 * managing of yearly subscriptions.  
*/

const int SIZE = 20;

void printMagazines(string[], double[], int);
int removeMagazine(string[], double[], int);
int loadArrays(string[], double[]);
int addMagazine(string[], double[], int);
double findHighest(double[]);
double validatePrice(double);

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
	system("type magazine.dat");
	system("pause");
}
/**
 * Load arrays from our magazine.dat file.
 *
 * @param names[] Array holding the magazine names.
 * @param prices[] Parallel array holding the magazines' prices.
 * @return length of the parallel arrays.
 */
int loadArrays(string names[], double prices[])
{
	// Open input file stream
	ifstream myFile("magazine.dat");

	// Check if successfully opened file
	if (!myFile.is_open()) {
		cout << "error opening file\n";
		system("pause");
		exit(-1);
	}
	
	// Variable to hold our total magazines added
	int count = 0;
	
	while (!myFile.eof())
	{
		// Loop through the file until array is filled or file ends
		for (int pos = 0; pos < SIZE; pos++)
		{
			if (myFile.eof())
			{
				break;
			}
			count += 1;
			// Add elements to array
			getline(myFile, names[pos]);
			myFile >> prices[pos];
			myFile.ignore(80, '\n');
		}
	}
	return count;
}

/**
 * Find highest subscription price of the magazines.
 *
 * @param prices[] Array holding the magazines' prices.
 * @return top subscription price.
 */
double findHighest(double prices[])
{
	double topPrice = 0;
	
	// Loop through prices array
	for (int index = 0; index < SIZE; index++)
	{
		// Assign top price 
		if (topPrice < prices[index])
		{
			topPrice = prices[index];
		}
	}
	return topPrice;
}

/**
 * Load arrays from our magazine.dat file.
 *
 * @param names[] Array holding the magazine names.
 * @param prices[] Parallel array holding the magazine's prices.
 * @param noMagazines Length of the parallel arrays.
 */
void printMagazines(string names[], double prices[], int noMagazines)
{
	cout << fixed << setprecision(2);

	// output titles
	cout << left << setw(25) << "Name"
		<< right << setw(27) << "Price\n\n";

	double topPrice = findHighest(prices);

	// Loop through array 
	for (int pos = 0; pos < noMagazines; pos++)
	{
		// Output magazines
		cout << left << setw(25) << names[pos];
		cout << right << setw(25) << prices[pos];

		// Output if top price 
		if (prices[pos] == topPrice)
			cout << right << setw(22) << "** highest price **";
		
		cout << endl;
	}
	// Output total magazines
	cout << "\nNumber of magazines = " << noMagazines << "\n\n";
}

/**
 * Add new magazine item to the arrays.
 *
 * @param names[] Array holding the magazine names.
 * @param prices[] Parallel array holding the magazine's prices.
 * @param noMagazines Length of the parallel arrays.
 * @return length of the parallel arrays.
 */
int addMagazine(string names[], double prices[], int noMagazines)
{
	
	// Magazine item, duplicate bool
	string name;
	double price;
	bool dupeMagazine = false;
	
	// Check if array is full
	if (noMagazines == SIZE)
		cout << "Error: Array is already full.\n\n";
	else
	{
		// Input magazine name 
		cout << "Enter the name of the magazine to add: ";
		getline(cin, name);
		// Turn first letter to uppercase to fit magazine listing
		name[0] = toupper(name[0]);		

		// Check for duplicate magazine
		for (int pos = 0; pos < noMagazines; pos++)
		{
			if (names[pos] == name)
			{
				cout << "Error: Magazine already exists\n\n";
				dupeMagazine = true;
				break;
			}
		}

		// If not duplicate
		if (!dupeMagazine)
		{
			// Take and validate price input
			cout << "Enter the price of the new magazine: ";
			cin >> price;
			cin.clear();
			cin.ignore(80, '\n');
			price = validatePrice(price);

			// Shift all items one position forward
			for (int pos = noMagazines; pos > 0; pos--) {
				names[pos] = names[pos - 1];
				prices[pos] = prices[pos - 1];
			}
			// Add new item to array
			names[0] = name;
			prices[0] = price;
			noMagazines += 1;

			// Store temporary items
			string tempName;
			double tempPrice;

			// Sort the new magazine in ascending order
			for (int pos = 0; pos < noMagazines - 1; pos++)
			{
				if (names[pos] > names[pos + 1])    
				{
					// Store item that will get overwritten
					tempName = names[pos + 1];
					tempPrice = prices[pos + 1];

					// Shift our new magazine forward
					names[pos + 1] = names[pos];
					prices[pos + 1] = prices[pos];

					// Replace the new magazine in the old position with the stored one
					names[pos] = tempName;
					prices[pos] = tempPrice;
				}
				// Break once sorting is done
				else
					break;
			}
		}
	}
	return noMagazines;
}

/**
 * Validate user price input.
 *
 * @param price Price input by the user.
 * @return a valid price.
 */
double validatePrice(double price)
{	
	// Validate if price within range
	while (price < 9 || price > 999 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error: Please enter a value between 9 and 999: ";
		cin >> price;
	}
	cout << endl;

	return price;
}

/**
 * Remove a magazine item from the arrays.
 *
 * @param names[] Array holding the magazine names.
 * @param prices[] Parallel array holding the magazine's prices.
 * @param noMagazines Length of the parallel arrays.
 * @return length of the parallel arrays.
 */
int removeMagazine(string names[], double prices[], int noMagazines)
{
	string name;
	bool removedMagazine = false;
	
	// Input name for removal
	cout << "Enter the name of the magazine to remove: ";
	getline(cin, name);
	// Turn first letter to uppercase to fit magazine listing
	name[0] = toupper(name[0]);
	cout << endl;

	// Loop through array to find removal item
	for (int pos = 0; pos < SIZE; pos++)
	{
		// If found, remove magazine
		if (names[pos] == name)
		{
			// Update count and bool
			noMagazines -= 1;
			removedMagazine = true;

			// Shift the rest of the items down 1
			for (int shift = pos; shift < noMagazines; shift++)
			{
				names[shift] = names[shift + 1];
				prices[shift] = prices[shift + 1];
			}
			break;
		}
	}
	
	// If removal failed, output error
	if (!removedMagazine)
		cout << "Error: Failed to remove - magazine not found.\n\n";

	return noMagazines;
}

/*Output

Delete an empty list:


Name                                         Price


Number of magazines = 0

Enter the name of the magazine to remove: test

Error: Failed to remove - magazine not found.

Name                                         Price


Number of magazines = 0

# magazines = 0

Initial array load:


Name                                         Price

Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Vaas                                        135.41   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93

Number of magazines = 8

# magazines = 8

Add a new magazine:


Enter the name of the magazine to add: Firework
Enter the price of the new magazine: 27.54

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Vaas                                        135.41   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93

Number of magazines = 9

# magazines = 9

Add the same magazine:


Enter the name of the magazine to add: Firework
Error: Magazine already exists

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Vaas                                        135.41   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93

Number of magazines = 9

# magazines = 9

Add a magazine to the beginning of the array:


Enter the name of the magazine to add: absolute
Enter the price of the new magazine: 88.49

Name                                         Price

Absolute                                     88.49
Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Vaas                                        135.41   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93

Number of magazines = 10

# magazines = 10

Add a magazine to the end of the array:


Enter the name of the magazine to add: Zoner
Enter the price of the new magazine: 132.99

Name                                         Price

Absolute                                     88.49
Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Vaas                                        135.41   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93
Zoner                                       132.99

Number of magazines = 11

# magazines = 11

Add a magazine to middle of array:


Enter the name of the magazine to add: Uzbeck
Enter the price of the new magazine: 212.42

Name                                         Price

Absolute                                     88.49
Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Uzbeck                                      212.42   ** highest price **
Vaas                                        135.41
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93
Zoner                                       132.99

Number of magazines = 12

# magazines = 12

Delete a magazine from start of array:


Enter the name of the magazine to remove: Absolute

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Uzbeck                                      212.42   ** highest price **
Vaas                                        135.41
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93
Zoner                                       132.99

Number of magazines = 11

# magazines = 11

Delete the same magazine


Enter the name of the magazine to remove: Absolute

Error: Failed to remove - magazine not found.

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Uzbeck                                      212.42   ** highest price **
Vaas                                        135.41
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93
Zoner                                       132.99

Number of magazines = 11

# magazines = 11

Delete a magazine from middle of array:


Enter the name of the magazine to remove: vaas

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Uzbeck                                      212.42   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93
Zoner                                       132.99

Number of magazines = 10

# magazines = 10

Delete a magazine from the end of the array:


Enter the name of the magazine to remove: Zoner

Name                                         Price

Firework                                     27.54
Flare                                        33.50
Macleans                                     12.75
Uber                                         95.21
Uzbeck                                      212.42   ** highest price **
Valt                                         57.23
Whig Standard                               124.96
Xert                                         52.32
Zeno                                        122.93

Number of magazines = 9

# magazines = 9

Program ended successfully
Flare
33.50
Macleans
12.75
Uber
95.21
Vaas
135.41
Valt
57.23
Whig Standard
124.96
Xert
52.32
Zeno
122.93Press any key to continue . . .
*/