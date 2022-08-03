// Kth largest in BST

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
    if(root == NULL) {
        return new node(data);
    }

    if(data <= root->data) {
        root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }
    return root;
}

void kthLarget(node* root, int k, int &c) {
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if(root == NULL || c>=k) {
        return;
    }


    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLarget(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if(c==k) {
        cout << root->data;
        return;
    }

    // Recur for left subtree
    kthLarget(root->left, k, c);
}

int main() {
    int n;
    cin >> n;

    node *root = NULL;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        root = insertInBST(root, data);
    }

    int k;
    cin >> k;

    int c=0;
    kthLarget(root, k, c);

    return 0;
}



// Given a BST and an integer k, print the kth largest element in the BST without modifying the BST.

// Can you do it in O(n) time ?

// Input Format
// First line contains the number of nodes. Next line contains n space separated integers denoting the elements of the BST. Insert them into the BST as given in order. Third line contains a single line integer k

// Constraints
// Output Format
// Print the kth largest value in the BST

// Sample Input
// 6
// 4 2 3 9 5 1
// 3
// Sample Output
// 4
// Explanation
