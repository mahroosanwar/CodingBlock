//Lever Order (zigzag) method - 2

#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* build(){
    int d;
    cin>>d;
    node*root=new node(d);

    string l;
    cin>>l;
    if(l=="true"){
    root->left=build();
    }
    string r;
    cin>>r;
    if(r=="true"){
        root->right=build();
    }
    return root;
}

void printZigZia(node*root){
    stack<node *> s1;
    stack<node *> s2;

    bool leftOrRight = true;
    s1.push(root);
    
    while(!s1.empty() or !s2.empty()) {
        int row = 0;
        if(s1.size() > s2.size()) {
            row = s1.size();
        } else {
            row = s2.size();
        }
        while(row--) {
            if(leftOrRight) {
                node *curr = s1.top();
                s1.pop();
                cout<<curr->data<<" ";
                if(curr->left)
                    s2.push(curr->left);
                if(curr->right)
                    s2.push(curr->right);
            } else {
                node *curr = s2.top();
                s2.pop();
                cout<<curr->data<<" ";
                if(curr->right)
                    s1.push(curr->right);
                if(curr->left)
                    s1.push(curr->left);
            }
        }
        leftOrRight = !leftOrRight;
    }
}
int main(){
    node*root=build();
    printZigZia(root);
    return 0;
}