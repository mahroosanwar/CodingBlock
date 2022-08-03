// Level Order ( Zigzag )

#include<iostream>
#include<string>
#include<queue>
using namespace std;

class node{
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

node *buildTreePreOrder(string s) {
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

int height(node *root) {
    //base case
    if(root == NULL) {
        return 0;
    }

    //rec case
    return max(height(root->left), height(root->right)) + 1;
}

// this func prints from left to right, at level k
void printOddLevel(node* root, int k){
    //base case
    if(root == NULL) {
        return;
    }
    if(k==1){
        cout << root->data << " ";
    }

    printOddLevel(root->left, k-1);
    printOddLevel(root->right, k-1);
}

// this func prints from left to right, at level k
void printEvenLevel(node* root, int k){
    //base case
    if(root == NULL) {
        return;
    }
    if(k==1){
        cout << root->data << " ";
    }

    printEvenLevel(root->right, k-1);
    printEvenLevel(root->left, k-1);
}

void printLevelOrder_zigzag(node *root) {
    int h = height(root);

    for(int i=1; i<=h; i++) {
        if(i%2 != 0) {
            // odd-th height -- print left to right
            printOddLevel(root, i);
        }
        else{
            // even-th height -- print right to left
            printEvenLevel(root, i);
        }
    }
} 
int main() {
    node *root = buildTreePreOrder("true");
    
    printLevelOrder_zigzag(root);

    return 0;
}

// Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// None

// Output Format
// Display the values in zigzag level order in which each value is separated by a space

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// 10 30 20 40 50 60 73 
