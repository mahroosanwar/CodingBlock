#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node*left;
	Node*right;
	Node(int d){
		data = d;
		left = right = NULL;
	}
};

Node* createTree(Node* root){
	int d;
	cin>>d;
	root = new Node(d);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;
		if(c1 != -1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2 != -1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void vertical(Node* root,int d,map<int,vector<int>>&map){
    if(root== NULL){
        return;
    }
    map[d].push_back(root->data);
    
    vertical(root->left,d-1,map);
    vertical(root->right,d+1,map);
}
int main(){
    int level;
    cin>>level;
	Node* root = nullptr;
	root =createTree(root);
    int d=0;
    map<int,vector<int>>map;
	vertical(root,d,map);
    for(auto p:map){
        for(auto x:p.second){
            cout<<x<<" ";
        }
    }
	return 0;
}