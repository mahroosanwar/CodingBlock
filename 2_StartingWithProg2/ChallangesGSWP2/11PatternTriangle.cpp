//Pattern Triangle

#include <iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >>n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j<n-i-1; j++)
            cout << "     ";

        for (j = 0; j<=i; j++)
            cout << i+j+1<<"    ";

        for (j = 0 ;j<i; j++)
            cout << 2*i-j <<"    ";
        
    cout << endl;
    }
}



// Take N (number of rows), print the following pattern (for N = 4).

//                        1 
//                      2 3 2
//                    3 4 5 4 3
//                  4 5 6 7 6 5 4
// Input Format
// Constraints
// 0 < N < 10

// Output Format
// Sample Input
// 4
// Sample Output
//                         1
// 		2	3	2
// 	3	4	5	4	3
// 4	5	6	7	6	5	4
// Explanation
// Each number is separated from other by a tab.
