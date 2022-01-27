//print 1 to 10 numbers

#include <iostream>
using namespace std;

int main()
{
    int N, i = 1;       
    cout << " Enter the value of N: " ; 
    cin >> N;             
    
    while (i <= N)
    {
        cout << i << " ";

        i = i + 1;
    }
    return 0;

}
