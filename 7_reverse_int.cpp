/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note: Beware of overflows
*/

#include<iostream>
using namespace std;

int reverse(int x) {
    if (x > -10 && x < 10) return x;
    if (x == INT_MIN) return 0;

    int sign = 1;
    if (x < 0) {
        sign = -1;
        x *= -1;
    }

    int rev = 0;
    while (x != 0) {
        if (rev == INT_MAX/10) {
            if (x%10 > INT_MAX%10) {
                return 0;
            }
        }
        else if (rev > INT_MAX/10) {
            return 0;
        }
        rev = rev*10 + x%10;
        x /= 10;
    }
    return sign*rev;
}

int main() {

    int x;
    while (1) {
        cin >> x;
        cout << INT_MAX << endl;
        cout << "--> " <<  reverse(x) << endl;    
    }    

}
