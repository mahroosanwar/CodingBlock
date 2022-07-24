// 13: Count Subsequences

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9 + 7;
ll dp[100005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, int> lastOcc;
        dp[0] = 1;

        for (int i = 1; i < s.length() + 1; i++)
        {
            if (lastOcc.find(s[i - 1]) == lastOcc.end())
            {
                dp[i] = (dp[i - 1] * 2) % MOD;
            }
            else
            {
                dp[i] = ((dp[i - 1] * 2) % MOD - dp[lastOcc[s[i - 1]] - 1] + MOD) % MOD;
            }
            lastOcc[s[i - 1]] = i;
        }

        cout << dp[s.length()] << endl;
    }
    return 0;
}

// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

// Input Format
// First line of input contains an integer 't' denoting number of test cases.
// Next t lines contain a string each.

// Constraints
// 1<=t<=100
// 1<=length of s<=100000
// s will contain upper letters only.

// Output Format
// For each test case ,print ans%1000000007 in a new line each ,where ans is the number of distinct subsequences.

// Sample Input
// 2
// AAA
// ABCDEFG
// Sample Output
// 4
// 128
// Explanation
// For "AAA" , the distinct subsequences that can be formed are { '', 'A' , 'AA' , 'AAA }. So we print 4 , no of distinct subsequences.