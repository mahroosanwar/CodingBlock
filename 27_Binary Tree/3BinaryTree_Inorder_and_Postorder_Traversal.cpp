//Binary Tree - Inorder and Postorder Traversal

//Binary Tree - Preorder Build and Print

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//this will return address of root 
node* buildTree() {
    int d;
    cin >> d;

    if(d==-1) {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}   

//print preorder
void print(node *root) {
    if(root == NULL) {
        return;
    }

    //Otherwise , print root first followed by subtrees(children)
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

//print inorder
void printIn(node *root) {
    if(root == NULL) {
        return;
    }

    //Otherwise , print root first followed by subtrees(children)
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

//print postorder
void printPost(node *root) {
    if(root == NULL) {
        return;
    }

    //Otherwise , print root first followed by subtrees(children)
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

int main() {
    node *root = buildTree();
    
    print(root);
    cout << endl;

    printIn(root);
    cout << endl;

    printPost(root);
    cout << endl;

    return 0;
}