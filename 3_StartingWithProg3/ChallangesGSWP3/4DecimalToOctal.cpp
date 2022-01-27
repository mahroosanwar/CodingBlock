//Decimal To Octal

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,num=0,place = 0;
    cin >> n;
    while(n!=0)
    {
        int rem = n % 8;
        num = num + rem*pow(10,place);
        place++;
        n/=8; 
    }
    cout << num << endl;
    return 0;
}