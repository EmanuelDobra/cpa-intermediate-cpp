/* Use a for loop to read data from the products.dat file 
 * until end of file is reached or the arrays are full. */
int loadArrays(int productCode[], double price[]) {
    ifstream myFile("products.dat");

    int pos;
    while (!myFile.eof()) {
        for (pos = 0; pos < SIZE; pos++) {
            myFile >> productCode[pos];
            if (myFile.eof()) {
                break;
            }         
            myFile >> price[pos];
            myFile.ignore(80, '\n');   
        }
    }
    return pos;
}