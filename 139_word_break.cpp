/*
 *    Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 *    For example, given
 *    s = "leetcode",
 *    dict = ["leet", "code"].
 *
 *    Return true because "leetcode" can be segmented as "leet code".
 *
 */


#include <iostream>
#include <unordered_set>
#include<string>
using namespace std;

/* Recursive solution */
bool wordBreak_util(const string &s, const unordered_set<string>& wordDict, int start, int end) {
    if(wordDict.find(s.substr(start)) != wordDict.end()) {
        return true;    
    }
    
    bool found_in_rest = false;
    for (int i = start; i < end; i++) {
        string word = s.substr(start, i-start+1);
        if(wordDict.find(word) != wordDict.end()) {
            found_in_rest = wordBreak_util(s, wordDict, i+1, end);            
        }
        if(found_in_rest) return true;
    }

    return false;
}

bool wordBreak_recursive(string s, unordered_set<string>& wordDict) {
    return wordBreak_util (s, wordDict, 0, s.length());
}



/* DP solution */
bool wordBreak(string s, unordered_set<string>& wordDict) {
    
    bool memo[s.length()];
    memset(memo, false, sizeof(memo));

    for(int i = s.length()-1; i >= 0 ; i--) {
        for(int j = i; j < s.length(); j++) {
            string word = s.substr(i, j-i+1);
                        
            /* If the word is found, we check if the remaining array can be broken */
            /* For each iteration, we check substrings ahead of us */
            if(wordDict.find(word) != wordDict.end()) {
                if(j < s.length()-1) {
                    memo[i] = memo[j+1];
                }
                else{
                    memo[i] = true;    
                }
            }
            /* If we find a possible match for string ahead of j, set memo[i]
             * to true and break
             */
            if(memo[i]) break;
        }
    }
    return memo[0];
}


int main() {
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    dict.insert("leetc");
    dict.insert("odes");

    cout << wordBreak(s, dict) << endl;
} 
