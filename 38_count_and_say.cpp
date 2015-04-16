#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n) {
    if(n == 0) return "";

    string num = "1" ;

    for (int i = 1; i < n; i++) {
        int curr = 0;
        string next = "";
        while(curr < num.length()) {
            char c = num[curr];
            int count = 0;
            while(num[curr+count] == c && curr+count < num.length())
                 count++;
            next += (to_string(count) + c);
            curr = curr+count;
        }
        num = next;
        cout << num << endl;
    }
    return num;
}

int main() {

    int n; 
    cin >> n;
    cout << countAndSay(n);
}
