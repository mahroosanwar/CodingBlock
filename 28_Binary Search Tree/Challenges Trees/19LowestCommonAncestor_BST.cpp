//Lowest Common Ancestor ( BST )

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

//accept the old root node & returns the new root node
node *insertInBST(node *root, int data) {
    if(root == NULL) {
        return new node(data);
    }

    //rec case - Insert in subtree and Update Pointers
    if(data <= root->data) {
        root->left = insertInBST(root->left, data);
    }
    else {
        root->right = insertInBST(root->right, data);
    }

    return root;
}

node *lca(node *root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == a || root->data == b) {
        return root;
    }

    //search in the left and right subtree
    node *lans = lca(root->left, a, b);
    node *rans = lca(root->right, a, b);

    if(lans != NULL && rans != NULL) {
        return root;
    }

    if(lans != NULL) {
        return lans;
    }

    return rans;
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

    int a, b;
    cin >> a >> b;

    node *LCAans = lca(root, a, b);

    if(LCAans) {
        cout << LCAans->data;
    }
    
    return 0;
}



// Find LCA of two elements in a BST.

// Input Format
// Enter the number of nodes N and add N more numbers to the BST, then add the two numbers whose LCA is to be found.

// Constraints
// None

// Output Format
// Display the LCA value.

// Sample Input
// 4
// 5
// 3
// 2
// 7
// 7
// 5
// Sample Output
// 5
