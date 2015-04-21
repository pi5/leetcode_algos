/*
 *    Given a binary tree, find the maximum path sum.
 *
 *    The path may start and end at any node in the tree.
 *
 *    For example:
 *    Given the below binary tree,
 *
 *           1
 *          / \
 *         2   3
 *    Return 6.
 */


#include <iostream>
using namespace std;
/*
 *Definition for binary tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum_util (TreeNode *root, int &global_sum) {

    if (root == NULL) return 0;
    int right_sum = maxPathSum_util (root->right, global_sum);
    int left_sum = maxPathSum_util (root->left, global_sum);

    int sum = root->val + max(right_sum, left_sum);

    /* Considering maximum sum upto now */
    int max_sum_here = root->val + right_sum + left_sum;

    /* Update global_sum */
    if(max_sum_here > global_sum) global_sum = max_sum_here;

    return sum > 0 ? sum : 0;
}

int maxPathSum(TreeNode *root) {
    int global_sum = INT_MIN;
    maxPathSum_util(root, global_sum);
    return global_sum;
}


int main() {

}
