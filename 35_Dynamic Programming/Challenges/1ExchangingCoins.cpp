//1: Exchanging Coins

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll>dp;

ll maxGold(ll n){
    // n == 0 return
	if(n==0){
		return 0;
	}
    //lookup
	if(dp.count(n) != 0)return dp[n];
    // else max of n or n/2 + n/3 + n/4
	return dp[n] = max(n,maxGold(n/2)+maxGold(n/3)+maxGold(n/4));
}

int main() {
	ll n;
	cin>>n;
	ll ans = n;
	cout<<maxGold(n);
	return 0;
}

// Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

// Input Format
// The input file contains a single integer n, the number on the coin.

// Constraints
// 0 <= n <= 1 000 000 000

// Output Format
// Print the maximum weight of gold you can get.

// Sample Input
// 12
// Sample Output
// 13
