//3: Prateek Loves Candy

#include <iostream>
using namespace std;
#define ll long long
long long a[1000000];

//PRIME SIEVE & OPTIMISATIONS


void primeSieve(ll *p,ll n){

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(ll i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(ll i=3;i<=n;i+=2){
        
        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(ll j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    int k=0;
    for(int i=2;i<1000000;++i){
        if(p[i]){
            a[k]=i;
            k++;
        }
    }
    return;
}

int main() {
    ll N = 1000001;
    ll p[N] = {0};
    primeSieve(p,N-1);
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<a[n-1]<<endl;
    }

}

// Prateek recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Prateek wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Prateek bhaiya it is now your job to help him out :)

// Input Format
// First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.

// Constraints
// T <= 10000

// It is guaranteed that the answer does not exceed 10^6.

// Output Format
// Print the minimum cost that needs to be paid.

// Sample Input
// 2
// 5
// 1
// Sample Output
// 11
// 2
// Explanation
// In the first case there are 5 primes upto 11(2,3,5,7,11).