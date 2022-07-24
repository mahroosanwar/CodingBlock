//1: Modular Exponentiation


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll n, ll k, ll m){
	ll res=1;

	while(k){

		if(k%2==0){
			n = (n*n)%m;
			k /=2;
		}
		else 
		{
			res = (res*n)%m;
			k--;
		}
	}


	return res;
}

int main() {
	ll n,k,m;
	cin>>n>>k>>m;
	cout<<power(n,k,m);
	return 0;
}

// Given three numbers a,b,c. Calculate (a^b)mod c.

// Input Format
// Single line containing three integers a,b,c separated by space.

// Constraints
// 1<=a,b,c<=100000

// Output Format
// Print (a^b)mod c.

// Sample Input
// 2 2 3
// Sample Output
// 1
// Explanation
// (2^2)mod 3=4 mod 3 = 1
