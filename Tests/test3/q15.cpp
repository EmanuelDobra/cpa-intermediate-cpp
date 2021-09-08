// q16
void printAvgRainfall(string city[], int rain[][12], int noCities) {
    cout << "Average Monthly Rainfall per City" << endl;
    // Hold temporary avrg of rain values
    double tempAvrg;
    for (int i = 0; i < noCities; i++) {
        tempAvrg = 0;
        // Add up all values
        for (int j = 0; j < 12; j++) 
            tempAvrg += rain[i][j];
        // Get monthly avrg
        tempAvrg /= 12;
        // Print if less avrg < 10
        if (tempAvrg < 10)
            cout << city[i] << "\t\t" << tempAvrg << endl;
    }
}