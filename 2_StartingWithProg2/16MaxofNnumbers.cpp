//Max of N numbers

#include <iostream>
#include <climits>   //to get the least value of bucket list
//#include <cmath>
using namespace std;

int main()
{
    int i = 1, N ,num, largest = INT_MIN ;//largest = -pow(2,31)
                                 // INT_MIN = -2^31,INT_MAX = 2^31-1   
    cout << "How many numbers: " <<endl;
    cin >> N;

    while (i <= N)
    {
        cout << "Enter the Number: " << endl;
        cin >> num;
        if (largest < num )
        {
            largest = num;
        }
    i = i + 1;
    }
    cout << "Largest number is: " << largest ;
    return 0;
}