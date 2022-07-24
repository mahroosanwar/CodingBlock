#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int recurcheck(int size[],int amount[],int n,int cap){	
    if(cap==0 || n==0)
		return 0;

	if(dp[n][cap]!=-1)
		return dp[n][cap];

	if(cap>=size[n-1]){
        int op1 = amount[n-1] + recurcheck(size,amount,n,cap-size[n-1]);
        int op2 = amount[n-1] + recurcheck(size,amount,n-1,cap-size[n-1]);
		int op3 = recurcheck(size,amount,n-1,cap);
		return dp[n][cap] = max(op1,max(op2,op3));
	}

    return dp[n][cap] = recurcheck(size,amount,n-1,cap);

}
int main() {
	int n,m;
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	int size[n],amount[n];
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
		
	}
	for(int i=0;i<n;i++)
	{
		cin>>amount[i];
		
	}
	cout<<recurcheck(size,amount,n,m);

	return 0;
}