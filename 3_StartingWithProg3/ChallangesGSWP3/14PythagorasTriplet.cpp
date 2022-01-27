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