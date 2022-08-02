//WAP yo find the largest of 5 numbers
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int i, no, largest  = INT_MIN;
    for (i = 1; i <= 5; i = i + 1)
    {
        cin >> no;

        if(largest < no)
        {
            largest  = no;
        }
        
    }
    cout << largest;
    
    
    
    return 0;
}

// Read as input 5 Numbers and print the largest out of them

// Input Format
// 5 Space Separated Numbers (both positive and negative)

// Constraints
// Output Format
// Sample Input
// 2 4 7 -2 3
// Sample Output
// 7
// Explanation
// In the given case 7 is largest among the given numbers.
