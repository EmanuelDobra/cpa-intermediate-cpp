#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Refresher Lab: Arrays and Functions
const int SIZE = 25;

// Function Prototypes
int loadArrays(ifstream&, string[], int[], int[], char[]);
void printArrays(ofstream&, string[], int[], int[], char[], int);

/* This program loads data from a file into 4 arrays
 (student name, assignment total, test total and grade for up to 25 students)
 It then writes each student’s information to a file */
int main()
{
	// Variables
	string studentName[SIZE];
	int assignTotal[SIZE];
	int testTotal[SIZE];
	char grade[SIZE];
	
	// # of students
	int noProducts;
	// Input file
	ifstream fin("student.dat");
	if (!fin.is_open())
	{
		cout << "error opening student.dat file ";
		system("pause");
		exit(-1);
	}

	// Output file
	ofstream fout("output.dat");
	if (!fout.is_open())
	{
		cout << "error opening output.dat file ";
		system("pause");
		exit(-1);
	}

	noProducts = loadArrays(fin, studentName, assignTotal, testTotal, grade); 
	printArrays(fout, studentName, assignTotal, testTotal, grade, noProducts);
	cout << "program completed successfully" << endl;
	system("type output.dat");
	system("pause");
}

// Fills array with info
int loadArrays(ifstream& fin, string name[], int assignTotal[], int testTotal[], char grade[])
{
	int length = 0;
	for (; length < SIZE; length++)
	{
		getline(fin, name[length]);
		if (fin.eof())
			break;
		fin >> assignTotal[length];
		fin >> testTotal[length];
		fin >> grade[length];
		fin.ignore(80, '\n');
	}
	return length;
}

// Prints arrays to file
void printArrays(ofstream& out, string name[], int assignTotal[], int testTotal[],
	char grade[], int noStudents)
{
	// Output titles 
	out << left << setw(30) << "Student Name" << setw(20) << right << "Assignment Total" <<
		setw(20) << right << "Test Total" << setw(20) << "Grade" << endl << endl;

	// Output results
	for (int index = 0; index < noStudents; index++) {
		out << left << setw(30) << name[index] << setw(20) << right << assignTotal[index] <<
			setw(20) << right << testTotal[index] << setw(20) << grade[index] << endl;
	}
}
