// Print Series

#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = 1; i <= n1; i++)
    {
        int num = 3*i + 2;
        if((num%n2)!= 0)
        {
            cout << num << endl;
        }
        else{
            n1++;           //it increase n1 as many times as num%2 == 0 
        }
    }
    return 0;
}