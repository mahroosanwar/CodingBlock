// 4 Trie Interview

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll maxXORFromLeft = LLONG_MIN, maxXORFromRight = LLONG_MIN, n;
class Node
{
public:
    Node *left;  // for storing 0
    Node *right; // for storing 1
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(ll n)
    {
        Node *temp = root, *newNode;
        REPI(i, 0, 64)
        {
            ll bit = (n >> i) & 1ll;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    newNode = new Node();
                    temp->left = newNode;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    newNode = new Node();
                    temp->right = newNode;
                }
                temp = temp->right;
            }
        }
    }
    ll calculate_max_xor(ll val, ll left, ll right, ll ind)
    {
        Node *temp = root;
        ll ans = 0ll;
        REPI(i, 0, 64)
        {
            ll bit = (val >> i) & 1ll;
            if (bit == 0)
            {
                if (temp->right)
                    ans += (1 << i), temp = temp->right;
                else if (temp->left)
                    temp = temp->left;
            }
            else
            {
                if (temp->left)
                    ans += (1 << i), temp = temp->left;
                else
                    temp = temp->right;
            }
        }
        if (left)
        {
            if (ans > maxXORFromLeft)
                maxXORFromLeft = ans;
            return maxXORFromLeft;
        }
        else
        {
            if (ans > maxXORFromRight)
                maxXORFromRight = ans;
            return maxXORFromRight;
        }
    }
};
int main()
{
    Trie tl, tr;
    ll ans = LLONG_MIN;
    cin >> n;
    ll a[n], maxXORLeft[n], maxXORRight[n], XORFromLeft = 0ll, XORFromRight = 0ll;
    REP(i, 0, n)
    cin >> a[i];
    tl.insert(0);
    REP(i, 0, n)
    {
        XORFromLeft ^= a[i];
        maxXORLeft[i] = tl.calculate_max_xor(XORFromLeft, 1, 0, i);
        tl.insert(XORFromLeft);
    }
    tr.insert(0);
    REPI(i, 0, n)
    {
        XORFromRight ^= a[i];
        maxXORRight[i] = tr.calculate_max_xor(XORFromRight, 0, 1, i);
        tr.insert(XORFromRight);
    }
    REP(i, 0, n)
    {
        if (i + 1 < n)
            ans = max(ans, maxXORLeft[i] + maxXORRight[i + 1]);
    }
    cout << ans << endl;
    return 0;
}

// This placement season , Avinash is preparing for his upcoming interviews in multinational companies . He is trying to solve a problem which was previously asked in many companies. There is an array named arr. He is supposed to find the maximum value of (arr[a] ^ arr[a + 1] ^ arr[a + 2] …….. arr[b]) + (arr[c] ^ arr[c + 1] ^ arr[c + 2] …….. arr[d]) where 1 <= a <= b <= c <= d <= N , where N is the size of the array. Help him to find an optimal solution.

// Input Format
// First line of the test case will be the length of array N . Then on the next line you will be given N space separated integers.

// Constraints
// 0 <= element of array <= 10^9 1 <= N <= 10^5

// Output Format
// The output contains a single integer denoting the maximum value of expression

// Sample Input
// 4 
// 1 2 6 8
// Sample Output
// 17
// Explanation
// Here in the given a=1, b= 2, c= 3, d=4 , so (1 ^ 2) + (6 ^ 8) = 3 + 14 = 17.