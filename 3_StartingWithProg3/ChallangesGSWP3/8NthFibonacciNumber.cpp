// Nth fibonacci number

#include <iostream>
using namespace std;

int main()
{
    int n, num, n1 = 0, n2 = 1;
    cin >> n;
    for (int i = 0; i< n-1 ; i++)       //total digits n-2 from 0 to n-1 & plus n1=0,n2=1
                                        //so total digit are n
    {
        num = n1 + n2;
        n1 = n2;
        n2 = num;
    }
    cout << num << endl;
    return 0;
}
