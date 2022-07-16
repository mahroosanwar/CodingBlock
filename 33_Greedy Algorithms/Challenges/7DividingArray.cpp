// 7 Dividing Array

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v1;
		for(int i=0 ; i<n ; i++){
			ll a;
			cin>>a;
			v1.push_back(a);
		}
        sort(v1.begin(),v1.end());
        ll mn=0,mx=0;
        for(int i=0;i<n;i+=2){
            mn += v1[i+1]-v1[i];
        }
        for(int i=0;i<n/2;i++){
            mx += v1[n-i-1]-v1[i];
        }
        cout<<mn<<" "<<mx<<'\n';
	}
	return 0;
}

// You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A, and add it to another array B(initially empty). After these operations, you can rearrange the elements of both the arrays in any order. We define, difference between these two arrays as :

// Find the maximum and minimum values of differences of these two arrays.

// Input Format
// First Line contains number of test cases, T. For each test case, first line contains a single integer, n (n is even). Next line contains n integers, denoting the elements f array, A.

// Constraints
// 1<=T<=10
// 1<=n<=10^5
// |Ai|<=10^9

// Output Format
// For each test case, print the minimum and maximum value of differences between two arrays.

// Sample Input
// 1
// 4
// 12 -3 10 0