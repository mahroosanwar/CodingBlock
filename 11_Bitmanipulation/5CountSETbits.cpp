//Count SET bits (SET are 1)

#include <iostream>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    while(n>0){
        if((n&1) == 1){
            ans++;
        }
        n = n >> 1;
    }
    cout << ans << endl;
    return 0;
}