//Tree Right View

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
        right =NULL;
    }
};

void buildLevelOrder(node *&root) {
    int d;
    cin >> d;

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

void treeRightView(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();

        if(f == NULL) {
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            //if q.front == NULL f->data is the right most data of that level
            if(!q.front()) {
                cout << f->data << " ";
            }

            //push left root
            if(f->left) {
                q.push(f->left);
            }

            //push right root
            if(f->right) {
                q.push(f->right);
            }
        }
    }
}

int main() {
    node *root = NULL;
    buildLevelOrder(root);

    treeRightView(root);

    return 0;
}


// Given a binary tree , print its nodes from root to bottom as visible from right side of tree

// Input Format
// Level order input for the binary tree will be given.

// Constraints
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the right view of the tree

// Sample Input
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// Sample Output
// 1 3 6
// Explanation
// The tree looks like

//              1
//           /      \
//        2           3
//     /     \           \
//    4       5           6
// When viewed from the left , we would see the nodes 1,3 and 6.
