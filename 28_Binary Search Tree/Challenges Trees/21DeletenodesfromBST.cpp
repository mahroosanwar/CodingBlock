//Delete nodes from BST

#include<iostream>
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

node *insertInBST(node *root, int data) {
    //base case
    if(root == NULL) {
        return new node(data);
    }

    //rec case - Insert in subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left, data);
    }
    else {
        root->right = insertInBST(root->right, data);
    }

    return root;
}

//Delete Nodes in BST
node *deleteNode(node* root, int data) {
    if(root == NULL ){
        return NULL;
    }

    else if(data < root->data) {
        //call fun in left subtree
        root->left = deleteNode(root->left, data);
        return root;
    }

    else if(data == root->data) {
        //found the node to delete : 3 cases

        //1: node with zero childern
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //2: when you have only one child
        if(root->left != NULL && root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }

        //3: delete node wtth 2 children
        node *replace = root->right;

        //find the inorder successor from the right subtree
        while(replace->left != NULL) {
            replace = replace->left;
        }

        root->data = replace->data;

        //now we delete the replacement node from the right subtree
        root->right = deleteNode(root->right, replace->data);

        return root;
    }
    else {
        //we are going to righthand-side to found the node to rec
        //call to delete that node from the right subtree 
        root->right = deleteNode(root->right, data);
        return root;
    }
}

void printPreOrder(node *root) {
    if(root == NULL) {
        return;
    }

    //rec case
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        node *root = NULL;

        for(int i=0; i<n; i++) {
            int data;
            cin >> data;

            root = insertInBST(root, data);
        }

        int m;
        cin >> m;

        for(int i=0; i<m; i++) {
            int del_data;
            cin >> del_data;
            root = deleteNode(root, del_data);
        }

        printPreOrder(root);
        cout << endl;
    }
    return 0;
}



// You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
// Note : In case of node with 2 children, consider its inorder successor as its replacement.

// Input Format
// First line contains integer t as number of test cases.
// Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.

// Constraints
// 1 < t < 100
// 1< n,m < 1000

// Output Format
// Print the preorder traversal of the final resultant tree.

// Sample Input
// 1
// 7
// 5 3 2 4 7 6 8
// 3
// 2 3 5
// Sample Output
// 6 4 7 8 
// Explanation
// Initially the tree looks like

//              5
//           /      \
//        3           7
//     /     \      /    \
//    2       4    6      8
// After the deletion , the tree looks like

//                6
//             /     \
//            4       7
//                      \
//                       8
// We print the preorder of the final tree.
