// 6: The Subset Sum To Target

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool dp[1001][100001];

bool subsetSum(int a[], int n, int k)
{
    if (k == 0)
        return true;

    if (n <= 0 || k < 0)
        return false;

    if (dp[n][k] != false)
        return dp[n][k];

    if (k >= a[n - 1])
        return dp[n][k] = subsetSum(a, n - 1, k - a[n - 1]) || subsetSum(a, n - 1, k);

    return dp[n][k] = subsetSum(a, n - 1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(dp, false, sizeof(dp));

    if (subsetSum(a, n, k))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}

// Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

// Input Format
// 1st Line: n sum 2nd Line: a1 a2……an (Array Values)

// Constraints
// 1<= n <= 1000
// 1<= sum <= 10^5
// 1<= Ai <=10^4

// Output Format
// Yes, if sum exist No, it sum does not exist

// Sample Input
// 5 10
// 1 2 3 4 5
// Sample Output
// Yes