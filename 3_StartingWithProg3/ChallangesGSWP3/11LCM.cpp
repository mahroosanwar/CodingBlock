// LCM of two number

#include <iostream>
using namespace std;

int main()
{
    int n1, n2, i, n, hcf;
    cin >> n1 >> n2;
    if(n1>n2)
    {
        n = n2;
    }
    else{
        n = n1;
    }

    for (i = 1; i <= n; i++)
    {
        if((n1%i) == 0 && (n2%i) == 0)
        {
            hcf = i;
        }   
    }
    cout << (n1*n2)/hcf << endl;            //LCM = (product of numbers)/HCF
    return 0;
}