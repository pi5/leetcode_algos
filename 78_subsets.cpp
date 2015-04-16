/* Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/


#include<iostream>
#include<vector>

using namespace std;


vector<vector<int> > subsets_util(vector<int> &S, int start) {
    vector<vector<int> > results;
    if (start == S.size()) {
        vector<int> temp;
        results.push_back(temp);
        return results;
    }
    
    int curr = S[start];
    vector<vector<int> > subresults = subsets_util(S, start + 1);
    
    /* Add the actual subresult */
    for (int i = 0; i < subresults.size(); i++) {
        results.push_back(subresults[i]);    
    }
    
    /* Append the current int to subresults and push to results */
    for(int i = 0; i < subresults.size(); i++) {
        vector<int> r = subresults[i];
        r.push_back(curr);
        results.push_back(r);
    }
    return results;
}

vector<vector<int> > subsets(vector<int> &S) {
    int start = 0;
    sort (S.begin(), S.end(), greater<int>());
    vector<vector<int> > results = subsets_util (S, start);          
    return results;
}


void print_results(vector<vector<int> > &v) {
    
    for (int i = 0; i < v.size(); i++) {
        cout << endl << "[";
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j < v[i].size() - 1){
                cout << ", ";    
            }
        }    
        cout << "]";
    }    
}

int main() {
    
    int arr[] = {1,2,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    vector<int> v(arr, arr + len);
    vector<vector<int> > results = subsets(v);
    
    print_results(results); 
    cout << endl;

}
