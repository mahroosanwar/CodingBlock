// Check prime no.

#include <iostream>
using namespace std;

int main()
{
    int i = 2, N;

    cout << "Enter the Number: ";
    cin >> N;

    while (i < N)
    {
        if ( N % i == 0)
        {
            cout << N <<" is not a Prime Number" << endl;
            break;
        }
       i = i + 1;
    }
    if (i == N)
    {
        cout << N << " is Prime Number ";
    }
    return 0;
}