//WAP to stop Processing Number for Cumulative sum become negative
#include <iostream>
using namespace std;

int main()
{
    int i,n,no,sum = 0;
    
    for (i = 0; i < n; i++)
    {
        cin >> no;
    
        sum = sum + no;  
         if (sum<0)
        {
            break;
        }
        cout << no << endl;
    
    }
    return 0;
}