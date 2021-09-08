// q14
void printRainfall(string city[], int rain[][12], ofstream& fout, int noCities) {
    fout << "City" << "\t\tYearly rain amount" << "\n";
    // Hold temporary sum of rain values
    int tempSum;
    for (int pos = 0; pos < noCities; pos++) {
        tempSum = 0;
        fout << city[pos];
        // Get total rain for the year
        for (int innerPos = 0; innerPos < 12; innerPos++) {
            tempSum += rain[pos][innerPos];
        }
        // Print result
        fout << "\t" << tempSum << "\n";
    }
    fout.close();
}