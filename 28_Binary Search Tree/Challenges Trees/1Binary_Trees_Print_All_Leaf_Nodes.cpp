//Binary Trees -- Print All Leaf Nodes

#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderBuild(node *&root) {
    int data;
    cin >> data;

    queue<node*> q;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();

        int left_in;
        int right_in;

        cin >> left_in >> right_in;

        if(left_in != -1) {
            temp->left = new node(left_in);
            q.push(temp->left);
        }

        if(right_in != -1) {
            temp->right = new node(right_in);
            q.push(temp->right);
        }
    }
}

void printLeafNode(node *root) {
    //base case
    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    printLeafNode(root->left);
    printLeafNode(root->right);
}

int main() {
    node *root = NULL;

    levelOrderBuild(root);

    printLeafNode(root);

    return 0;
}
