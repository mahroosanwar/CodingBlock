//Binary Tree - Diameter of the Tree Optimized Approach

//Binary Tree - Count and Sum Nodes

//Binary Tree Level Order Traversal - II

//Binary Tree BFS Traversal-I

//Binary Tree - Level Order Print Recursive

#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    //constructor
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    } 
};

node* buildTree() {
    int d;
    cin >> d;

    if(d==-1) return NULL;

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

//print preorder 
void print(node *root) {

    if(root==NULL) {
        return;
    }
    cout << root->data <<" ";
    print(root->left);
    print(root->right);
}

// print inorder
void printIn(node *root) {

    if(root==NULL){
        return;
    }

    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

//print postorder
void printPost(node *root) {

    if(root==NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

//heightof Binary tree
int height(node *root) {
    if(root==NULL) {
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

//print kth level
void printKthLevel(node*root, int k) {
    if(root==NULL) {
        return;
    }

    if(k==1) {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}
//level order print recursive
void printLevelOrder(node *root) {
    int H = height(root);

    for(int i=1; i<=H; i++) {
        printKthLevel(root, i);
        cout << endl;
    }
}

void bfs(node * root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* f = q.front();
        if(f==NULL) {
            cout << endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout << f->data << " ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

int count(node*root) {
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sum(node*root) {
    if(root==NULL){
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

int diameter(node *root) {
    if(root==NULL){
        return 0;
    }

    //height of left size
    int h1 = height(root->left);
    //height of right size
    int h2 = height(root->right);
    int opt1 = h1+h2;
    //diameter of the left 
    int opt2 = diameter(root->left);
    //diameter of the right 
    int opt3 = diameter(root->right);

    return max(max(opt1, opt2), opt3);
}

//diameter optimize approach
//same as pair inbuilt

class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root) {
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    //left subtree
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}



int main() {
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();

    Pair p = fastDiameter(root);

    cout << p.height << endl;
    cout << p.diameter << endl;

    return 0;
}