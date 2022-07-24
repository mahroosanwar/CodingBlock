//1: Exchanging Coins

#include<bits/stdc++.h>
using namespace std;

long long int dp[1000000];

long long int coins(long long int n){
	if(n<=1000000 && dp[n] != -1)
		return dp[n];
	//base  case
	if(n <= 11){
		dp[n] = n;
		return dp[n];
	}
	long long ans = max(n,coins(n/2)+coins(n/3)+coins(n/4));
	if(n <= 1000000)
		dp[n] = ans;//memoize the answer
	return ans;
}
int main(){
	long long int n,i;
	
	for(i=0;i<=1000000;i++){
		dp[i] = -1;
	}
	
	cin>>n;
	cout<<coins(n);
	
	return 0;
}