#include<iostream>
using namespace std;

int dp[1001][1001];

int profit(int N, int C,int *wt,int *prices){
	//base case
	if(N==0||C==0){
		return 0;
	}
	if(dp[N][C] != -1){
		return dp[N][C];
	}
	//recursive case
	int ans=0;
	int inc,exc;
	inc=exc=0;
	//inc
	if(wt[N-1]<=C){
	    inc=prices[N-1]+profit(N-1,C-wt[N-1],wt,prices);
    } 
    //exc
    exc=profit(N-1,C,wt,prices);
    ans=max(inc,exc);
    return dp[N][C]=ans;	
}
int main(){
	int N;
	int S;
	cin>>N>>S;
	int weights[N];
	int prices[N];
	for(int i=0;i<N;i++){
		cin>>weights[i];
	}
	for(int i=0;i<N;i++){
		cin>>prices[i];
	}

    for(int i=0;i<=N;i++){
        for(int j=0;j<=S;j++){
            dp[i][j] = -1;
        }
    }
	
	cout<<profit(N,S,weights,prices);
	
	return 0;
}