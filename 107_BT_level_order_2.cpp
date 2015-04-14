
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root) {

    vector<vector<int> > result;
    if (root == NULL) return result;   

    /* We store data on this stack */
    stack<vector<int> > s;

    /* We use this queue for level order traversal */
    queue<TreeNode*> q;

    q.push(root);
    int curr_level = 1;
    int next_level = 0;

    vector<int> v;
    while (!q.empty()) {

        TreeNode *temp = q.front();

        /* We add value to vector corresponding to current level */
        v.push_back(temp->val);

        q.pop();
        curr_level--;

        if (temp->right) {
            q.push(temp->right);    
            next_level++;
        }        

        if (temp->left) {
            q.push(temp->left);
            next_level++;    
        }

        if(curr_level == 0) {
            s.push(v);
            v.clear();
            curr_level = next_level;
            next_level = 0;    
        }
    }

    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();    
    }

    return result;
}

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


    vector<vector<int> > result = levelOrderBottom(a);
    print(result);
} 
