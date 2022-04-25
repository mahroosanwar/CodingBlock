//Level Order ( New Line

#include<iostream>
#include<queue>
#include<string>
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

void buildTreePreOrder(node *&root) {
    int data;
    cin >> data;

    root = new node(data);

    string l;
    cin >> l;
    if(l == "true") {
        buildTreePreOrder(root->left);
    }

    string r;
    cin >> r;
    if(r == "true") {
        buildTreePreOrder(root->right);
    }
}

void printLevelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();
        if(f == NULL) {
            cout << endl;

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << f->data << " ";

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

    buildTreePreOrder(root);

    printLevelOrder(root);    

    return 0;
}