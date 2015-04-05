#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void preorder_util(TreeNode *root, vector<int> &result) {
    if(root == NULL) return;
    result.push_back(root->val);
    preorder_util(root->left, result);
    preorder_util(root->right, result);
}

/* Recursive */
vector<int> preorderTraversal_recursive(TreeNode *root) {
    vector<int> result;
    preorder_util(root, result);
    return result;
}

/* Iterative Solution */
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    if(root == NULL) return result;

    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()) {
        TreeNode *temp = s.top();
        result.push_back(temp->val);
        s.pop();
        
        if(temp->right != NULL) {
            s.push(temp->right);    
        }
        if(temp->left != NULL) {
            s.push(temp->left);    
        }
    }
    return result;
}


