// Continue Statement

#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    while (i <= 10)
    {
        if (i == 3)
        {
            i = i+1;  //prevent it from stuck in infinite loop
            continue; //not print 3 because it will updated 
        }
    cout << i << " ";
    i = i+1;
    }
    return 0;
}