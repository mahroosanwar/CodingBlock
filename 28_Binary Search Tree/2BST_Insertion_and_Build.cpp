// 2 Insertion & Build (BST)

#include<iostream>
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

//accept the old root node & returns the new root node
node* insertInBST(node *root, int data) {
    if(root==NULL) {
        return new node(data);
    } 

    //rec case - Insert in subtree and Update Pointers
    if(data<=root->data) {
          root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }

    return root;
}

node* build() {
    //read a list of number  till -1 and insert these number will be inserted in BST
    int d;
    cin >> d;

    node *root = NULL;
    while(d!=-1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

//print the bst lever by level
void bfs(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *f = q.front();
        if(f==NULL) {
            cout << endl;
            q.pop();

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << f->data << " ";
            q.pop();

            if(f->left) {
                q.push(f->left);
            }
            if(f->right) {
                q.push(f->right);
            }
        }
    }
    return;
}

//inorder print
void inorder(node *root) {
    if(root == NULL ){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    //5 3 7 1 6 8 -1
    //You can give any input to generate the same tree(like lever-order, in-order, post-order)
    node *root = build();

    inorder(root);
    cout << endl;
    bfs(root);
    cout << endl;
    
    return 0;
}
