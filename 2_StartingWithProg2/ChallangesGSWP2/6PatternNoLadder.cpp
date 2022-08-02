//Pattern No. Ladder

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,no = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            no++;
            cout << no << "    ";
        }
        cout << endl;
    }
    return 0;

}

//Pattern No. Ladder

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,no = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            no++;
            cout << no << "    ";
        }
        cout << endl;
    }
    return 0;

}

// Take N (number of rows), print the following pattern (for N = 4)

// 1
// 2 3
// 4 5 6
// 7 8 9 10

// Input Format
// Constraints
// 0 < N < 100

// Output Format
// Sample Input
// 4
// Sample Output
// 1  
// 2	3  
// 4	5	6  
// 7	8	9	10
// Explanation
// Each number is separated from other by a tab.
