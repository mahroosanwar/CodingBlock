//Prime Visits

#include<iostream>
using namespace std;

int p[900000]; // use global array as size is large
int csum[1000005]={0};

void prime_sieve(){
	for(long long i=0;i<=900000;i++)p[i]=1; // use long long

	for(long long i=2;i*i<=900000;i++){
		if(p[i]==1){
			for(long long j=i*i;j<=900000;j+=i){
				p[j]=0;
			}
		}
	}

	p[0] = p[1] = 0;
}


int main() {
	prime_sieve();
	for(int i = 1; i<=1000005;i++){
		csum[i] = csum[i-1]+p[i];
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b; // not >>a,b
		cout<<csum[b]-csum[a-1]<<endl;
	}
	return 0;
}


// PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.



// Input Format
// The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

// Constraints
// a<=1000000 & b<=1000000.
// N<=1000

// Output Format
// Output contains N lines each containing an answer for the test case.

// Sample Input
// 2
// 1 10
// 11 20
// Sample Output
// 4
// 4
// Explanation
// PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
// For the second testcase , he chooses countries with numbers 11,13,17 and 19.