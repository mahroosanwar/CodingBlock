//Binary Tree - Level Order Print Recursive

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    //constructor
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    } 
};

node* buildTree() {
    int d;
    cin >> d;

    if(d==-1) return NULL;

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

//print preorder 
void print(node *root) {

    if(root==NULL) {
        return;
    }
    cout << root->data <<" ";
    print(root->left);
    print(root->right);
}

// print inorder
void printIn(node *root) {

    if(root==NULL){
        return;
    }

    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

//print postorder
void printPost(node *root) {

    if(root==NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

//heightof Binary tree
int height(node *root) {
    if(root==NULL) {
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

//print kth level
void printKthLevel(node*root, int k) {
    if(root==NULL) {
        return;
    }

    if(k==1) {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}
//level order print recursive
void printLevelOrder(node *root) {
    int H = height(root);

    for(int i=1; i<=H; i++) {
        printKthLevel(root, i);
        cout << endl;
    }
}

int main() {
    node *root = buildTree();

    print(root);
    cout << endl;

    printIn(root);
    cout << endl;

    printPost(root);
    cout << endl;

    cout << height(root) << endl << endl;

    printLevelOrder(root);
    return 0;
}