/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Problem 46 + Duplicates might be present. Return unique permutations

*/

#include<iostream>
#include<vector>
using namespace std;


void permute_util (vector<int> num, int index, vector<vector<int> > &result) {
    if (index == num.size()) {
        result.push_back(num);
        return;    
    }    
    
    /* We keep swapping the numbers until we reach the end */ 
    for(int i = index; i < num.size(); i++) {
        /* To avoid duplicates, we avoid swapping identical numbers */
        if (index != i && (num[i] == num[index])) continue;
        swap(num[i], num[index]);
        permute_util(num, index+1, result);    
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    permute_util(num, 0, result);
    return result;
}

/* Print to validate results */
void print_results (vector<vector<int> > &result) {
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }    
        cout << endl;
    }    
}

/* Driver function to test functionality */
int main() {
    int arr[] = {1,1,2,3,4,5,6,7,87,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> num(arr, arr+len); 

    vector<vector<int> > result = permute(num);
    print_results(result);

}
