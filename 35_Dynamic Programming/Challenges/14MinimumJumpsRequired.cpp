// 14: Minimum Jumps Required

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_jumps_req(int n, int a[])
{
    if (n == 0 || a[0] == 0)
        return INT_MAX;

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (dp[j] != INT_MAX && a[j] + j >= i)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << min_jumps_req(n, a) << endl;
    }
    return 0;
}

// You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

// Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

// Constraints
// 1<=t<=50
// 1<=n<=1000
// 0<=A[i]<=100

// Output Format
// Print the minimum number of jumps.

// Sample Input
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// Sample Output
// 3
// Explanation
// 1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9