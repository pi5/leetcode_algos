/*
 *    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 *    For example:
 *    Given binary tree {3,9,20,#,#,15,7},
 *        3
 *       / \
 *      9  20
 *        /  \
 *       15   7
 *    return its level order traversal as:
 *    [
 *      [3],
 *      [9,20],
 *      [15,7]
 *    ]
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);
    
    int curr_level = 1;
    int next_level = 0;
    vector<int> temp;

    while(!q.empty()) {
    
        TreeNode* n = q.front();
        q.pop();
        curr_level--;

        temp.push_back(n->val);

        if (n->left) {
            next_level++;
            q.push(n->left);    
        }

        if (n->right) {
            next_level++;
            q.push(n->right);    
        }

        if(curr_level == 0) {
            result.push_back(temp);
            temp.clear();
            curr_level = next_level;
            next_level = 0;
        }
        
    }

    return result;
};

void print (vector<vector<int> > & v) {

    cout << endl;
    for (int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";    
        }    
        cout << endl;
    }    
    cout << endl;
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
    d->left = h;


    vector<vector<int> > result  = levelOrder(a);
    print(result);
}

