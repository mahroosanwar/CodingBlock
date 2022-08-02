// Pattern Mountain

#include <iostream>
using namespace std;


int main()
{
    int i,j,n;
    cin >> n;
    for (i = 0; i<n; i++)
    {   int no = 1;
        for(j=0; j<=i; j++)
        {    cout << no << "    ";
            no++;
        }
        for(j = 0; j<2*(n-i)-3; j++)
            cout << "     ";

        int bottom_line = i+1,no1 = i+1;
        if (i == n-1)
        {
            bottom_line--;
            no1--;
        }
        
        for (j = 0; j<bottom_line; j++)
        {
            cout << no1 << "    ";
            no1--;
        }
    cout << endl;
    }
    return 0;
}


// Take N (number of rows), print the following pattern (for N = 4).

//                        1           1
//                        1 2       2 1  
//                        1 2 3   3 2 1
//                        1 2 3 4 3 2 1   
// Input Format
// Constraints
// 0 < N < 10

// Output Format
// Sample Input
// 4
// Sample Output
// 1						1
// 1	2				2	1
// 1	2	3		3	2	1
// 1	2	3	4	3	2	1
