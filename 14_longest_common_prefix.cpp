/* Leetcode #14
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    /* Base cases for 0 and 1 size vectors */
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];

    int count = -1;
    bool done = false;

    while (!done) {
        /* We compare with the character of first string */
        if(++count >= strs[0].length()) break;
        char c = strs[0][count];
        cout << c << endl;

        /* Start coparing with rest of the strings */
        for(int i = 1; i < strs.size(); i++) {
            if(count >= strs[i].length() || strs[i][count] != c) {
                done = true;
            }
        }

    }

    return strs[0].substr(0, count);
}

/* Driver program */
int main() {
    vector<string> s;
    s.push_back("asdc");
    s.push_back("adffasdf");
    s.push_back("asdffas");
    cout << longestCommonPrefix(s) << endl;
} 
