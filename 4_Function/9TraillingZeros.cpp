// Number of Trailling zeros in N!

#include <iostream>
using namespace std;

int traillingZeros(int n)
{
    int zeros = 0;
    while(n!=0)
    {
        n = n/5;
        zeros = zeros + n; 
    }
    return zeros;
}

int main(){

    int n;
    cin >> n;

    cout << traillingZeros(n);

    cout << endl;
    return 0;
}