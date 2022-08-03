// ArrayList of levels ( Binary Tree )

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

node* buildTreePreOrder(string s) {
    if(s == "true") {
        int data;
        cin >> data;

        node *root = new node(data);

        string l;
        cin >> l;
        if(l == "true"){
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

void ArrayList_of__Levels(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    cout << "[";        //for outer array
    cout << "[";        //for just first root element of BT
    while(!q.empty()){
        node *f = q.front();
        
        if(f == NULL) {
            cout << "]" ;       //new level occur -> close the arraylist of that level
            q.pop();

            if(!q.empty()) {
                cout << ", [";      //if array is not empty and new level occur -> starting of a new array with new aray list
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << f->data ;

            // if queue front is not empty means have more than a child in that level speprate them 
            //by ", "
            if(q.front() != NULL) {         
                cout << ", ";
            }
            if(f->left) {
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    cout << "]";            //for closing the outer arraylist
}

int main() {
    node *root = buildTreePreOrder("true");

    ArrayList_of__Levels(root);
    return 0;
}



// Given a Binary tree, write code to create a separate array list for each level. You should return an arraylist of arraylist.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// None

// Output Format
// Display the resulting arraylist of arraylist according to given sample examples.

// Sample Input
// 50 true 12 true 18 false false true 13 false false false
// Sample Output
// [[50], [12], [18, 13]]
