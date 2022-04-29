// Tree Left View

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
        left = NULL;
        right = NULL;
    }
};

void buildLevelOrder(node *&root) {
    int d;
    cin >>d;

    root = new node(d);

    queue<node *> q;
    q.push(root);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();

        int left_d, right_d;
        cin >> left_d >> right_d;

        if(left_d != -1) {
            f->left = new node(left_d);
            q.push(f->left);
        }

        if(right_d != -1) {
            f->right = new node(right_d);
            q.push(f->right);
        }
    }
}

void treeLeftView(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    cout << root->data << " ";
    
    while(!q.empty()){
        node *f = q.front();
        q.pop();
        
        if(f == NULL) {
            
            if(!q.empty()) {
                //print front element after null in queue for left-most element when q is not empty
                node *temp = q.front();
                cout << temp->data << " ";

                q.push(NULL);
            }
        }
        else {
            if(f->left) {
                q.push(f->left);
            }
            if(f->right) {
                q.push(f->right);
            }
        }
    }
}

int main() {
    node *root = NULL;
    buildLevelOrder(root);

    treeLeftView(root);

    return 0;
}