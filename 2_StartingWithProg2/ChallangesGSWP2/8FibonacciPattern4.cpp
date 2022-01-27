// Fibonacci Pattern 

#include  <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    int n, t1 = 0,t2 = 1,next_term;
        n = N*(N+1)/2;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
        
            if(i == 1)
            {
                cout << t1 << "    ";
            }
            else if (i == 2 && j == 1)
            {
                cout << t2 << "    ";
            }
            else
            {
                next_term = t1 + t2;
                t1 = t2;
                t2 = next_term;
                cout << next_term << "    ";
            }
        }
        cout << endl;
    }
    return 0;
}