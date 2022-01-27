// Print Reverse of Number method 2

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;

    while(n!=0)
    {
        int rem  = n%10;
        num  = num*10 + rem;
        n/=10;
    }
    cout << num << endl;
}