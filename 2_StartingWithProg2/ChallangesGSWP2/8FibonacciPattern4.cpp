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

// Take N (number of rows), print the following pattern (for N = 4)
// 0
// 1 1
// 2 3 5
// 8 13 21 34

// Input Format
// Constraints
// 0 < N < 100

// Output Format
// Sample Input
// 4
// Sample Output
// 0 
// 1    1 
// 2    3     5 
// 8   13    21    34
// Explanation
// Each number is separated from other by a tab. For given input n, You need to print n(n+1)/2 fibonacci numbers. Kth row contains , next k fibonacci numbers.
