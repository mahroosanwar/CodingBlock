//10: 0-N Knapsack

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapSack01(vector<int> &wt,vector<int> &val,int W,int n,int dp[][1001]){
	if(n == 0 || W == 0){
		return 0;
	}

	if(dp[n][W] != -1) return dp[n][W];

	if(wt[n-1] <= W){
		int op1 = val[n-1] + knapSack01(wt,val,W-wt[n-1],n,dp);
        int op2 = val[n-1] + knapSack01(wt,val,W-wt[n-1],n-1,dp);
		int op3 = knapSack01(wt,val,W,n-1,dp);
		return dp[n][W] = max(op1,max(op2,op3));
	}
	return dp[n][W] = knapSack01(wt,val,W,n-1,dp);
}


int main() {
	int n,w;
	cin>>n>>w;
	int no;
	vector<int> wt,val;
	int dp[1001][1001];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            dp[i][j] = -1;
        }
    }
	for(int i=0;i<n;i++){
		cin>>no;
		wt.push_back(no);
	}
	for(int i=0;i<n;i++){
		cin>>no;
		val.push_back(no);
	}
	cout<<knapSack01(wt,val,w,n,dp)<<endl;
	return 0;
}

// You've heard of 0-1 knapsack. Below is the problem statement for the same.

// Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
// There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

// Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

// Input Format
// The first line contains two integers, representing n(size of val[]) and cap respectively. The subsequent line contains n integers representing the wt[] array. The next line, again, contains n integers representing the val[] array.

// Constraints
// 1 <= n,cap <= 1000 1 <= wt[i] <= cap 1 <= val[i] <= 100000

// Output Format
// Print a single integer, the answer to the problem.

// Sample Input
// 5 11
// 3 2 4 5 1
// 4 3 5 6 1
// Sample Output
// 16
// Explanation
// We take second item 4 times and fifth item one time to make the total values 16.