/* Minimum Depth of Binary Tree */

/**
 *  * Definition for binary tree
 *  * struct TreeNode {
 *  *     int val;
 *  *     TreeNode *left;
 *  *     TreeNode *right;
 *  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  * };
 *  */
class Solution {
    public:
        int minDepth(TreeNode *root) {
            if (root == NULL) return 0;
            int min_depth = INT_MAX;
            minDepth_util (root, min_depth, 1);
            return min_depth;
        }

        void minDepth_util(TreeNode *root, int &min_depth, int curr_depth) {
            if (curr_depth > min_depth) return;

            if (root->right == NULL && root->left == NULL && curr_depth < min_depth) {
                min_depth = curr_depth;
            }

            else {
                if (root->right != NULL) {
                    minDepth_util (root->right, min_depth, curr_depth + 1);
                }
                if (root->left != NULL) {
                    minDepth_util (root->left, min_depth, curr_depth + 1);
                }
            }
        }
};
