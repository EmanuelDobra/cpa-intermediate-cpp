// Q2:
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 500;  

int loadArrays(int[], double[]);
int findProduct(int[], int, int);
int addStart(int[], double[], int, int);

int main()
{
    int productCode[SIZE];
    double price[SIZE];
    int noProducts;

    noProducts = loadArrays(productCode, price);   
    int pos = findProduct(productCode,  noProducts,  30599);

    if (pos == -1)
        cout << "30599 not found\n";
    else
        cout << "price of 30599 is $" << price[pos]<< endl;

    noProducts = addStart(productCode, price,  89234,  noProducts);

    double avgPrice = calcAvg(price, noProducts);

    printProductsAboveAvg(productCode,price,avgPrice,noProducts);
}

/* The function prints and counts a product code
 * if its price is more than the average price. */
void printProductsAboveAvg(int productCode[], double price[], double avgPrice, int noProducts) {
    int aboveAvgTotal;
    for (int pos = 0; pos < noProducts; pos++) {
        if (price[pos] > avgPrice) {
            cout << productCode[pos];
            aboveAvgTotal = aboveAvgTotal + 1;
        }
    }
    cout << "# above average price = " << aboveAvgTotal << "\n";
}

/* Write a function called addStart that will 
 * add a product to the beginning of the arrays.  
 * The price for the new product is to be set to zero.
 * The number of products is to be returned from the array.
 * Print an appropriate error message if a product cannot be added. 
 * No validation is required.  
 * You can assume the product does not already exist 
 * i.e. don’t add code to check if it already exists. */
int addStart(int productCode[], double prices[], int pCode, int noProducts) {
    if (noProducts == SIZE)
        cout << "Array is already at max size. New product was not added.\n";
    else {
        for (int pos = noProducts; pos > 0; pos--) {
            productCode[pos] = productCode[pos-1];
            prices[pos] = prices[pos-1];
        }
        noProducts += 1;
        productCode[0] = pCode;
        prices[0] = 0;
    }
    return noProducts;
}

/* The function searches the array for a product.  
 * Return the position in the array where the product is located.
 * If the product is not found, return -1. You can assume all codes are unique. */
int findProduct(int productCode[], int noProducts, int product) {
    int productPos = -1;
    for (int pos = 0; pos < SIZE; pos++) {
        if (productCode[pos] == product) {
            productPos = pos;
            break;
        }
    }
    return productPos;
}

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