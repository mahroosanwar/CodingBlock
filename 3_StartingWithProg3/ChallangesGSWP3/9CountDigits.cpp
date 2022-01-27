// Count Digits

#include <iostream>
using namespace std;

int main()
{
    int n,rem,count=0;
    cin >> n;
    int digit;
    cin >> digit;

    while(n!=0)
    {
        rem = n%10;
        n = n/10;
        if(rem == digit){
            count++;
        }
       
    }
    cout << count << endl;
    
    return 0;
}