// 16: Optimal Game Strategy-II

#include <iostream>
using namespace std;

long long int dp[10001][10001];

long long int max_score(long long int a[], int i, int j)
{
    // base case
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // rec. case
    long long int op1 = a[i] + min(max_score(a, i + 2, j), max_score(a, i + 1, j - 1));
    long long int op2 = a[j] + min(max_score(a, i, j - 2), max_score(a, i + 1, j - 1));
    long long int ans = max(op1, op2);
    return dp[i][j] = ans;
}
int main()
{
    int n;
    cin >> n;
    long long int a[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_score(a, 0, n - 1);
    return 0;
}

// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

// Input Format
// First line contains the number of coins 'n'.
// Second line contains n space separated integers where ith index denotes the value of ith coin.

// Constraints
// 1 < N <= 10000 , N is always even
// 0 <= Ai <= 1000000

// Output Format
// Print a single line with the maximum possible value that Piyush can win with.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 6
// Explanation
// Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases Piyush picks coin 2 and wins with a total of 6.