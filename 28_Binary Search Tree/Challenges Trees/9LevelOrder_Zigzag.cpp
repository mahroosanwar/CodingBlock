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