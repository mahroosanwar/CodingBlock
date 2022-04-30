// Replace with Sum of greater nodes

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

//build tree from inorder array
node *buildTree(int *inOrder, int s, int e) {
    if(s>e) {
        return NULL;
    } 

    int mid = (s+e)/2;
    node *root = new node(inOrder[mid]);

    if(s == e) {
        return root;
    }

    root->left = buildTree(inOrder, s, mid-1);
    root->right = buildTree(inOrder, mid+1, e);

    return root;
}

int ReplaceWithGreaterSum(node *root, int largerSum) {
    if(root == NULL) {
        return 0;
    }
	
    // Calling to right , rans will store sum of all larger node
    int rans = ReplaceWithGreaterSum(root->right, largerSum);

	// storing original root->data because we will update this
    int oldRootData = root->data;
    root->data = root->data + rans + largerSum;

	// call to left and update left side node as well, here we have to pass sum of all right side node value
    int lans = ReplaceWithGreaterSum(root->left, root->data);

	// Returning sum of this subtree including root->data
    return lans + rans + oldRootData;
}

void printPreOrder(node *root) {
    if(root== NULL) {
        return;
    }

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    int N;
    cin >> N;
    int inOrder[N];
    
    for(int i=0; i<N; i++) {
        cin >> inOrder[i];
    }

    node *root = buildTree(inOrder, 0, N-1);

    ReplaceWithGreaterSum(root, 0);

    printPreOrder(root);

    return 0;
}