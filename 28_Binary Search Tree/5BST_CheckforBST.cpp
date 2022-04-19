//BST - Check for BS

//BST - Deletion

//BST - Searching

// 2 Insertion & Build (BST)

#include<iostream>
#include<queue>
#include<climits>
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

//searching
bool search(node *root , int data){
    if(root == NULL) {
        return false;
    }
    if(root->data == data) {
        return true;
    }

    //rec search  in left and right

    if(data<=root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

//Delete the node form BST
node* deleteInBST(node*root, int data) {
    if(root==NULL) {
        return NULL;
    }

    else if(data<root->data) {
        //call deleteInBST in left Subtree
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if(data==root->data) {
        //found the node to delete : 3 cases
        
        //1: node with zero children - leaf Node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //2: When You have only 1 child
        if(root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        //3: Delete node with 2 children 
        node* replace = root->right;

        //find the inorder successor from right subtree
        while(replace->left != NULL) {
            replace = replace->left;
        }

        root->data = replace->data;
        
        //now we delete the replacement node from the right subtree
        root->right = deleteInBST(root->right, replace->data);

        return root;
    }
    else{
        //we are going to righthand-side to found the node to rec
        //call to delete that node from the right subtree 
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

//Check BST or Not (top Down Approach)
bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX) {
    if(root==NULL) {
        return true;
    }

    //at every node check
    if(root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)) {
        return true;
    }

    return false;
} 

int main() {
    //5 3 7 1 6 8 -1
    //You can give any input to generate the same tree(like lever-order, in-order, post-order)
    node *root = build();

    bfs(root);
    cout << endl;

    if(isBST(root)) {
        cout << "Yes";
    }
    else {
        cout << "Not a BST!";
    }
    return 0;
}
