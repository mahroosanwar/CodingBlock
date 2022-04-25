//Sibling ( Binary Tree)

#include <iostream>
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

node* buildTreePreOrder(string s) {
    if(s == "true") {
        int data;
        cin >> data;
        node *root = new node(data); 

        string l;
        cin >> l;
        if(l == "true") {
            root->left = buildTreePreOrder(l);
        }

        string r;
        cin >> r;
        if(r == "true") {
            root->right = buildTreePreOrder(r);
        }
        return root;
    }
    return NULL;
}

void printSingles(node*root) {
    //base case 
    if(root == NULL) {
        return;
    }


    //rec case
    //1: if both right and left not null
    if(root->left != NULL && root->right != NULL) {
        printSingles(root->left);
        printSingles(root->right);
    }

    //2: if left not null -> print it
    else if(root->left != NULL) {
        cout << root->left->data << " ";
        printSingles(root->left);
        
    }

    //3: if right not NULL -> print it
    else if(root->right != NULL) {
        cout << root->right->data << " ";
        printSingles(root->right);
    }
}

int main() {
    node *root = buildTreePreOrder("true");

    printSingles(root);

    return 0;
}