//Tree Left View
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
    data=d;
    left=NULL;
    right=NULL;
    }
};
node*buildtree(){
    int d;
    cin>>d;
    node*root=new node(d);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*root1=q.front();
        q.pop();
        int a,b;
        cin>>a>>b;
        if(a!=-1){
            root1->left=new node(a);
            q.push(root1->left);
        }
        if(b!=-1){
            root1->right=new node(b);
            q.push(root1->right);
        }
    }
    return root;
}

void printleft(node*root,int level,int &maxlevel) {
    if(root==NULL)
        return;

    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }

    printleft(root->left,level+1,maxlevel);
    printleft(root->right,level+1,maxlevel);
}

int main() {
    node* root=buildtree();
    int maxlevel=-1;
    printleft(root,0,maxlevel);
    return 0;
}