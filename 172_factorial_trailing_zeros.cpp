/*
 *Given an integer n, return the number of trailing zeroes in n!.
 *
 *Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
using namespace std;

/* A zero is obtained when we multiply a 5 with 2. There are plenty of 2s to 
 * pair up with limited 5s. We count the number of 5s encountered and return 
 * that number. That will be the number of trailing zeros */
int trailingZeroes(int n) {
    int count = 0;
    while (n/5 > 0) {
        count += (n/5);
        n /= 5;    
    }
    return count;
}


/* Driver program */
int main() {
    int n;
    while(1) {
        cin >> n;
        cout << trailingZeroes(n) << endl; 
    }

}

