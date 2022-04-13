// Binary Tree - Diameter of Tree

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int data;
    cin >> data;

    if(data==-1){
        return NULL;
    }
    node *root = new node(data);

    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node* root){
    if(root==NULL) {
        return ;
    }

    cout << root->data << " ";;
    print(root->left);
    print(root->right);
}

int height(node *root) {
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
} 

int diameter(node *root) {
    if(root==NULL){
        return 0;
    }

    //height of left size
    int h1 = height(root->left);
    //height of right size
    int h2 = height(root->right);
    int opt1 = h1+h2;
    //diameter of the left 
    int opt2 = diameter(root->left);
    //diameter of the right 
    int opt3 = diameter(root->right);

    return max(max(opt1, opt2), opt3);
}

int main() {
    node* root = buildTree();
    // print(root);
    cout << diameter(root)<< endl;
}