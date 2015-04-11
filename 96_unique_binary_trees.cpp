/*    Leetcode #96
 *    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 *    For example,
 *    Given n = 3, there are a total of 5 unique BST's.
 *
 *       1         3     3      2      1
 *        \       /     /      / \      \
 *         3     2     1      1   3      2
 *        /     /       \                 \
 *       2     1         2                 3
 *
 */

#include <iostream>
using namespace std;

int numTrees(int n) {
    if (n <= 1) return n;
    
    int trees[n+1];
    trees[0] = 1;
    trees[1] = 1;

    for (int i = 2; i <= n; i++) {
        int t = 0;
        for (int j = i; j > 0; j--) {
            int right = i - j;
            int left = j-1;
            /* Total possible trees is a product of total possible
             * on right and total possible on left
             */
            t += (trees[right] * trees[left]);
        }
        trees[i] = t;
    }

    return trees[n];
}

int main() {
    int n;

    while (1) {
        cin >> n;
        cout << numTrees(n) << endl;        
    }
}      
