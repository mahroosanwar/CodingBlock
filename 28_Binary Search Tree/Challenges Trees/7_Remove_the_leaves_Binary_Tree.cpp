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