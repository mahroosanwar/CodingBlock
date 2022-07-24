// 7: Minimum trials needed (Plate Dropping)

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int DP[1005][1005];

int eggDropBUDP(int n, int k)
{
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i <= k; i++)
    {
        DP[0][i] = 0;
        DP[1][i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        DP[i][0] = 0;
        DP[i][1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (i > j)
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = INT_MAX;
                for (int x = 1; x <= j; x++)
                {
                    int retval = max(DP[i - 1][x - 1], DP[i][j - x]);
                    if (retval < DP[i][j])
                        DP[i][j] = retval;
                }
                DP[i][j] = DP[i][j] + 1;
            }
        }
    }
    return DP[n][k];
}

int eggDropTDDP(int n, int k)
{
    if (k == 0 or k == 1)
        return k;
    if (n == 1)
        return k;
    if (DP[n][k] != -1)
        return DP[n][k];

    int result = INT_MAX;
    for (int x = 1; x <= k; x++)
    {
        int retval = max(eggDropTDDP(n - 1, x - 1), eggDropTDDP(n, k - x));
        if (retval < result)
        {
            result = retval;
        }
    }
    return DP[n][k] = 1 + result;
}

int eggDrop(int n, int k)
{
    if (k == 0 or k == 1)
        return k;
    if (n == 1)
        return k;

    int result = INT_MAX;
    for (int x = 1; x <= k; x++)
    {
        int retval = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
        if (retval < result)
        {
            result = retval;
        }
    }
    return 1 + result;
}

int main(int argc, char const *argv[])
{
    int n, k, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        // memset(DP, -1, sizeof(DP));
        // cout<<eggDropTDDP(n, k)<<endl; For Top Down DP
        cout << eggDropBUDP(n, k) << endl; // For Bottom Up DP
        // cout<<eggDrop(n, k); For Recursive Solution
    }
    return 0;
}

// Aakash has K identical plates and N floors. He needs to find the lowest floor at which the plate will break down aka critical floor. However, he doesn't like climbing stairs again and again. So he decided to take your help. Help him design a strategy that would tell him the minimum no of trials he need to perform for knowing the critical floor.

// Assume that plate will only break at critical floor and floors higher than that.

// _Hint :
// _Recursion tells u what u intend to calculate._
// Test case 3 is only for students who think that the test cases are easy.

// Input Format
// The first line contains T, the number of test cases.
// Next T line follows 2 space separated integers, first being the number of plates K, next being the number of floors N.

// Constraints
// 0 < T < 10
// 0 < K < 2
// 0 < N < 10

// Output Format
// T lines of required answer

// Sample Input
// 1
// 2 3
// Sample Output
// 2
// Explanation
// Aakash can start dropping plates from floor 1, 2 or 3.

// Consider floor 1 :

// If the plate breaks, critical floor is floor 1 else he moves to floor 2 and repeat the process. By this method minimum no of trials to know the critical floor are 3.

// Consider he starts with 2nd floor.

// Now if the plate breaks, the number of floors left to be checked is 1, floor 1. If it doesn't break, then floors to be tested is floor 3. In both the cases the number of trials are 2. So Akash will start from floor 2
