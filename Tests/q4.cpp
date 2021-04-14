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