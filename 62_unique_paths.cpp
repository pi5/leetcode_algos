/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

*/

#include<iostream>
using namespace std;

/* Dynamic programmign solution */
int uniquePaths(int m, int n) {
    int memo[m][n];
    memset(memo, 0, sizeof(memo));
    
    /* only go down from last col */
    for(int i = 0; i < m; i++) {
        memo[i][n-1] = 1;
    }

    /* only go right from last row */
    for(int i = 0; i < n; i++) {
        memo[m-1][i] = 1;
    }

    /* start filling rest of the matrix from bottom right
     * to top left */
    for (int i = m-2; i >=0; i--) {
        for(int j = n-2; j >= 0; j--) {
            //cout << i << j << endl << endl;
            memo[i][j] = memo[i+1][j] + memo[i][j+1];   
        }    
    }
    
    return memo[0][0];
}


int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;    
}
