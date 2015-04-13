
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* This function returns -1 if heights of left and right 
 * differ by more than 1, else it return the actual height */
int checkHeight (TreeNode *root) {
    
    if (root == NULL) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    int diff = rightHeight - leftHeight;

    if(abs(diff) > 1) return -1;
    
    return max(leftHeight, rightHeight)  + 1;
            
}

bool isBalanced(TreeNode *root) {
    if (checkHeight(root) == -1) return false;
    return true;
}


int main() {

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    TreeNode *h = new TreeNode(8);


    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;
    d->left = g;
    g->left = h;

    cout << isBalanced(a) << endl;

} 
