// Tree Left View

#include<iostream>
#include<queue>
using namespace std;

class node {
public: 
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void buildLevelOrder(node *&root) {
    int d;
    cin >>d;

    root = new node(d);

    queue<node *> q;
    q.push(root);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();

        int left_d, right_d;
        cin >> left_d >> right_d;

        if(left_d != -1) {
            f->left = new node(left_d);
            q.push(f->left);
        }

        if(right_d != -1) {
            f->right = new node(right_d);
            q.push(f->right);
        }
    }
}

void treeLeftView(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    cout << root->data << " ";
    
    while(!q.empty()){
        node *f = q.front();
        q.pop();
        
        if(f == NULL) {
            
            if(!q.empty()) {
                //print front element after null in queue for left-most element when q is not empty
                node *temp = q.front();
                cout << temp->data << " ";

                q.push(NULL);
            }
        }
        else {
            if(f->left) {
                q.push(f->left);
            }
            if(f->right) {
                q.push(f->right);
            }
        }
    }
}

int main() {
    node *root = NULL;
    buildLevelOrder(root);

    treeLeftView(root);

    return 0;
}



// Given a binary tree , print its nodes from root to bottom as visible from left side of tree

// Input Format
// Level order input for the binary tree will be given.

// Constraints
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the left view of the tree

// Sample Input
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// Sample Output
// 1 2 4
// Explanation
// The tree looks like

//              1
//           /      \
//        2           3
//     /     \           \
//    4       5           6
// When viewed from the left , we would see the nodes 1,2 and 4.
