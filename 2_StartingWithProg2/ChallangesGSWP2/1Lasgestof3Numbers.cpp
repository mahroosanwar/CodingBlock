// WAP to find the largest of 3 Number

#include <iostream>
using namespace std;

int main()
{
    float a,b,c;
    cout << "Enter value of 1st number: ";
    cin >> a;
    cout << "Enter value of 2nd number: ";
    cin >> b;
    cout << "Enter value of 3rd number: ";
    cin >> c;

    if (a >= b && b >= c)
    {
        cout << a << " is largest" << endl;
    }
    else if (b >= a && b >= c)
    {
        cout << b << " is largest" <<endl; 
    }
    
    else
        cout << c << " is largest" <<endl;
    
    return 0;
}