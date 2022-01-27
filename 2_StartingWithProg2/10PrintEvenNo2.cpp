//Print EVen No. Method 2
#include <iostream>
using namespace std;

int main()
{
    int i = 1,N;
    cout << "Enter The Value of N: ";
    cin >> N;

    while (i <= N)
    {
        if (i % 2 == 0 )
        {
            cout << i << " ";
        }
        i = i+1;
    }
    return 0;
}