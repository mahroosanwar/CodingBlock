//Find tge unique no. out of  2*n+1 ,n no. occur twice
#include <iostream>
using namespace std;

int main()
{
    int n,no,ans = 0;
    cin >> n;
    for ( int i = 0; i<n; i++){
        cin >> no;
        
        ans = ans^no;
    }   
    cout << "Unique no. " << ans << endl;
        
    return 0;
}