// q12
void loadArrays(string city[], int rain[][12], ifstream& fin, int &noCities) {
    for (noCities = 0; noCities < SIZE; noCities++) {
        // Fill city array
        getline(fin, city[noCities]);
        // Break if eof
        if (fin.eof())
            break;
        for (int innerPos = 0; innerPos < 12; innerPos++) {
            // Fill rain array
            fin >> rain[noCities][innerPos];
        }
        fin.ignore(80, '\n');
    }
    fin.close();
}