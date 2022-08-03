//Replace with Sum ( BST )

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};


int ReplaceSum(node *root, int &largerSum)
{
    if (root == NULL)
        return 0;

    // Calling to right , rans will store sum of all larger node
    int rans = ReplaceSum(root->right, largerSum);

    // storing original root->data because we will update this
    int oldRootData = root->data;
    root->data = largerSum; // replace with larger sum
	largerSum += oldRootData; // tehn add to it

    // call to left and update left side node as well, here we have to pass sum of all right side node value
    int lans = ReplaceSum(root->left, largerSum); // pass larger sum not toot->data

    // Returning sum of this subtree including root->data
    return lans + rans + oldRootData;
}

void printPre(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Print root
    if (root->left)
    {
        cout << root->left->data << " => ";
    }
    else
    {
        cout << "END => ";
    }
    cout << root->data << " <= ";
    if (root->right)
    {
        cout << root->right->data << endl;
    }
    else
    {
        cout << "END" << endl;
    }

    // Print left subtree
    printPre(root->left);

    // Print right subtree
    printPre(root->right);
}

node*insertinBST(node*root,int d){ // build one by one else structure will change (its correct but not according to the test cases here)
	if(root==NULL){
		return new node(d);
	}
	if(d <= root->data){
		root->left = insertinBST(root->left,d);
	}
	else{
		root->right = insertinBST(root->right,d);
	}
	return root;
}

node*builtBST(int n){
	node*root = NULL;
	for( int i = 0; i<n; i++){
		int x;
		cin>>x;
		root = insertinBST(root,x);
	}
	return root;
}

int main()
{
    int n;
    cin >> n;
    
	node *root =  builtBST(n);

	int ls = 0;
    ReplaceSum(root, ls);

    printPre(root);

    return 0;
}


// Replace each node with the sum of all greater nodes in a given BST

// Input Format
// Enter the number of nodes N and add N more numbers to the BST

// Constraints
// None

// Output Format
// Display the resulting tree

// Sample Input
// 3
// 2
// 1
// 3
// Sample Output
// 5 => 3 <= 0
// END => 5 <= END
// END => 0 <= END
