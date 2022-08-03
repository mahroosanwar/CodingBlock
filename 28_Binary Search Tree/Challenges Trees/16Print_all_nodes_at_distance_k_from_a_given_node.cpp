//Print all nodes at distance k from a given node

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;          //for print the sorted order

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

//build tree using preorder and inorder
node *buildTree(int *inOrder, int *preOrder, int s, int e) {
    static int i=0;

    if(s>e) {
        return NULL;
    }

    node *root = new node(preOrder[i]);

    int index = -1;

    for(int j=s; j<=e; j++) {
        if(inOrder[j] == preOrder[i]) {
            index = j;
            break;
        }
    }

    i++;

    root->left = buildTree(inOrder, preOrder, s, index-1);
    root->right = buildTree(inOrder, preOrder, index+1, e);

    return root;
}

// helper function (-> print all the node which are below kth level from the given node)
void printAtLevel_K(node *root, int k) {
    //basse case
    if(root == NULL or k<0) {
        return;
    }

    if(k == 0) {
        v.push_back(root->data);
        return;
    }

    printAtLevel_K(root->left, k-1);
    printAtLevel_K(root->right, k-1);
    return;
}

//Nodes at Distance K from Given Node
int printAtDistance_K(node *root, node *target, int k) {
    //base case
    if(root == NULL) {
        return -1;
    }

    if(root == target) {
        printAtLevel_K(root, k);
        return 0;
    }

    //next step ancestor
    //distance of target node in left subtree
    int dl = printAtDistance_K(root->left, target, k);

    if(dl != -1) {
        if(dl + 1 == k) {
            v.push_back(root->data);            
        }
        else {
            printAtLevel_K(root->right, k-dl-2);
        }
        return 1+dl;
    }

    //distance of target node in right subtree
    int dr = printAtDistance_K(root->right, target, k);

    if(dr != -1) {
        if(dr + 1 == k) {
            v.push_back(root->data);
        }
        else {
            printAtLevel_K(root->left, k-dr-2);
        }
        return 1 + dr;
    }

    //node was not present in left and right subtree
    return -1;
}

//find the add of target node in BT
node *targetNode(node *root, int target) {
    //base case
    if(root == NULL) {
        return NULL;
    }

    node *temp;
    if(root->data == target) {
        return root;
    }

    node *leftSearch  = targetNode(root->left, target);

    if(leftSearch == NULL) {
        return targetNode(root->right, target);
    }

    return leftSearch;
}

int main() {
    int n;
    cin >> n;

    int preOrder[n];
    for(int i=0; i<n; i++) {
        cin >> preOrder[i];
    }

    int inOrder[n];
    for(int i=0; i<n; i++) {
        cin >> inOrder[i];
    }

    node *root = buildTree(inOrder, preOrder, 0, n-1);
    

    int T;
    cin >> T;

    while(T--) {
        int target_data;
        cin >> target_data;

        node *target = targetNode(root, target_data);
        
        int k;
        cin >> k;
        printAtDistance_K(root, target, k);

        if(v.size() == 0) {
            cout << 0;
        }
        else {
            sort(v.begin(), v.end());

            for(auto x : v) {
                cout << x << " ";
            }
        }
        cout << endl;

        v.clear(); // clear vector after each test 
		//case as it defined globally so that easily accessible to all function and we dont need to pass all the time
    }

    return 0;
}


// Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. Print 0 if no such node exist at distance k.

// Input Format
// The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT. The next line will contain an integer T. Then T lines follow you will be given 2 integers the first one denoting the value of Node and the second one denoting the value of k.

// Constraints
// 2 ≤ N ≤ 10^3

// Output Format
// On T lines print space separated desired output for each test case in sorted form

// Sample Input
// 4
// 60 65 50 70
// 50 65 60 70
// 2
// 60 1
// 65 2
// Sample Output
// 65 70
// 70
// Explanation
// The tree looks like

//              60
//           /      \
//        65         70
//      /
//   50
// For testcase 1 : The nodes 65 and 70 are the only ones at distance k=1 from 60.
// For testcase 2 : The node 70 is at distance k=2 from 65.
