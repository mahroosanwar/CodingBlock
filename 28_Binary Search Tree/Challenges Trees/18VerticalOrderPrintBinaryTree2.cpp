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



// You will be given a Binary Tree. Your task is to print the binary tree in Vertical Fashion. The image below describes how we define a vertical traversal of a tree.

// Input Format
// You will be given an Integer N denoting the number of levels in the corresponding tree. On the next line you will be given (2^N)-1 order integers denoting the level order input for the tree. If at any level any node is absent then that will denoted by -1 and every integer other than -1 shows the presence of a node at that level.

// Constraints
// 1 <= N <= 10^5

// Output Format
// Print all nodes of a given column in the same line.

// Image

// Sample Input
// 4 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
// Sample Output
// 4 2 1 5 6 3 8 7 9
// Explanation
// Refer to the image.
// We are to simply print the traversal of each vertical level from left to right , using pre order traversal. {4} {2} {1 5 6} {3 8} {7} {9}
