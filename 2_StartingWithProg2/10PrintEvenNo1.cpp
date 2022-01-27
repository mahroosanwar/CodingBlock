//Print Even No b/w 1 to N Method 1

#include <iostream>
using namespace std;

int main()
{
    int i = 2,N;
    cout << "Enter The value Of N: ";
    cin >> N;

    while (i <= N)
    {
        cout << i << " ";

        i = i+2;

    }
    return 0;
}