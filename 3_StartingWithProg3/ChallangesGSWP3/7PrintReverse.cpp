// Print Reverse

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,num = 0;
    cin >> n;
    int n1 = n;    //intialize another number(n1) equal to n for further use 
    int count = 0;  
    while(n!=0)
    {
        n/=10;
        count++;        //count the number of digit 
    }
    while(n1!=0)
    {
        int rem = n1 % 10;              //for reverse the number
        count--;                        //change the place of 0th digit to count - 1 placed
        num = num + rem*pow(10,count);
        n1 = n1/10;
    }
    cout << num << endl;
    return 0;
}