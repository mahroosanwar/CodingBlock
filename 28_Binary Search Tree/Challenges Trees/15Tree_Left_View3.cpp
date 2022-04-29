//Tree Left View

#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node*left;
	Node*right;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};



void buildleftSideView(Node* root,int level,unordered_map<int,int> &mp){
	if(root == NULL){
		return;
	}
	if(mp.find(level) == mp.end()){
		mp[level] = root->data;
	}
	buildleftSideView(root->left,level+1,mp);
	buildleftSideView(root->right,level+1,mp);
}

void leftView(Node * root){
	unordered_map<int,int> mp;
	buildleftSideView(root,1,mp);
	for (int i = 1; i <= mp.size(); i++)
		cout << mp[i] << " ";
}

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
		if(c1!=-1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
    return root;
}

int main(){
        Node *root=NULL;
        root=createTree(root);
        leftView(root);
        cout<<endl;
}