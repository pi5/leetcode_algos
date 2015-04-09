#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateMatrix(int n) {

    vector<vector<int> > result;
    for(int i = 0; i < n; i++) {
        vector<int> t(n);    
        result.push_back(t);
    }

    int num = 0;
    int depth = n/2;

    for (int d = 0; d <= depth; d++) {
        
        /* Top left to top left */
        for(int i = d; i < n-d; i++) {
            result[d][i] = ++num;
            
            //cout << num << endl;
        }    

        /* Top right to bottom left */
        for(int i = d+1; i < n-d; i++) {
            result[i][n-d-1] = ++num;
        }

        /* Bottom right to bottom left */
        for (int i = n-d-2; i >= d; i--) {
            result[n-d-1][i] = ++num;    
        }

        /* Bottom right to top left */
        for (int i = n-d-2; i > d; i--) {
            result[i][d] = ++num;    
        }
    }
    
    return result;
}

void print_result(vector<vector<int> > &result) {
    for(int i = 0; i < result.size(); i++) {
        cout << endl;
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "\t";
        }    
    }    
}

int main() {
    vector<vector<int> > result = generateMatrix(5);
    print_result(result);
    cout << endl;
}

