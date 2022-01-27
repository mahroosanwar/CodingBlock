// GCD of Two numbers

#include <iostream>
using namespace std;

int main()
{
    int i,n1,n2,n,largest =0;
    cin >> n1 >> n2;


    // check which is greater for updation in for 
    if (n1>n2)
    {
        n=n2;
    }
    else
    {
        n=n1;
    }
    for ( i= 1; i<=n; i++)                  // n is small of n1 and n2
    {
        if((n1%i)==0 && (n2%i) == 0){       //will get the common factor of n1 and n2
            if(largest<i)                   //greatest common factor 
            {
                largest = i;
            }
        }
        
    }cout << largest << endl;
    
    return 0;

}