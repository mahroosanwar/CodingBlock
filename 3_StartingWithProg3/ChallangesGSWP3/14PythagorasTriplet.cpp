//Pythogoras Triplet

#include <iostream>
#include <math.h>

using namespace std;

int main()
{   long long int n,triplet;
    cin >> n;

    if (n==1 || n==0 ||n==2){
        cout << "-1";
    }
    else if(n%2==0){
        triplet = n*n/4;
        cout << triplet-1 << " " << triplet+1;
    }
    else if(n%2!=0){
         triplet = n*n;
        cout << (triplet-1)/2 << " " << (triplet+1)/2;
    }
    cout << endl;
    return 0;

}


// Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".

// Input Format
// A single integer N

// Constraints
// N <= 10^9

// Output Format
// Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

// Sample Input
// 3
// Sample Output
// 4 5
