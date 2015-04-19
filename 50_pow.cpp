/*
 * Implement pow(x, n)
 */

#include <iostream>
using namespace std;

double pow(double x, int n) {
    if (n == 0) return 1;

    bool pos_pow = n > 0 ? true : false;

    /* We need a different handling for negative numbers */
    int abs_pow = abs(n);

    double temp = pow(x, abs_pow/2);

    /* For negative numbers we take reciprocals */
    if(!pos_pow) {
        temp = 1/temp;
        x = 1/x;
    }

    if (n % 2 == 0) {
        return temp*temp;    
    }
    else{
        return x * temp * temp;    
    }
}

int main() {
    double x; 
    int n;
    while(1) {
        cin >> x;
        cin >> n;
        cout << pow(x,n) << endl;  
    }
} 
