//Create tree ( Using preorder and inorder)

#include<iostream>
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

//create Tree using Inorder And Preorder Array
node *createTree(int *in, int *pre, int s, int e) {
    static int i=0;

    //base case
    if(s>e) {
        return NULL;
    }
    
    node *root = new node(pre[i]);

    int index = -1;

    for(int j=s; j<=e; j++) {
        if(in[j] == pre[i]) {
            index = j;
            break;
        }
    }

    i++;

    root->left = createTree(in, pre, s, index-1);
    root->right = createTree(in, pre, index+1, e);

    return root;
}

//A modified preorder function. For each node , first print its left child's data ,
//then the data of the root itself , then the data of its right child
void printTree(node *root) {
    //base case
    if(root == NULL) {
        return;
    }

    if(root->left == NULL) {
        cout << "END";
    }
    else {
        cout << root->left->data;
    }

    cout << " => " << root->data << " <= ";

    if(root->right == NULL) {
        cout << "END";
    }
    else{
        cout << root->right->data;
    }
    
    cout << endl;
    printTree(root->left);
    printTree(root->right);
    
}

int main() {
    int m;
    cin >> m;
    int pre_arr[m];

    for(int i=0; i<m; i++) {
        cin >> pre_arr[i];
    }

    int n;
    cin >> n;
    int in_arr[n];

    for(int i=0; i<n; i++) {
        cin >> in_arr[i];
    }

    node *root = createTree(in_arr, pre_arr, 0, n-1);

    printTree(root);
    return 0;
}