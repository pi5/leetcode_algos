/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate (int numRows) {
    
    vector<vector<int> > results;
    if (numRows <= 0) return results;
    
    vector<int> first(1,1);
    results.push_back(first);   

    for (int row = 1; row < numRows; row++) {
        vector<int> temp;
        for(int i = 0; i < row+1; i++) {
            if(i == 0) {
                temp.push_back(results[row-1][0]);    
            }    
            else if (i == row){
                temp.push_back(results[row-1][i-1]);
            }
            else {
                temp.push_back(results[row-1][i-1] + results[row-1][i]);    
            }
        }
        results.push_back(temp);
    }
    return results;
}


void printAll(vector<vector<int> > &v) {
    cout << endl;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << " " << v[i][j];    
        }    
        cout << endl;
    }
    
    cout << endl;    
    
}

int main() {

    int numRows;
    cin >> numRows;
    
    vector<vector<int> > p = generate(numRows);
    printAll(p); 
    
}
