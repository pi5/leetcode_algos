#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            int n = s.length();
            if (n == 1 && s[0] == ' ') {
                s = "";
                return;
            }
            if (n <= 1) return;

            /* First reverse the entire string */
            reverse(s.begin(), s.end());

            int word_start = 0, word_end = 1;

            /* Reverse each word */
            while(word_start < s.length()) {

                /* Find first non-blank character */
                while(word_start < s.length() && s[word_start] == ' ') 
                    word_start++;

                word_end = word_start + 1;

                /* Find end of the word */
                while (word_end < s.length() && s[word_end] != ' ') 
                    word_end++;

                reverse(s.begin() + word_start, s.begin() + word_end);

                word_start = word_end + 1;

            }

            /* Stripping white space in beginning and end */
            while(s.length() > 0 && s[0] == ' ') 
            { 
                s.erase(s.begin());
            }

            while(s.length() > 0 && s[s.length() - 1] == ' ') 
            { 
                s.erase(s.begin() + s.length()-1);
            }

            /* Trimming in between -- required by problem*/
            word_end = 1;
            while(word_end < s.length()) {
                if (s[word_end] == ' ' && s[word_end  + 1] == ' ') {
                    s.erase(s.begin() + word_end);
                }
                else {
                    word_end++;
                }
            }

        }
};
