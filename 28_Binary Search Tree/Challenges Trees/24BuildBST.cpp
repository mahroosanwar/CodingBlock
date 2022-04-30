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