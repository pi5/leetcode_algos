/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    if (s.length() == 0) return true;
    if (s.length()%2 != 0) return false;

    stack<char> p;            

    for(int i = 0; i < s.length(); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[' ) {
            p.push(s[i]);   
        }    
        else {
            if(p.empty()) return false;
            char c = s[i];
            switch(c) {
                case ')':
                    if (p.top() != '(') return false;
                    break;    
                case '}':
                    if (p.top() != '{') return false;
                    break;    
                case ']':
                    if (p.top() != '[') return false;
                    break;    
                default:
                    return false;
            }
            p.pop();
        }
    }

    return p.empty();
}


int main() {
    
    string s;

    while (1) {
        cin >> s;
        cout << isValid(s) << endl;    
    }
}
