/* 
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
using namespace std;

/* Util function to help with memoization */
vector<string> wordBreak_util (string s, unordered_set<string> &dict, map<string, vector<string> > &memo) {
    
    if (memo.find(s) != memo.end()) {
        return memo[s];    
    }

    vector<string> result;
    if (s.length() == 0) return result;
    
    /* We try to find all possible first words */
    for (int i = 1; i <= s.length(); i++) {
        string word = s.substr(0,i);
        if(dict.find(word) != dict.end()) {
            /* Found in dictionary */
            vector<string> sub_result = wordBreak_util(s.substr(i, string::npos), dict, memo);    
            if (sub_result.size() > 0) {
                for(int j = 0; j < sub_result.size(); j++) {
                    result.push_back(word + " " + sub_result[j]);    
                }    
            }
            else if (i == s.length()){
                result.push_back(word);
            }
        }
    } 
    memo[s] = result;
    return result;
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> result;
    map<string, vector<string> > memo;
    result = wordBreak_util(s, dict, memo);
    return result;
}

int main() {
    
    string words[] = {"cat", "cats", "and", "sand", "dogs"};
    int len = 5;

    unordered_set<string> dict;
    for(int i = 0; i < len; i++) {
        dict.insert(words[i]);    
    } 

    string s = "catsanddogscatsanddogs";
    vector<string> result = wordBreak (s, dict);
   
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;    
    } 

    cout << endl;
}
