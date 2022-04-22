//Sum of the nodes (Binary tree)

#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left  = NULL;
        right = NULL;
    }
};

//build recursively nodes first all left then right
void buildTree(node *&root) {    
    int data;
    cin >> data;

    root = new node(data);

    string isleftPresent, isrightPresent;
    
    cin >> isleftPresent;
    if(isleftPresent == "true") {
        buildTree(root->left);
    }

    cin >> isrightPresent;
    if(isrightPresent == "true") {
        buildTree(root->right);
    }
}

int sum_of_Nodes(node *root) {
    //base case
    if(root == NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }

    //rec case
    int sumLeft = sum_of_Nodes(root->left);
    int sumRight = sum_of_Nodes(root->right);

    int totalSum = sumLeft + sumRight + root->data;

    return totalSum;
}

int main() {

    node *root = NULL;

    buildTree(root);

    int sum = sum_of_Nodes(root);
    cout << sum << endl;

    return 0;
}