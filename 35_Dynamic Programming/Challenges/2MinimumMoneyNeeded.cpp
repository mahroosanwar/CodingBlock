//2: Minimum Money Needed

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

long long int minCost(vector<int> &val,vector<int> &wt,int n,int W){
	long long int dp[W+1];
    dp[0] = 0;
	
	for(int i=1;i<=W;i++){
        dp[i] = INT_MAX;
		for(int j=0;j<n;j++){
			if(wt[j] <= i){
                dp[i] = min(dp[i], dp[i- wt[j]] + val[j]);
            }
		}
	}
	return dp[W] == INT_MAX ? -1 : dp[W];
}

int main() {
	int n,w,currCost;
	cin>>n>>w;
	vector<int> val,wt;
	for(int i=1;i<=w;i++){
		cin>>currCost;
        if(currCost != -1){
            val.push_back(currCost);
		    wt.push_back(i);
        }	
	} 
	cout<<minCost(val,wt,val.size(),w)<<endl;
	return 0;
}

// Cody went to the market to buy some oranges for his N friends. There he finds orange wrapped in packets, with the price of i^th packet as val[i]. Now he wants to buy exactly W kg oranges, so he wants you to tell him what minimum price he should pay to buy exactly W kg oranges. Weight of i^th packet is i kg. If price of i^th packet is -1 then this packet is not available for sale. The market has infinite supply of orange packets.

// Input Format
// First line of input contains two space separated integers N and W, the number of friend he has and the amount of Oranges in kilograms which he should buy.

// The second line contains W space separated integers in which the i^th^ integer specifies the price of a ‘i’kg apple packet. A value of -1 denotes that the corresponding packet is unavailable

// Constraints
// 1 <= N,W,val[ ] <= 10^3

// Output Format
// Output a single integer denoting the minimum price Code should pay to get exactly W kg oranges. Else print -1 if it is not possible to fill the bag.

// Sample Input
// 5 5
// 1 2 3 4 5
// Sample Output
// 5