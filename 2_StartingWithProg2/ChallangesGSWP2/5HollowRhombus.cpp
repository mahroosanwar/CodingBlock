// Hollow Rhombus Pattern

#include <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = i; j <= N; j++)
        {
            if(j < N)
            {
                cout << " ";
            }
            else if (j == N)
            {
                cout << "*";
            }
        }
        for (j = 1; j < N -1; j++)
        {
            if(i == 1 || i == N)
            {
                cout << "*";
            }
            else if(i != 1 || i != N)
            {
                cout << " ";
            }
            
        }
        for (j = 1; j <= i; j++)
        {
            if(j > 1)
            {
                cout << " ";
            }
            else if (j == 1)
            {
                cout << "*";
            }
        }
        cout << endl;
       
    }
    return 0;
}