/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Given an encoded message containing digits, determine the total number of ways to decode it.

  For example,
  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

  The number of ways decoding "12" is 2.
  */

#include<iostream>
#include<string>
#include<map>
using namespace std;


/* Recursive -- elegant */
int numDecodings (string s) {
    if(s.length() == 0) return 1;
    if(s.length() == 1) return s[0]=='0'?0:1;

    int skip_two = 0;     

    if (s[0] != '0') {
        int num = (s[0] - '0')*10 + s[1]-'0';
        if (num <= 26) {
            skip_two = numDecodings(s.substr(2));
        }

        return skip_two + numDecodings(s.substr(1));
    }
    return 0;        
}


/* Recursive solution util function - Avoid -- too complicated! */
void decode_ways_util (string s, int start, int &ways) {

    if (start == s.length()) {
        ways++;
        return;    
    }    

    char c = s[start];
    /* Alphabet encoding is from 1 to 26. 0 needs special handling */
    if (start + 1 < s.length() && s[start+1] == '0') {
        decode_ways_util (s, start+2, ways);    
    }
    else if (c == '1') {
        decode_ways_util (s, start + 1, ways);    
        if (start + 1 < s.length()) {
            /* next sequence cannot start from zero */
            if((start + 2 < s.length() && s[start+2] != '0') || (start + 2 == s.length()))
                decode_ways_util (s, start+2, ways);    
        }
    }
    else if (c == '2' && start + 1 < s.length()) {
        decode_ways_util (s, start + 1, ways);    
        char temp = s[start + 1];
        if (temp >= '0' && temp <= '6') {
            /* next sequence cannot start from zero */
            if((start + 2 < s.length() && s[start+2] != '0') || (start + 2 == s.length()))
                decode_ways_util (s, start + 2, ways);    
        }
    }
    else {
        decode_ways_util (s, start + 1, ways);    
    }
}

/* Recursive solution - Avoid -- too complicated! */
int decode_ways (string s) {
    int ways = 0;
    decode_ways_util (s, 0, ways);
    return ways;    
}


/* DP solution */
int decode_ways_dp (string s) {

    int len = s.length(); 
    if (len == 0) return 0;
    if (len == 1) return (s[0] == '0' ? 0:1);

    int memo[len + 1];
    memset(memo, 0, sizeof(memo));

    memo[len] = 1;
    memo[len - 1] = s[len-1] == '0' ? 0 : 1;

    for (int i = len -2; i >= 0; i--) {
        if (s[i] != '0') {
            memo[i] += memo[i+1];
            int num = (s[i] - '0')*10 + (s[i+1]-'0');

            if (num <= 26) {
                memo[i] += memo[i+2];    
            }        
        }    
    }
    return memo[0];
}





int main() {

    string s;
    while (1) {
        cin >> s;
        cout << decode_ways(s) << endl;
        cout << numDecodings(s) << endl;
        cout << decode_ways_dp(s) << endl;
        cout << endl;    
    }    
}
