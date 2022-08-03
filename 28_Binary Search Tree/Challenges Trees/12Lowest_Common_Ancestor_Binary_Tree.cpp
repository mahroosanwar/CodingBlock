// Lowest Common Ancestor (Binary Tree )

#include <iostream>
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

void buildTree(node *&root) {
    int data;
    cin >> data;

    root = new node(data);

    string isleftPresent;
    cin >> isleftPresent;

    if(isleftPresent == "true") {
        buildTree(root->left);
    }

    string isRightPresent;
    cin >> isRightPresent;

    if(isRightPresent == "true") {
        buildTree(root->right);
    }
}

node *lca(node *root, int a, int b) {
    //base case
    if(root == NULL) {
        return NULL;
    }

    if(root->data == a || root->data == b) {
        return root;
    }

    //search in left and right subtree
    node *leftAns = lca(root->left, a, b);
    node *rightAns = lca(root->right, a, b);

    if(leftAns != NULL && rightAns != NULL) {
        return root;
    }

    if(leftAns != NULL) {
        return leftAns;
    }

    return rightAns;
}

int main()  {
    node *root = NULL;

    buildTree(root);

    int a, b;
    cin >> a >> b;

    node *ans = lca(root, a, b);
    cout << ans->data;

    return 0;
}



// Find LCA(Lowest Common Ancestor) of two elements in a Binary Tree.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL next two line contains 2 element of BT

// Constraints
// None

// Output Format
// Display the LCA value.

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 50
// 60
// Sample Output
// 10
