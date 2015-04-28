/* Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int titleToNumber(string s) {
    
    if (s.length() == 0) {
        return 0;    
    }   

    int len = s.length();
    int power = 0;
    int num = 0;
    const int base = 26;

    for (int i = 0; i < len; i++) {
        int digit = s[i] - 'A' + 1;
        num = num*26 + digit;
    }
    return num;
}


int main() {
    
    string s;
    while(1) {
        cin >> s;
        cout << titleToNumber(s) << endl;
    }
}
