//2: Deepak and Primes


#include<iostream>
using namespace std;
#define ll long long
void prime(ll *p)
{
	for(ll i=2;i<=1000000;i=i+1)
	p[i]=1;

	for(ll i=2;i<=1000000;i++)
	{
		if(p[i]==1)
		{
			for(ll j=i*i;j<=1000000;j=j+i)
			p[j]=0;
		}
	}
}

int main() {
	ll p[1000000]={0};
	ll n;
	cin>>n;
	prime(p);
	int j=0;
	int i=1;
    for(;i<=1000000;i++)
	{
		if(p[i]==1)
		{
        j++;
		}
        if(j==n){
            break;
        }
	}
	cout<<i;
	return 0;
}

// Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

// Input Format
// Single line containing integral value n.

// Constraints
// 1<=n<=500000

// Output Format
// Integral value denoting nth prime number.

// Sample Input
// 1
// Sample Output
// 2

