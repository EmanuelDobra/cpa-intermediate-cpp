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