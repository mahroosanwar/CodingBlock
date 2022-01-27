//Pattern With Zeros

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,no = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        no++;
        for (j = 1; j <=i; j++)
        {
            if(j == 1 || j == i)
            {
                cout << no << "    ";
            }
            else if (j != 1 || j != i)
            {
                cout << 0 << "     ";
            }
        }
        cout << endl;
    }
    return 0;
}
