//countv Sets Bits

#include <iostream>
using namespace std;

void CountSetBits(int a[], int n){
    for(int i=0; i<n; i++){
        int ans = 0;
        int no = a[i];
        
        while(no > 0){
            if((no&1) == 1){
                ans += 1;
            }
            no >>= 1;
        }
        cout << ans << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    CountSetBits(a,n);
    
    return 0;
}