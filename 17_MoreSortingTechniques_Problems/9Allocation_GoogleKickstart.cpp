// // Allocation Google KickStart (Question Below the code)


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(NULL);
#define endl "\n"
#define int long long

const int N = 1e5+5;

int n,b;
int a[N];

int32_t main() { 
    IOS;
    int t;
    cin>>t;
    int tc=0;
    while(t--){
        tc++;
        cin>>n>>b;
        for (int i=1; i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);        //n log n 
        int ans=0;
        for (int i=1;i<=n;i++){
            if (b>=a[i]){
                ans++;
                b-=a[i];
            }
        }
        cout<<"Case #"<<tc<<" : "<<ans<<endl;
    }   
}



// Problem
// There are N houses for sale. The i-th house costs Ai dollars to buy.
// You have a budget of B dollars to spend.

// What is the maximum number of houses you can buy?

// Input
// The first line of the input gives the number of test cases, T.
// T test cases follow. Each test case begins with a single line containing the two integers N and B.
// The second line contains N integers. The i-th integer is Ai, the cost of the i-th house.

// Output
// For each test case, output one line containing Case #x: y, 
//where x is the test case number (starting from 1) and y is the maximum number of houses you can buy.

// Limits
// Time limit: 15 seconds.
// Memory limit: 1 GB.
// 1 ≤ T ≤ 100.
// 1 ≤ B ≤ 105.
// 1 ≤ Ai ≤ 1000, for all i.

// Test Set 1
// 1 ≤ N ≤ 100.

// Test Set 2
// 1 ≤ N ≤ 105.

// Sample

// Sample Input
// 3
// 4 100
// 20 90 40 90
// 4 50
// 30 30 10 10
// 3 300
// 999 999 999

// Sample Output
// Case #1: 2
// Case #2: 3
// Case #3: 0

// In Sample Case #1, you have a budget of 100 dollars.
// You can buy the 1st and 3rd houses for 20 + 40 = 60 dollars.
// In Sample Case #2, you have a budget of 50 dollars.
// You can buy the 1st, 3rd and 4th houses for 30 + 10 + 10 = 50 dollars.
// In Sample Case #3, you have a budget of 300 dollars. You cannot buy any houses (so the answer is 0).

// Note: Unlike previous editions, in Kick Start 2020, all test sets are visible verdict test sets,
// meaning you receive instant feedback upon submission.
