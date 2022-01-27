//Check Prime or Not Prime

#include <iostream>
using namespace std;

int main()
{
    int i,N;
    cin >> N;
    for (i = 2; i < N; i = i + 1)
    {
        if (N % i == 0)
        {
            cout << "Not Prime";
            break;

        }
    }
    if (i == N)
    {
        cout << "prime";
    }
    return 0;
}