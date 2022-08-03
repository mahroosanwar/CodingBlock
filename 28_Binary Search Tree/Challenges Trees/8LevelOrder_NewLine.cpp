//Level Order ( New Line

#include<iostream>
#include<queue>
#include<string>
using namespace std;

class node{
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

void buildTreePreOrder(node *&root) {
    int data;
    cin >> data;

    root = new node(data);

    string l;
    cin >> l;
    if(l == "true") {
        buildTreePreOrder(root->left);
    }

    string r;
    cin >> r;
    if(r == "true") {
        buildTreePreOrder(root->right);
    }
}

void printLevelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();
        if(f == NULL) {
            cout << endl;

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << f->data << " ";

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

    buildTreePreOrder(root);

    printLevelOrder(root);    

    return 0;
}


// Given a binary tree. Print the level order traversal, make sure each level start at a new line.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// None

// Output Format
// Print the level order in which the different levels are in different lines, all the values should be in a space separated manner

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// 10 
// 20 30 
// 40 50 60 73
