// Is Balanced (Binary Tree)

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{
    // Write your code here
    //base case
    pair<int, bool> p;
    if(root ==  NULL){
        p.first = 0;
        p.second = true;
        return p;
    }

    //rec case

    pair<int, bool> left = isHeightBalancedOptimised(root->left);
    pair<int, bool> right = isHeightBalancedOptimised(root->right);
    
    p.first = max(left.first, right.first) + 1;
 
    if(abs(left.first - right.first) <= 1 && left.second && right.second) {
        p.second = true;
    }
    else {
        p.second = false;
    }

    return p;
}

int main()
{
    node *root = build("true");

    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}
