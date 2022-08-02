//WAP to stop Processing Number for Cumulative sum become negative
#include <iostream>
using namespace std;

int main()
{
    int i,n,no,sum = 0;
    
    for (i = 0; i < n; i++)
    {
        cin >> no;
    
        sum = sum + no;  
         if (sum<0)
        {
            break;
        }
        cout << no << endl;
    
    }
    return 0;
}


// Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.

// Input Format
// A list of integers to be processed

// Constraints
// All numbers input are integers between -1000 and 1000.

// Output Format
// Print all the numbers before the cumulative sum become negative.

// Sample Input
// 1
// 2
// 88
// -100
// 49
// Sample Output
// 1
// 2
// 88
