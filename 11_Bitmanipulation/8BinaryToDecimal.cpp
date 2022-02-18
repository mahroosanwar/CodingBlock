//Decimal to Binary

#include <iostream>
using namespace std;

void DecimalToBinary(int n){
    int ans = 0, place = 1;
    while(n>0){
        ans += (n%2)*place;
        place*=10;
        n/=2;
    }
    cout << ans;
}

//using bitwise operator
void DecimalToBinaryBitwise(int n){
    int ans = 0, place = 1;
    while(n>0){
        ans += (n&1)*place;
        place*=10;
        n = n>>1;
    }
    cout << ans << endl;
}
int main(){
    int n;
    cin >> n;
    DecimalToBinary(n);

    cout << endl;

    DecimalToBinaryBitwise(n);
    return 0;
}