// Remove the leaves ( Binary Tree )
#include<iostream>
#include<string>
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

node *removeLeaves(node *root) {
    if(root == NULL) {
        return root;
    }

    if(!root->left && !root->right) {
        delete root;
        return NULL;
    }

    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);

    return root;
}

void printTree(node *root) {
    if(root == NULL) {
        return;
    }

    if(root->left){
        cout << root->left->data << " => ";
    }
    else{
        cout << "END => "; 
    }

    cout << root->data;

    if(root->right) {
        cout << " <= " << root->right->data;
    }
    else {
        cout << " <= END";
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}


int main() {
    node *root = NULL;
    buildTreePreOrder(root);

    removeLeaves(root);

    printTree(root);

    return 0;
}


// Given a binary tree, remove all the leaves from the tree

// Input Format
// Enter the value of the nodes of the tree

// Constraints
// None

// Output Format
// Display the tree in which all the leaves have been removed in pre-order traversal in the following format :
// Left->data => Root->data <= Right->Data
// Output END if left or right node is NULL

// Sample Input
// 50 true 12 true 18 false false false false
// Sample Output
// 12 => 50 <= END
// END => 12 <= END
