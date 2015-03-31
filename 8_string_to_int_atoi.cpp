/* Implement atoi -- Convert string to integer */

#include<iostream>
using namespace std;

int atoi (string s) {
    if(s.length() == 0) return 0;
    
    int index = 0;
    int num = 0;
    int sign = 1;
    
    /* Discard whitespaces */
    while(s[index] == ' ') index++;

    /* Check for sign */
    if (s[index] == '+' || s[index] == '-'){
        sign = s[index] == '+' ? 1 : -1;
        index++;    
    }
    
    int digits = 0;
    for (int i = index; i < s.length(); i++) {
        if( !(s[i] >= '0' && s[i] <= '9') ) break;

        if(num >= INT_MAX/10) {
            if((s[i] - '0' > INT_MAX%10) && sign == 1){
                return INT_MAX;    
            }
            if((s[i] - '0' > -1*(INT_MIN%10)) && sign == -1){
                return INT_MIN;    
            }
            
        }
        num = num*10 + (s[i] - '0');
        if (digits++ > 10) {
            break;    
        }
    }
   
    /* If number of digits are greater than INT_MAX digits */ 
    if (digits > 10) {
        return sign == 1 ? INT_MAX : INT_MIN;    
    }

    return num * sign;
}

int main() {
    string s = "      -11919730356x";
    while (1) {
        cout << atoi(s) << endl;    
        cin >> s;
    } 
}
