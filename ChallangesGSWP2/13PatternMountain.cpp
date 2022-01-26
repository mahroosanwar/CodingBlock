// Pattern Mountain

#include <iostream>
using namespace std;


int main()
{
    int i,j,n;
    cin >> n;
    for (i = 0; i<n; i++)
    {   int no = 1;
        for(j=0; j<=i; j++)
        {    cout << no << "    ";
            no++;
        }
        for(j = 0; j<2*(n-i)-3; j++)
            cout << "     ";

        int bottom_line = i+1,no1 = i+1;
        if (i == n-1)
        {
            bottom_line--;
            no1--;
        }
        
        for (j = 0; j<bottom_line; j++)
        {
            cout << no1 << "    ";
            no1--;
        }
    cout << endl;
    }
    return 0;
}