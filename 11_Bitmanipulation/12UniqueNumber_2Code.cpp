//Unique Number 2

#include <iostream>
using namespace std;

int main(){
    int a[] = {6,5,1,6,1,3};
    int n = sizeof(a)/sizeof(int);

    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^=a[i];
    }
    
    //1: extrect the bit pos with value 1, that means it would be diff. in both unique numbers
    int result = ans;
    int pos = 0;
    while(ans>0){
        if((ans&1) > 0){
            break;
        }
        pos++;
        ans = ans >> 1;
    }

    //2: we need to separate according to bit position

    int x = 1<<pos;

    int unique1 = 0;
    for(int i=0; i<n; i++){
        if((a[i]&x) == 0){
            unique1 ^= a[i];
        }
    }

    int unique2 = result ^ unique1;
    cout << unique1 << " " << unique2 << endl;

    return 0;
}