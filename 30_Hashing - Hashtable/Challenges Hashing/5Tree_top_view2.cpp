//Tree top View

#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* createTree() {
	int d;
	cin>>d;

	node *root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		node* f = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1 != -1) {
			f->left = new node(c1);
			q.push(f->left);
		}

		if(c2 != -1) {
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void topView1(node* root,int dis,int level,map<int, pair<int,int> > &mp) {
	if(root == NULL){
		return;
	}

	if(mp.find(dis) == mp.end() || level < mp[dis].second) {
		mp[dis] = {root->data, level};
	}

	topView1(root->left,dis-1,level+1,mp);
	topView1(root->right,dis+1,level+1,mp);
}

void topView(node* root) {
	map<int,pair<int,int>> mp;

	topView1(root,0,0,mp);

	for(auto x:mp) {
		cout<<x.second.first<<" ";
	}
}

int main() {
	node *root = createTree();

	topView(root);
	return 0;
}