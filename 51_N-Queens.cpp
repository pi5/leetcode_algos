/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isSafe (const vector<string> &board, int row, int col) {
    
    /* Check row towards left */
    for (int i = col-1; i >= 0; i--) {
        if(board[row][i] == 'Q') {
            return false;    
        }    
    }

    /* Check left upwards diagonal */
    for (int i = col-1, j = row - 1; i >= 0 && j >=0; i--, j--) {
        if(board[j][i] == 'Q') {
            return false;    
        }    
    }

    /* Check left downwards diagonal */
    for (int i = col-1, j = row + 1; i >= 0 && j < board.size(); i--, j++) {
        if(board[j][i] == 'Q') {
            return false;    
        }    
    }
    return true;    
}


bool solveNQueens_util(vector<string> &board, const int &n, int col, vector<vector<string> > &results) {
    
    /* If all columns have been filled, save the board position and return */ 
    if (col == n) {
        results.push_back(board);
        return true;    
    }

    /* Start placing the string in r-th row */
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)){

            /* Place the queen */
            board[row][col] = 'Q';
            solveNQueens_util(board, n, col+1, results);
            
            /* Remove the placed queen */
            board[row][col] = '.';
        }
    }

    return false;    
}

vector<vector<string> > solveNQueens(int n) {
    vector<string> board;
    string row(n, '.');
    for (int i = 0; i < n; i++) {
        board.push_back(row);    
    } 
    
    vector<vector<string> > results;
    solveNQueens_util (board, n, 0, results);
    return results;
}

void print_board(const vector<string> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;    
    }
}

void print_results(const vector<vector<string> > &v) {

    cout << endl;    
    for(int i = 0; i < v.size(); i++) {
        cout << "\n\n[\n";
        print_board(v[i]);
        cout << "]\n";
    }
    cout << endl;    
}



int main () {
   int n;
   cin >> n;
   
   vector<vector<string> > results = solveNQueens(n);
   print_results(results);
   return 0;
}
