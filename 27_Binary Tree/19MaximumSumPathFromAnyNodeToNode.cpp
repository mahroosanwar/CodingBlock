//Maximum Sum Path From Any Node To Node

//Lowest Common Ancestor (LCA)
//Nodes at Distance K from Given Node

//Binary Tree - Right View

//Binary Tree - Build Tree from PreOrder and Postorder

//Binary Tree - Build Balanced Tree From Array

//Binary Tree - Height Balanced Tree

//Binary Tree Solution - Sum Replacement

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

int replaceSum(node *root) {
    if(root==NULL) {
        return 0;
    }

    if(root->left==NULL && root->right==NULL) {
        return root->data;
    }  

    //recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return  temp + root->data;
}

class HBPair {
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node*root) {
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    //rec case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height, right.height) + 1;
    
    if(abs(left.height - right.height)<=1 && left.balance && right.balance) {
        p.balance = true;
    }
    else{
        p.balance = false;
    }

    return p;
}

//build a height balance tree from array
node* buildTreeFromArray(int *a, int s, int e) {
    //base case
    if(s>e) return NULL;

    //rec case

    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid-1);
    root->right = buildTreeFromArray(a, mid+1, e);
    
    return root;
}

node *createTreeFromTrav(int *in, int *pre, int s, int e) {     //s, and e is for inorder array
    static int i=0; 
    //base case
    if(s>e) {
        return NULL;
    }

    //rec case
    node* root = new node(pre[i]);

    int index = -1;

    for(int j=s; j<=e; j++) {
        if(in[j] == pre[i]) {
            index = j;
            break;
        }
    }

    i++;

    root->left = createTreeFromTrav(in, pre, s, index-1);
    root->right = createTreeFromTrav(in, pre, index+1, e);

    return root;
}

void printRightView(node* root, int level, int &maxlevel) {

    if(root==NULL) {
        return;
    }

    if(maxlevel < level) {
        //have discovred new level
        cout << root->data << " ";
        maxlevel = level;
    }

    //right
    printRightView(root->right, level+1, maxlevel);
    printRightView(root->left, level+1, maxlevel);
}

void levelOrderBuild(node*&root) {
    int d;
    cin >> d;

    root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* n = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            n->left = new node(c1);
            q.push(n->left);
        }
        if (c2 != -1) {
            n->right = new node(c2);
            q.push(n->right);
        }
    }
}

void levelOrderPrint(node*root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *n = q.front();
        if(n == NULL) {
            cout << endl;
            q.pop();

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << n->data << " ";

            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
    }
}

istream& operator>>(istream &is, node*root) {
    levelOrderBuild(root);
    return is;
}

ostream& operator<<(ostream &os, node*root) {
    levelOrderPrint(root);
    return os;
}

//Nodes at Distance K from Given Node
// helper function (-> print all the node which are below kth level from the given node)
void printAtLevelK(node *root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printAtDistanceK(node*root, node*target, int k) {
    //base case
    if(root == NULL) {
        return -1;      //if root is null then you cross the leaf node  so you have to return from there
    }

    //otherwise
    //if reach the target node
    if(root==target) {
        printAtLevelK(target, k);
        return 0;
    }

    //next step ancestor
    int DL = printAtDistanceK(root->left, target, k);   //distance of target node in left subtree

    if(DL != -1) {

        //again there are 2 cases
        //ancestor itself or you need to go the the right ancestor

        if(DL+1 == k) {
            cout << root->data << " ";
        }
        else {
            printAtLevelK(root->right, k-2-DL);
        }
        return 1 + DL;
    }

    int DR = printAtDistanceK(root->right, target, k);

    if(DR != -1){
        if(DR + 1 == k) {
            cout << root->data << " ";
        }
        else {
            printAtLevelK(root->left, k-2-DR);
        }
        return 1 + DR;
    }

    //node was not present in left and right subtree
    return -1;
}

//Lowest Common Ancestor (LCA)

node* lca(node* root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == a or root->data == b) {
        return root;
    }

    //search in the left and right subtree

    node* leftans = lca(root->left, a, b);
    node* rightans = lca(root->right, a, b);

    if(leftans != NULL && rightans != NULL) {
        return root;
    }

    if(leftans != NULL) {
        return leftans;
    }

    return rightans;
}

//Maximum Sum Path From Any Node To Node
class Pair2 {
public:
    int branchSum;
    int maxSum;

    Pair2() {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair2 maxSumPath(node *root) {
    Pair2 p;

    if(root==NULL) {
        return p;
    }

    Pair2 left = maxSumPath(root->left);
    Pair2 right = maxSumPath(root->right);

    //comstructor two values
    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));
    // branch sum of the current root
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}

int main() {
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();

    cout << "Max. Sum Path " << maxSumPath(root).maxSum << endl;
    return 0;
}