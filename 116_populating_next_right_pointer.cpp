/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include<iostream>
#include<queue>
using namespace std;
 
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/* Using O(1) extra space */
void connect (TreeLinkNode *root) {
    
    if (root == NULL) return;
    TreeLinkNode *curr, *nextlevel;
    curr = root;
    nextlevel = root->left;
    
    while(curr->left != NULL) {
        curr->left->next = curr->right;
        if(curr->next != NULL) {
            curr->right->next = curr->next->left;
            curr = curr->next;    
        }
        else {
            curr->right->next = NULL;
            curr = nextlevel;
            nextlevel = nextlevel->left;    
        }
    }    
}


/* This solution uses a queue which makes it O(n) size */
void connect_using_queue(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode* marker = NULL;
    queue<TreeLinkNode*> q;
    
    q.push(root);
    q.push(marker);
    
    while(!q.empty()) {
        TreeLinkNode *temp = q.front();
        q.pop();
        if (temp != marker) {
            cout << temp->val;
            temp->next = q.front();
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        else {
            //cout << endl;
            if (q.empty()) break;
            q.push(marker);        
        }
    }
}


void print_list(TreeLinkNode* root) {
    
    cout << endl;
    while(root != NULL) {
        cout << root->val << " ";
        root = root->next;
    }    
    cout << endl;
}

/* Driver program to test solution */
int main() {
    TreeLinkNode a(1);    
    TreeLinkNode b(2);    
    TreeLinkNode c(3);    
    TreeLinkNode d(4);    
    TreeLinkNode e(5);    
    TreeLinkNode f(6);    
    TreeLinkNode g(7);    
    
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    connect(&a);
    cout << endl;

    print_list(&a);
    print_list(&b);
    print_list(&d);

}
