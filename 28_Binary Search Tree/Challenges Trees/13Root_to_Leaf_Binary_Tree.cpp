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