//Tree bottom view

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node *buildLevelOrder() {
    int d;
    cin >> d;

    queue<node *> q;
    node *root = new node(d);
    q.push(root);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if(c1 != -1) {
            f->left = new node(c1);
            q.push(f->left);
        }

        if(c2 != -1) {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

vector<int> TreeBottomView(node *root) {
    vector<int> ans;

    //base case
    if(root == NULL) {
        return ans;
    }

    map<int, int> m;    //line(horizontal distance from root) and data      
    queue<pair<node*, int> > q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        node* temp = it.first;
        int line = it.second;

        m[line] = temp->data;

        if(temp->left != NULL) {
            q.push({temp->left, line - 1});
        }

        if(temp->right != NULL) {
            q.push({temp->right, line + 1});
        }
    }

    for(auto it : m) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {

    node* root = buildLevelOrder();

    vector<int> v = TreeBottomView(root);

    for(auto i : v) {
        cout << i << " ";
    }    

    return 0;
}


// Given a binary tree , print the nodes in left to right manner as visible from below the tree

// Input Format
// Level order input for the binary tree will be given.

// Constraints
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the bottom view of the tree

// Sample Input
// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// Sample Output
// 4 2 6 3
// Explanation
// The tree looks like

//              1
//           /      \
//        2           3
//     /     \       /
//    4       5     6
// (Note that 5 and 6 are at the same position so we consider the right one to lower)
