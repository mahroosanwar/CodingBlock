#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter Value of a: " << endl; 
    cin >> a ;

    if (a>=0 && a<=10)
    {
        cout << "Hello" << endl;
    }
    else if (a>10 && a<=20)
    {
        cout << "World" << endl;
    }
    else                    //this else is optional
    {
        cout << "Hello World" << endl;
    }
    return 0;
}