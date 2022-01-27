//Break Statement

#include <iostream>
using namespace std;

int main()

{
    int i = 1;

    while (i <= 10)
    {
        if (i == 5)
        {
            break;   //it will break and come outside the loop
        }
        cout << i << " " ;
        i = i+1;
    }
    return 0;
}