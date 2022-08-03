#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void create(Node *&root)
{
    int d;
    cin >> d;
    root = new Node(d);
    string left1, right1;
    cin >> left1;
    if (left1 == "true")
    {
        create(root->left);
    }
    cin >> right1;
    if (right1 == "true")
    {
        create(root->right);
    }
}
void printPathUtils(Node *root, int sum, int sumsofar, vector<int> &path)
{
    if (root == NULL)
    {
        return;
    }
    sumsofar += root->data;
    path.push_back(root->data);
    if (root->left == NULL and root->right == NULL and sumsofar == sum)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout<<endl;
    }
    if (root->left != NULL)
    {
        printPathUtils(root->left, sum, sumsofar, path);
    }
    if (root->right != NULL)
    {
        printPathUtils(root->right, sum, sumsofar, path);
    }
    path.pop_back();
}
int main()
{
    Node *root=nullptr;
    create(root);
    int sum;
    cin>>sum;
    vector<int> path;
    printPathUtils(root,sum,0,path);
    return 0;
}

// Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number.

// Input Format
// First line contains the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL. Second line contains the number k.

// Constraints
// None

// Output Format
// Display the root to leaf path whose sum is equal to k.

// Sample Input
// 10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false
// 60
// Sample Output
// 10 20 30
// Explanation
// The given tree is in pre order traversal. So convert it into binary tree and check root to leaf path sum.
