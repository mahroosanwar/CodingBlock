//Structurally Identical (Binary Tree)

#include<iostream>
#include<string>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void buildTreePre_Order(node *&root) {
    int data;
    cin >> data;

    root = new node(data);

    string isleftPresent, isrightPresent;

    cin >> isleftPresent;
    if(isleftPresent == "true") {
        buildTreePre_Order(root->left);
    }

    cin >> isrightPresent; 
    if(isrightPresent == "true") {
        buildTreePre_Order(root->right);
    }
}

bool isIdentical(node *root1, node *root2) {
    //1. both empty
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    // 2. both non-empty -> compare them
    if(root1 != NULL && root2 != NULL) {
        return (isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
    }

    // 3. one empty, one not -> false
    return false;
} 

int main() {
    node *root1 = NULL;
    node *root2 = NULL;
    
    buildTreePre_Order(root1);
    buildTreePre_Order(root2);

    if(isIdentical(root1, root2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}


// Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// 1 <= N <= 10^4

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true
// Explanation
// The given two trees have the exact same structure and hence we print true.
