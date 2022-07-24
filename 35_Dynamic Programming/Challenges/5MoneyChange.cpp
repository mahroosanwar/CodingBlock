// 5: Money Change

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
ll CoinChangeBottomUp(int *coins, int value, int n)
{
    ll *dp = new ll[value + 1];
    dp[0] = 1;
    for (int i = 0; i <= value; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            if (coins[i] <= j)
                dp[j] = ((dp[j] % mod) + (dp[j - coins[i]] % mod)) % mod;
        }
    }
    int temp = dp[value];
    delete[] dp;
    return temp;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n;
        int *coins = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        cin >> s;
        cout << CoinChangeBottomUp(coins, s, n) << endl;
        // delete [] dp;
    }
    return 0;
}

// Given a big amount N and the array of denominations S. Assuming infinite supply of each of S = {S1,S2….Sm} denominations, find the number of ways to make change for N cents.

// Input Format
// First line contains an integer T denoting the total number of test cases.
// For every test case, there are three lines.
// First line will contain an integer 'M' denoting the size of array.
// The second line contains M space-separated integers A1, A2, …, Am denoting the elements of the array.
// The third line contains an integer 'N' denoting the cents.

// Constraints
// 1 <= T <= 10 1 <= n <= 500 1 <= S[i] <= 1000 1 <= N <= 1000000

// Output Format
// Print number of possible ways to make change for N cents in a new line. Since answers can be large, print answer % (1000000000 + 7).

// Sample Input
// 2
// 3
// 1 2 3
// 4
// 4
// 2 5 3 6
// 10
// Sample Output
// 4
// 5
// Explanation
// For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
