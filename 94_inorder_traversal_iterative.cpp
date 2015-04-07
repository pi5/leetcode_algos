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

void inorderTraversal_recursive_util(TreeNode *root, vector<int> &result) {
   if(root == NULL) return;
   inorderTraversal_recursive_util(root->left, result);
   result.push_back(root->val);     
   inorderTraversal_recursive_util(root->right, result);
}


vector<int> inorderTraversal_recursive(TreeNode *root) {
    vector<int> result;
    inorderTraversal_recursive_util(root, result);
    return result;
}

/* Solution one */
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL) return result;

    stack<TreeNode*> s;
    
    TreeNode *t = root;
    s.push(root);
    while(!s.empty() || t != NULL) {
        while(t != NULL) {
            if(t != root) {
                s.push(t);
            }    
            t = t->left;    
        }   

        t = s.top();
        s.pop();
        result.push_back(t->val);

        if (t->right != NULL) {
            t = t->right;    
        }
        else {
            t = NULL;    
        }
    }
    return result;            
}


/* Solution 2: Easier to read */
vector<int> inorderTraversal2 (TreeNode *root) {
    vector<int> result;
    if (root == NULL) return result;
    
    stack<TreeNode*> s;
    bool done = false; 
    TreeNode *curr = root;
    while (!done) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;    
        }
        else {
            if (!s.empty()) {
                curr = s.top();
                s.pop();
                result.push_back(curr->val);
                curr = curr->right;    
            }
            else {
                done = true;    
            }
        }
    }   
    return result;
}


void print_result (vector<int> &v) {
    cout << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";    
    }   
    cout << endl;
}

int main() {
    TreeNode a(1);        
    TreeNode b(2);        
    TreeNode c(3);        
    TreeNode d(4);        
    TreeNode e(5);        
    TreeNode f(6);        
    TreeNode g(7);        
    TreeNode h(8);        
   
    a.left = &b; a.right = &c;
    //b.left = &d; b.right = &e;
    b.right = &d; b.left = &e;
    c.left = &f; c.right = &g;
    d.right = &h;

    vector<int> result1 = inorderTraversal_recursive(&a);
    vector<int> result2 = inorderTraversal(&a);
    vector<int> result3 = inorderTraversal2(&a);

    print_result(result1);
    print_result(result2);
    print_result(result3);
}
