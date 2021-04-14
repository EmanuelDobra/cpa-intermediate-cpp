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