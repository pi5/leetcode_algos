#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find (vector<int> &inorder, int value) {
    
    for(int i = 0; i < inorder.size(); i++) {
        if(inorder[i] == value) {
            return i;    
        }    
    }
    // Not found
    return -1;
}


TreeNode *buildTree_util(vector<int> &preorder, vector<int> &inorder, int &preindex, int in_start, int in_end) {

    if (in_start > in_end) return NULL;
     
    int rootval = preorder[preindex++];
    TreeNode *root = new TreeNode(rootval);
    if (in_start == in_end) return root;
   
    /* Using a map instead of find method has good speed benefits */ 
    int root_index = find(inorder, rootval);
    //cout << "------" << rootval << "  " << root_index << endl;
    root->left = buildTree_util(preorder, inorder, preindex, in_start, root_index - 1);
    root->right = buildTree_util(preorder, inorder, preindex, root_index + 1, in_end);

    return root;
}


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preindex = 0;
    return buildTree_util(preorder, inorder, preindex, 0, inorder.size()-1);    
}


void print_inorder(TreeNode *root) {
    if (root == NULL) return;
    print_inorder(root->left);
    cout << root->val << " ";    
    print_inorder(root->right); 
}


void print_preorder(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << " ";    
    print_preorder(root->left);
    print_preorder(root->right); 
}


int main() {
    
    int in[] = {4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};
    
    int size = sizeof(pre)/sizeof(pre[0]);

    vector<int> preorder(pre, pre + size);
    vector<int> inorder(in, in + size);

    TreeNode *root = buildTree(preorder, inorder);

    cout << endl;
    print_inorder(root);
    cout << endl;

    cout << endl;
    print_preorder(root);
    cout << endl;
}
