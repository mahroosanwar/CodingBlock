//Binary to Decimal

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,N,num=0,place= 0;
    cin >> n;
    while(n!=0)
    {
        int rem = n%10;       //rem is remainder
        num = num + rem*pow(2,place);
        n/=10;
        place++;
    }
    cout << num << endl;
    return 0;
}