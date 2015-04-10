
/*    Leetcode: Problem #87
 *    Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 *
 *    Below is one possible representation of s1 = "great":
 *
 *        great
 *       /    \
 *      gr    eat
 *     / \    /  \
 *    g   r  e   at
 *               / \
 *              a   t
 *    To scramble the string, we may choose any non-leaf node and swap its two children.
 *
 *    For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *
 *        rgeat
 *       /    \
 *      rg    eat
 *     / \    /  \
 *    r   g  e   at
 *               / \
 *              a   t
 *    We say that "rgeat" is a scrambled string of "great".
 *
 *    Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *
 *        rgtae
 *       /    \
 *      rg    tae
 *     / \    /  \
 *    r   g  ta  e
 *           / \
 *          t   a
 *    We say that "rgtae" is a scrambled string of "great".
 *
 *    Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 *
 */

/* Solution variant of http://blog.theliuy.com/scramble-string/ */
/* TODO: Implement a DP solution */

#include<iostream>
#include<string>
using namespace std;

#define CHAR_SIZE 26

bool isScramble(string s1, string s2) {
   
    /* Check if sizes are unequal */ 
    if (s1.size() != s2.size()) return false;

    /* If strings are equal return true */
    if (s1 == s2) return true;

    int len = s1.size();
    //if (len == 1 && s1[0] != s2[0]) return false;

    /* We check if both strings have same chars */
    int count[CHAR_SIZE];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--; 
    }
    for(int i = 0; i < len; i++) {
        if(count[i] != 0) return false;    
    }

    for(int i = 1; i < len; i++) {
        string s11 = s1.substr(0, i);
        string s12 = s1.substr(i);
        
        string s21 = s2.substr(0,i);
        string s22 = s2.substr(i);
        
        if (isScramble(s11, s21) && isScramble(s12, s22)) return true; 

        s21 = s2.substr(len - i);
        s22 = s2.substr(0, len - i);

        if (isScramble(s11, s21) && isScramble(s12, s22)) return true; 
    }

    return false; 
}

int main() {
    string s1 = "great", s2="rgeat";
    //cin >> s1 >> s2;
    
    cout << isScramble(s1, s2) << endl;          
}
