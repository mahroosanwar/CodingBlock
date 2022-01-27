// Sum of N Digit

#include <iostream>
using namespace std;

int main()
{
    int N, sum = 0;

    cout << "Enter The value of N: ";
    cin >> N;

    while (N != 0)  //it become zero in the end
    {
        sum = sum + N % 10 ;

    N = N/10;
    }

    cout << "Sum of Digit is " << sum << endl;

    return 0;
}