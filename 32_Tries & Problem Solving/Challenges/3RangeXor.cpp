// Range XOR
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class trieNode {

public:
    trieNode *left; /// represents 0
    trieNode *right; /// represent one
    vector<int> v;
};

void insert(int n, trieNode *head, int index) {

    trieNode *curr = head;
    for (int i = 31; i >= 0; i--) {

        int bit = (n >> i) & 1;
        if (bit == 0) {

            if (curr->left == NULL) {
                curr->left = new trieNode();
            }
            curr->v.push_back(index);
            curr = curr->left;
        }
        /// bit is one ..
        else {

            if (curr->right == NULL) {
                curr->right = new trieNode();
            }
            curr->v.push_back(index);
            curr = curr->right;
        }
    }
    curr->v.push_back(index);
}

bool binarysearchrange(vector<int>v, int left , int right) {
    int l = 0;
    int h = v.size() - 1;
    while (l <= h) {

        int m = (l + h) / 2;
        int val = v[m];
        if (val >= left && val <= right) {
            return true;
        }
        else if (val < left) {
            l = m + 1;
        }
        else if (val > right) {
            h = m - 1;
        }

    }
    return false;
}

int findmaxorpair(trieNode *head, int el, int left, int right) {
    trieNode *curr = head;
    int value = el;
    int curr_xor = 0;
    for (int j = 31; j >= 0; j--) {

        int b = (value >> j) & 1;
        if (b == 0) {

            if (curr->right != NULL && binarysearchrange(curr->right->v, left, right)) {
                curr = curr->right;
                curr_xor += (int)pow(2, j);
            }
            else {
                curr = curr->left;
            }
        }
        else {
            if (curr->left != NULL && binarysearchrange(curr->left->v, left, right)) {
                curr = curr->left;
            }
            else {
                curr_xor += (int)pow(2, j); //Here
                curr = curr->right;
            }
        }
    }
    return curr_xor;
}

int main() {
    trieNode *myt = new trieNode();
    int t;
    cin >> t;
    int index = 0;
    while (t--) {

        int q;
        cin >> q;

        if (q == 0) {
            int val;
            cin >> val;
            insert(val, myt, index);
            index++;
        }
        else if (q == 1) {
            int x, l, r;
            cin >> l >> r >> x; //Here
            cout << findmaxorpair(myt, x, l - 1, r - 1)<<endl;
        }
    }
    return 0;
}

// You are given an array and Q queries of two types.
// Type 0: Given a number x , insert the number at the last of the array.
// Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y

// Input Format
// First line of the test case will be the number of queries Q . Then on next Q subsequent lines you will be given a query either of type 0 or type 1. Query of type 0 is of the form : 0 X, where X is the integer to be inserted . Query of type 1 is of the form : 1 L R X

// Constraints
// 0 <= element of array <= 10^9
// 1 <= N <= 10^5

// Output Format
// For each query of type 1 output the desired value.

// Sample Input
// 5
// 0 3 
// 0 5
// 0 10 
// 0 6 
// 1 1 4 6
// Sample Output
// 10