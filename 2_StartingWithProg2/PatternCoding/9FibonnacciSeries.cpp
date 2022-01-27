// N terms fibonacci Series

#include <iostream>
using namespace std;

int main()
{
    int i, N,t1 = 0, t2 = 1, next_term;
    cin >> N;
    for (i = 1; i <= N; i++ )
    {
        if(i == 1)
        {
            cout << t1 << " ";
        }
        else if (i == 2)
        {
            cout << t2 << " ";
        }
        else
        {
            next_term = t1 + t2;
            t1 = t2;
            t2 = next_term;
            cout << next_term << " ";
        }
    }
    return 0;
}