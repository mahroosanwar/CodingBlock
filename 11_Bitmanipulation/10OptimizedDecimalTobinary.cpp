//optimized Decimal to Binary

#include <iostream>
using namespace std;

void DecimalTobinary(int n){
    int mask = 1<<30;

    bool isOneFound = false;
    while(mask != 0){
        if((n&mask) == 0 && isOneFound == false){
            mask = mask >> 1;
            continue;
        }
        else{
            isOneFound = true;
            if((n&mask) > 0 ){
                cout << 1;
            }
            else{
                cout << 0;
            }
            mask = mask >> 1;
        }
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    DecimalTobinary(n);

    return 0;
}