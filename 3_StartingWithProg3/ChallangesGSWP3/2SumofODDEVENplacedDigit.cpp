// Sum of the ODD and EVEN placed Digits

#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cin >> n;
    int n1 =n;              // take n1 = n so it can be use as it's previous(original) value
    while(n!=0)
    {
        int rem=n%10;
        sum  = sum + rem;
        n = n/100;
        
    }
    cout << sum << endl;

    sum = 0;
    while (n1!=0)               
    {
        n1 =n1/10;      //make number even place to once place 
                        //to get the remainder from %
        int rem = n1%10;
        sum = sum + rem;
        n1 = n1/10;
    }

    cout << sum << endl;
    return 0;
}