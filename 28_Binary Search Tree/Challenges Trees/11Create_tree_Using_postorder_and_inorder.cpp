//Create Tree Using PostOrder and Inorder

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

//Create Tree Using PostOrder and Inorder
node *createTree(int *post, int *in, int s, int e, int n) {
    static int i = n-1;

    //base case
    if(s>e) {
        return NULL;
    }

    node *root = new node(post[i]);

    int index = -1;

    for(int j=0; j<=e; j++) {
        if(post[i] == in[j]) {
            index = j;
            break;
        }
    }

    i--;

    root->right = createTree(post, in, index+1, e, n);
    root->left = createTree(post, in, s, index-1, n);

    return root;
}

//display in pre-order format
void printTree(node *root) {
    //base case
    if(root == NULL) {
        return;
    }

    //rec case
    if(root->left) {
        cout << root->left->data;
    }
    else {
        cout << "END";
    }

    cout << " => " << root->data << " <= ";

    if(root->right) {
        cout << root->right->data;
    }
    else {
        cout << "END";
    }

    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n;
    cin >> n;
    int postOrder[n];

    for(int i=0; i<n; i++) {
        cin >> postOrder[i];
    }

    int m;
    cin >> m;
    int inOrder[m];

    for(int i=0; i<m; i++) {
        cin >> inOrder[i];
    }

    node *root = createTree(postOrder, inOrder, 0, n-1, n);

    printTree(root);

    return 0;
}


// Given postorder and inorder traversal of a tree. Create the original tree on given information.

// Input Format
// Enter the size of the postorder array N then add N more elements and store in the array, then enter the size of the inorder array M and add M more elements and store in the array. here M and N are same.

// Constraints
// None

// Output Format
// Display the tree using the display function

// Sample Input
// 3
// 1
// 3
// 2
// 3
// 1
// 2
// 3
// Sample Output
// 1 => 2 <= 3
// END => 1 <= END
// END => 3 <= END
