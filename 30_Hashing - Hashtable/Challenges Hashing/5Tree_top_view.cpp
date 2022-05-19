//Tree top view

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* buildLevelOrder() {
    queue<node*> q;

    int d;
    cin >> d;

    node* root = new node(d);
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

void verticalOrderMap(node*root,int d,map<int,vector<int> > &m) {
	if(root==NULL) {
		return;
	}

	m[d].push_back(root->data);
	verticalOrderMap(root->left,d-1,m);
	verticalOrderMap(root->right,d+1,m);
}

int main() {

    node* root = buildLevelOrder();

    map<int, vector<int> > m;
    int d = 0;
    verticalOrderMap(root, d, m);

    // from verticle view by using break print make top view
    for(auto it : m) {
        for(auto x : it.second) {
            cout << x << " ";
            break;          
        }
    }

    return 0;
}


// Given a binary tree , print the nodes in left to right manner as visible from above the tree

// Input Format
// Level order input for the binary tree will be given.

// Constraints
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the top view of the tree

// Sample Input
// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// Sample Output
// 4 2 1 3
// Explanation
// The tree looks like

//              1
//           /      \
//        2           3
//     /     \       /
//    4       5     6
// When viewed from the top , we would see the nodes 4, 2, 1 and 3.
