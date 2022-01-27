//Local and Global variable;

#include <iostream>
using namespace std;
int x = 2;          //Global Scope
int main()
{   cout << x << endl; // 1
    int x =1;           //local variable to main block
    int a = 1;
    if (a>0)
    {
        int x=10;           //x:10
        cout << x << endl;  //10
    }
    cout << x << endl;      // x: local variable to main block
    return 0;
}
