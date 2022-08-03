//Build BST

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

node *buildTree(int *arr, int s, int e) {
    if(s>e) {
        return NULL;
    }

    int mid = (s+e)/2;

    node *root = new node(arr[mid]);
    if(s==e) {
        return root;
    }

    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

void printPreOrderTree(node *root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        node *root = NULL;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];   
        }
        root = buildTree(arr, 0, n-1);

        printPreOrderTree(root);
        cout << endl;
    }
    return 0;
}


// You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

// Input Format
// First line contains integer t as number of test cases.
// Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers denoting the elements for the BST.

// Constraints
// 1 < t < 100
// 1< n < 1000

// Output Format
// For each testcase , print the preorder traversal of the BST in a new line.

// Sample Input
// 1
// 7
// 1 2 3 4 5 6 7
// Sample Output
// 4 2 1 3 6 5 7
// Explanation
// The tree looks like

//              4
//           /      \
//        2           6
//     /     \      /    \
//    1       3    5      7
// We print the preorder of the final tree.
