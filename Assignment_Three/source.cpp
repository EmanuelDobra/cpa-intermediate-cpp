/*
 * Name: Emanuel Dobra
 * Assignment: #3
 * 
 * Program takes in organized data of bird sightings in different areas
 * and displays the statistics in a report file. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 25;

void loadArrays(ifstream&, string[], int[][3], int&);
void computeSum(int[][3], int[], int);
void findBird(int[][3], int&, int&, int);
void mostSightings(int[], int&, int);
void printReport(ofstream&, string[], int[][3], int[], int, int);

int main()
{
	int sightings[SIZE][3];  //no need to change your variable names to match yours!
	string bird[SIZE];
	int totalAreaSightings[SIZE] = { 0 };
	int noBirds;
	int highestRow, highestCol, mostSeen;

	ifstream fin("birds.dat");
	if (!fin.is_open())
	{
		cout << "error opening birds.dat file - contact systems";
		system("pause");
		exit(-1);
	}
	ofstream fout("birds.rpt");
	if (!fout.is_open())
	{
		cout << "error opening birds.rpt file - contact systems";
		system("pause");
		exit(-2);
	}

	cout << "\n\nLoad arrays\n\n";
	loadArrays(fin, bird, sightings, noBirds);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nCompute total sightings by area\n\n";
	computeSum(sightings, totalAreaSightings, noBirds);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind most seen bird and highest number of sightings:\n\n";
	findBird(sightings, highestRow, highestCol, noBirds);
	cout << "\n\n" << bird[highestRow] << " had the most number of sightings = "
		<< sightings[highestRow][highestCol] << endl;
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind the most seen bird:\n\n";
	mostSightings(totalAreaSightings, mostSeen, noBirds);
	cout << "\n\n Most seen bird is " << bird[mostSeen] << endl;

	cout << "\n\n=======================================================\n\n";

	printReport(fout, bird, sightings, totalAreaSightings, mostSeen, noBirds);
	cout << "\n\n=======================================================\n\n";

	fout.close();
	fin.close();

	cout << "program ended successfully" << endl;
	cout << "\n\n Printing birds.dat file\n\n";
	system("type birds.dat");
	cout << "\n\n Printing birds.rpt file\n\n";
	system("type birds.rpt");
	system("pause");
}

/**
 * Fill the arrays with the data from the input file.
 * 
 * @param myFile Input file that holds the bird data
 * @param birdTypes String array holding all the bird types
 * @param birdSightings Bird array that contains all the data
 * @param noBirds Total number of birds recorded within the arrays
 */
void loadArrays(ifstream& myFile, string birdTypes[], int birdSightings[][3], int &noBirds) {
	// Loop until array reaches max capacity
	for (noBirds = 0; noBirds < SIZE; noBirds++) {
		// Get input from file
		getline(myFile, birdTypes[noBirds]);
		// Break if file data ends
		if (myFile.eof())
			break;
		// Otherwise, fill the birdSightings array
		for (int innerPos = 0; innerPos < 3; innerPos++) {
			myFile >> birdSightings[noBirds][innerPos];
		}
		myFile.ignore(80, '\n');
	}
}


/**
 * Compute the sum of each individual bird's sightings.
 *
 * @param birdSightings Bird array that contains all the data
 * @param totalAreaSightings Total array holding the sum of each bird's sightings
 * @param noBirds Total number of birds recorded within the arrays
 */
void computeSum(int birdSightings[][3], int totalAreaSightings[], int noBirds) {
	for (int pos = 0; pos < noBirds; pos++) {
		// Initialize value to 0
		totalAreaSightings[pos] = 0;
		for (int innerPos = 0; innerPos < 3; innerPos++) {
			// Add area sightings to value
			totalAreaSightings[pos] += birdSightings[pos][innerPos];
		}
	}
}

/**
 * Find the bird with the highest area sighting, and store its [x, y] values
 *
 * @param birdSightings Bird array that contains all the data
 * @param highestRow Row # of the highest bird.
 * @param highestCol Col # of the highest bird.
 * @param noBirds Total number of birds recorded within the arrays
 */
