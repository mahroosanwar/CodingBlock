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