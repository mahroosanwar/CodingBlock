//Root to Leaf ( Binary Tree)

#include<iostream>
#include<string>
#include<vector>
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

node *buildTree(string s) {
    if(s == "true") {
        int data;
        cin >> data;

        node *root = new node(data);

        string l;
        cin >> l;
        if(l == "true") {
            root->left = buildTree(l);
        }

        string r;
        cin >> r;
        if(r == "true") {
            root->right = buildTree(r);
        }
        return root;
    } 
    return NULL;
}

vector<vector<int>>ans; // to store all path 
vector<int>res; // to store temp path
void root_to_leaf_Paths(node *root, int sum, int sumSoFar) {
    if(root == NULL) {
        return;
    }

    sumSoFar += root->data;         //add to sum
    res.push_back(root->data);      //push to res

    if(root->left == NULL && root->right == NULL && sumSoFar == sum) {
        ans.push_back(res);  // if sumSOFar == sum and its root node add to ans
        res.pop_back();      //remove this node and return
        return;
    }

    root_to_leaf_Paths(root->left, sum, sumSoFar);
    root_to_leaf_Paths(root->right, sum, sumSoFar);

    res.pop_back();         //backtracking step
}

int main() {
    node *root = buildTree("true");

    int sum;
    cin >> sum;

    root_to_leaf_Paths(root, sum, 0);

    for(auto v : ans) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}