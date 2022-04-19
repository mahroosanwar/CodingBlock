//BST to Sorted Linked List Convert / Flatten a Tree

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

//Define pair class (calling it LinkedList) 
class LinkedList {
public:
    node*head;
    node*tail;
};

LinkedList flatten(node *root) {
    //we are not going to change node structure at any point 
    //we are accepting the root node of the tree and  we are returning in the form of Linked List(pair of the head and tail pointer)
    LinkedList l;

    if(root == NULL) {
        l.head = l.tail = NULL;
    }

    //1: only leaf onde
    if(root->left == NULL && root->right == NULL) {
        l.head = l.tail = root;
        return l;
    }

    //2: left is not null

    if(root->left != NULL && root->right == NULL) {
        LinkedList leftLL = flatten(root->left);         //Linked list comming from left hand side 
        
        //to connect the tail of the linked list to the root node
        leftLL.tail->right = root;

        //new head is same of the left linked list
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    //3: right is not NULL
    if(root->left == NULL && root->right != NULL) {
        LinkedList rightLL = flatten(root->right);

        //make root to point to head from right new head (get from rightLL) and update the root node as head
        root->right = rightLL.head;

        //new head is going to be:
        l.head = root;
        //new tail is going to be:
        l.tail = rightLL.tail;
        return l;
    }

    //4: Both side are not NULL;
    //it is the case of the postorder traversal( left , right , and do some work on the root node)
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;

    return l;
}

int main() {
    //5 3 7 1 6 8 -1
    //You can give any input to generate the same tree(like lever-order, in-order, post-order)
    node *root = build();
    inorder(root);
    cout << endl;
    bfs(root);
    cout << endl;

    LinkedList l = flatten(root);
    node*  temp = l.head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->right;
    }
    return 0;
}
