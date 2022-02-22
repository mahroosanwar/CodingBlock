//Playing With Bits

#include <iostream>
using namespace std;

void CountSet_Bits(int a, int b){
    int ans = 0;

    for(int i=a; i<=b; i++){
        int no = i;
        while(no>0){
            if((no&1) == 1){
                ans += 1;
            }
            no >>= 1;
        }
    }
    cout << ans << endl;
}
int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        CountSet_Bits(a, b);
    }
    return 0;
}
