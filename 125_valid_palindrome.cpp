#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    
    if (s.length() <= 1) return true;
    int front = 0;
    int back = s.length()-1;
    
    while (front < back) {
        while(front < back && !isalnum(s[front])) front++;   
        while(front < back && !isalnum(s[back])) back--;   

        if(tolower(s[front]) != tolower(s[back])) return false;
        front++;
        back--;
    } 
    return true;
}


int main(){
    //string s = "A man, a plan, a canal: Panama";
    string s = "race a car";
    cout << endl << isPalindrome(s) << endl;    
}
