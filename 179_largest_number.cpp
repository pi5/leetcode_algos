/* Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

*/

#include<iostream>
#include<queue>
#include<string>
using namespace std;

template<typename T>
struct Compare {
    bool operator() (T &a, T &b) {
        string sa = to_string(a);
        string sb = to_string(b);
        
        return sa + sb < sb + sa;
    }   
};


string largestNumber(vector<int> &num) {
    priority_queue<int, vector<int>, Compare<int> > p;
    
    for(int i = 0; i < num.size(); i++) {
        p.push(num[i]);    
    }
    
    string s = "";
    while(!p.empty()) {
        s = s + to_string(p.top());
        p.pop();    
    }
    
    return s[0] == '0' ? "0" : s;
}


int main() {

    int arr[] = {3, 30, 34, 5, 9};    
    int len = sizeof(arr)/sizeof(arr[0]);

    vector<int> v;
    for(int i = 0; i < len; i++) {
        v.push_back(arr[i]);    
    }

    cout << endl << largestNumber(v);
    cout << endl;
}