void findBird(int birdSightings[][3], int &highestRow, int &highestCol, int noBirds) {
	// Initialise var to hold the current highest sightings amount
	int topSighting = 0;
	for (int row = 0; row < noBirds; row++) {
		for (int col = 0; col < 3; col++) {
			if (birdSightings[row][col] > topSighting) {
				// Update top upon finding a higher value
				topSighting = birdSightings[row][col];
				highestRow = row;
				highestCol = col;
			}
		}
	}
}

/**
 * Find the bird with the most total sightings.
 *
 * @param totalAreaSightings Total array holding the sum of each bird's sightings
 * @param mostSeen Index of the most seen bird within the totalAreaSightings array
 * @param noBirds Total number of birds recorded within the arrays
 */
void mostSightings(int totalAreaSightings[], int &mostSeen, int noBirds) {
	// var to hold the most sightings
	int mostSightings = 0;
	for (int pos = 0; pos < noBirds; pos++) {
		if (totalAreaSightings[pos] > mostSightings) {
			// if value is higher, update the value and the position
			mostSightings = totalAreaSightings[pos];
			mostSeen = pos;
		}
	}
}

/**
 * Print the birds report to output file.
 *
 * @param outFile Output file to hold the bird report
 * @param birdTypes String array holding all the bird types
 * @param birdSightings Bird array that contains all the data
 * @param totalAreaSightings Total array holding the sum of each bird's sightings
 * @param mostSeen Index of the most seen bird within the totalAreaSightings array
 * @param noBirds Total number of birds recorded within the arrays
 */
void printReport(ofstream& outFile, string birdTypes[], int birdSightings[][3], 
	int totalAreaSightings[], int mostSeen, int noBirds) {
	// Titles
	outFile << left << setw(20) << "\nType of Bird"
		<< left << setw(10) << "Area #1"
		<< left << setw(10) << "Area #2"
		<< left << setw(10) << "Area #3"
		<< left << setw(10) << "Total\n";
	
	// Fix indentation
	outFile << endl;

	// var to hold the grand total of all sightings
	int grandTotal = 0; 
	for (int pos = 0; pos < noBirds; pos++) {
		// output the bird type
		outFile << left << setw(20) << birdTypes[pos];

		for (int innerPos = 0; innerPos < 3; innerPos++) {
			// output the sightings for each area
			outFile << left << setw(10) << birdSightings[pos][innerPos];
		}

		// output the total sightings
		outFile << left << setw(4) << totalAreaSightings[pos];

		// if most seen, mark it in output
		if (pos == mostSeen)
			outFile << "** Most Sightings**";
		outFile << endl;
		
		// update grand total
		grandTotal += totalAreaSightings[pos];
	}

	outFile << "\nTotal Number of Sightings = " << grandTotal << endl;
}

/*Output 


Load arrays



=======================================================



Compute total sightings by area



=======================================================



Find most seen bird and highest number of sightings:



Baltimore Oriole had the most number of sightings = 53


=======================================================



Find the most seen bird:



 Most seen bird is Blue Heron


=======================================================



=======================================================

program ended successfully


 Printing birds.dat file

Blue Heron
25      50       4
Cardinal
25      0       25
King Fisher
3       44       0
Pink Flamingo
0       40       2
Baltimore Oriole
53      8        7
Albatross
11  32   27
Swift
20  13   38
Plover
0   12   5


 Printing birds.rpt file


Type of Bird       Area #1   Area #2   Area #3   Total

Blue Heron          25        50        4         79  ** Most Sightings**
Cardinal            25        0         25        50
King Fisher         3         44        0         47
Pink Flamingo       0         40        2         42
Baltimore Oriole    53        8         7         68
Albatross           11        32        27        70
Swift               20        13        38        71
Plover              0         12        5         17

Total Number of Sightings = 444
Press any key to continue . . .
*/