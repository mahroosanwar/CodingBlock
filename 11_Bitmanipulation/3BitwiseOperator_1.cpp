//bitwise Operator 1 ( clear bit )

#include <iostream>
using namespace std;

void clearBit(int &n, int i){
    int mask = 1<<i;
    mask = ~ mask;
    n = ( n & mask );
}

void UpdateBit(int &n, int i, int v){       //&n --> whatever changes makes inside the function will also refer to main
    int mask = 1<<i;
    mask = ~ mask;
    //clear bit
    n = ( n & mask );
    //set bit
    n = ( n | (v<<i) );
}
int main(){
    int no = 16;
    // clearBit(no, 3);
    UpdateBit(no, 3, 1);
    cout << "N: " << no << endl;

    return 0;
}
