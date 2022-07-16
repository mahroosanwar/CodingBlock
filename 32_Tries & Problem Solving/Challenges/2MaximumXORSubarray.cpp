//2 Maximum XOR Subarray 
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;
    node(int d = 0)
    {
        left = right = NULL;
        val = d;
    }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node(0);
    }

    void insert(int x, int xorSoFar)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            bool b = xorSoFar & (1 << i);

            if (!b)
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
        temp->val = xorSoFar;
    }

    int query(int xorSoFar)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            bool b = xorSoFar & (1 << i);

            if (b == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else if (temp->left != NULL)
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else if (temp->right != NULL)
                {
                    temp = temp->right;
                }
            }
        }
        return xorSoFar ^ (temp->val);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;

    int xorSoFar = 0;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        xorSoFar ^= x;
        t.insert(x, xorSoFar);
        result = max(result, t.query(xorSoFar));
    }

    cout << result;

    return 0;
}

// Given an array of n integers, find subarray whose xor is maximum. A subarray is a contiguous part of array.

// Input Format
// First line contains single integer n (1<=n<=1000). Next line contains n space separated integers

// Constraints
// 1 <= n <= 1000
// 1 <= A[i] <=1000

// Output Format
// Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 7