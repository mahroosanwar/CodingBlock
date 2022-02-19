//Unique Number 3 code

#include <iostream>
using namespace std;

int main(){
    int a[] = {3,3,5,6,6,6,3};
    int n = sizeof(a)/sizeof(int);

    int cnt[64] = {0};
    for(int i=0; i<n; i++){
        int pos = 0;
        int no = a[i];

        while(no>0){
            if((no&1)==1){
                cnt[pos]++;
            }
        no = no >> 1;
        pos++;
        }
    }

    for(int i=0; i<64; i++){
        cnt[i] %=3;
        // cout << cnt[i] << " ";
    }
    //Binary to decimal
    int ans =0;
    int p = 1;

    for(int i=0; i<64; i++){
        ans += cnt[i]*p;
        p <<= 1;  // equi to p*=2;
    }
    cout << "Unique No.: " << ans << endl;


    return 0;
}

