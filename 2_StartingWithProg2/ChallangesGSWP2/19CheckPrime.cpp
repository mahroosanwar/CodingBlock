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


// Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

// Input Format
// Constraints
// 2 < N <= 1000000000

// Output Format
// Sample Input
// 3
// Sample Output
// Prime
// Explanation
// The output is case specific
