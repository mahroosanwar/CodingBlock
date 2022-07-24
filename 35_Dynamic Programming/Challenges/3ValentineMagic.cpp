//3: Valentine Magic

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5005][5005];

ll valentine(ll *a, ll n, ll *b, ll m, ll i, ll j){
	if(i >= n)return 0; // if i reaches end (end of boys array) return 0;
	if(j >= m)return 1000000000; // if j reaches end (end of girls array and boys havent come to end) return a big value 
	if(dp[i][j] != -1)return dp[i][j]; // look up case
	
	ll diff = abs(a[i]-b[j]);
	ll op1 = valentine(a,n,b,m,i+1,j+1) + diff; // if i include the ith item and jth item then increase i and j
	ll op2 = valentine(a,n,b,m,i,j+1);	 // if I dont consider the ith item then dont move i just move j

	return dp[i][j] = min(op1,op2); // return min of both
}

int main() {
	ll n,m;
	cin>>n>>m;
	ll a[n],b[m];
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<m;i++)cin>>b[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = -1;
		}
	}

	sort(a,a+n);
	sort(b,b+m);

	cout<<valentine(a,n,b,m,0,0);

	return 0;
}


// It's Valentine's Day in Russia today. as we all know number of girls in Russia is more than number of boys 😜 hence boys have an extra advantage while choosing girl for the valentine evening. Each boy has certain number of chocolates and each girl has certain number of candies. Now you being the anchor of evening wants to pair all the boys with girls such that the sum of absolute difference between boy's chocolate and girl's candy in a pair is minimized. Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia 😜

// Input Format
// The first line consists of two integers N and M. then follow N integers in second line. Then follow M integers in third line. M >= N

// Constraints
// 1 <= N <= 5000
// 1 <= M <= 5000
// M >= N
// 1 <= chocolates <= 1000000
// 1 <= candies <= 1000000

// Output Format
// The only line which consists of required sum of absolute differences.

// Sample Input
// 2 5
// 4 5
// 1 2 3 4 5
// Sample Output
// 0
// Explanation
// we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5