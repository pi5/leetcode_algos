/*
 *    Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 *    For example:
 *    Given "25525511135",
 *
 *    return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> ip_helper (string s, int points) {
    
    vector<string> results;
    if(points == 0) {
        /* Last number should:
         * 1. Be less than three digits
         * 2. Be less than 255
         * 3. If greater than 1 digit, should not begin with 0
         */
        if(s.length() > 3 || stoi(s) > 255 || (s.length() > 1 && s[0]=='0')) {
            return results;    
        }
        else {
            results.push_back(s);
            return results;
        }
    }
    
    float ratio = (float(s.length()) / (points+1)); 
    if(ratio > 3 || ratio < 1) {
        return results;
    }

    vector<string> subresults;
    int num = 0;
    for (int i = 0; i < 3 && i < s.length()-1; i++) {
        num = num*10 + (s[i] - '0');  
        if (num <= 255) {
            subresults = ip_helper(s.substr(i+1), points - 1);
            for(int j = 0; j < subresults.size(); j++) {
                string ip = to_string(num) + "." + subresults[j];
                results.push_back(ip);        
            } 
        }
        else {
            break;    
        }
        if(num == 0) break;
    }
    return results;
}


vector<string> restoreIpAddresses(string s) {
    vector<string> results;
    int len = s.length();

    if(len < 4 || len > 12) return results;

    int points = 3;
    results = ip_helper (s, points);

    return results;
}

void print_results (vector<string> &results) {
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;    
    }    
}


int main() {
    //string s = "10255122255";
    //string s = "1111";
    string s = "010010";
    vector<string> results = restoreIpAddresses(s);
    print_results(results);
}
