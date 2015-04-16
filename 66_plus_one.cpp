/*
   Given a non-negative number represented as an array of digits, plus one to the number.
   The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> result(digits.size(), 0);
    int carry = 1;
    for(int i = digits.size()-1; i >= 0; i--) {
        result[i] = (digits[i]+carry) % 10;
        carry = (digits[i] + carry)/10;
    }    
    if (carry) {
        result.insert(result.begin(), 1);
    }
    return result;
}


int main() {
    int arr[] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);

    vector<int> result = plusOne(v);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];    
    }

    cout << endl;

} 
