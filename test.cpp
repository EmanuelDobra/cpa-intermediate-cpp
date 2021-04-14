#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// name: Joulyano Mzaber
// purpose: ...........

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
	system("type magazines.dat");
	system("pause");
}





int loadArrays(string name[], double price[])
{
	ifstream fin("magazine.dat");
	if (!fin.is_open())
	{
		cout << "error opening magazine.dat";
		system("pause");
		exit(-1);
	}

	int index = 0;
	while (!fin.eof())
	{
		for (; index < SIZE; index++)
		{
			getline(fin, name[index]);
			if (fin.eof())
			{
				break;
			}
			fin >> price[index];
			fin.ignore(80, '\n');
		}
	}
	return index;
}

double findHighest(double price[])
{
	double highest = 0;
	for (int index = 0; index < SIZE; index++)
	{
		if (price[index] > highest)
		{
			highest = price[index];
		}
	}
	return highest;
}

void printMagazines(string name[], double price[], int noMagazines)
{
	cout << left << setw(15) << "Name"
		<< right << setw(19) << "Price" << endl << endl;

	double highest = findHighest(price);
	for (int index = 0; index < noMagazines; index++)
	{
		cout << left << setw(15) << name[index];
		if (price[index] == highest)
		{
			cout << right << setw(17) << price[index]
				<< right << setw(19) << "**highest price**" << endl;
		}
		else
		{
			cout << right << setw(17) << price[index] << endl;
		}
	}
	cout << endl;
	cout << "Number of magazines: " << noMagazines << endl << endl;
}



int addMagazine(string name[], double price[], int noMagazines)
{
	if (noMagazines == SIZE)
	{
		cout << "Max number of magazines reached, cannot add more " << endl;
	}
	else
	{
		string new_magazine;
		double new_price;
		bool magazine_exist = false;
		cout << "Please enter the name of the magazine: ";
		getline(cin, new_magazine);

		// first add the new magazine to the array
		for (int index = 0; index < SIZE; index++)
		{
			if (name[index] == new_magazine)
			{
				magazine_exist = true;
				cout << "Error, this magazine already exists " << endl;
				break;
			}
		}

		// next, ask for the price
		if (magazine_exist == false)
		{
			cout << "Please enter the price of the new magazine: ";
			cin >> new_price;
			new_price = validatePrice(new_price);
			name[noMagazines] = new_magazine;
			price[noMagazines] = new_price;
			noMagazines++;
			cin.clear();
			cin.ignore(80, '\n');
		}

		// hold array element
		string hold_name;
		double hold_price;

		// then, shift the magazine to its correct spot
		for (int index = noMagazines-1; index > 0; index--)  // index = 9
		{
			hold_name = name[index-1];
			hold_price = price[index-1];

			if (name[index] < name[index-1])          
			{
				name[index-1] = name[index];
				price[index-1] = price[index];
				name[index] = hold_name;
				price[index] = hold_price;
			} 
			else
			{
				break;
			}
		}
	}

	return noMagazines;
}

double validatePrice(double magPrice)
{
	while (magPrice < 0 || magPrice > 900 || cin.fail())
	{
		cout << "Invalid entery, Please enter a number between 0-900 " << endl;
		cin.clear();
		cin.ignore(80, '\n');
		cin >> magPrice;
	}
	return magPrice;
}

int removeMagazine(string name[], double price[], int noMagazines)
{
	string remove_magazine;
	bool validate_remove = false;
	cout << "Please enter the magazine name you wish to remove: ";
	getline(cin, remove_magazine);

	for (int index = 0; index < SIZE; index++)
	{
		if (name[index] == remove_magazine)
		{
			for (int check = index; check < noMagazines; check++)
			{
				name[check] = name[check+1];
				price[check] = price[check+1];
			}
			noMagazines--;
			validate_remove = true;
			break;
		}

	}

	if (validate_remove == false)
	{
		cout << "Error, this magazine does not exist " << endl;
	}

	return noMagazines;
}