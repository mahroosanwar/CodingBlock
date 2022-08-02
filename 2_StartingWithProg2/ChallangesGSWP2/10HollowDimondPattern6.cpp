//Hollow Dimond Pettern 6

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,n;
    cin >> N;
    n = N/2+1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i; j++)
        cout << "*    ";

        for (j=0; j <(2*i-1); j++)
        cout << "     ";

        int no_of_stars = n-i;
        if (i==0)
            no_of_stars--;
        
        for (j=0; j < no_of_stars; j++)
        cout << "*    ";

    cout << endl;
    }

    for (i = n-2; i >= 0; i--)
    {
        for (j=0; j<n-i; j++)
            cout << "*    ";

        for (j=0; j<(2*i-1); j++)
            cout << "     ";

        int no_of_stars = n-i;
        if (i==0)
            no_of_stars--;
        for (j=0; j<no_of_stars; j++)
            cout << "*    ";

    cout << endl;
    }
    return 0;
}


// Take N (number of rows), print the following pattern (for N = 5).

//      * * * * *
//      * *   * *
//      *       *
//      * *   * *
//      * * * * *
// Input Format
// Constraints
// 0 < N < 10 (where N is an odd number)

// Output Format
// Sample Input
// 5
// Sample Output
// *	*	*       *      *		  
// *	*	        *      *
// * 	                       *
// * 	*               *      *
// * 	*	*       *      *	
// Explanation
// Each '*' is separated from other by a tab.
