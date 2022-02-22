//XOR Profit Problem

#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;

    //find the xor of x and y
    int num = x^y;

    //find the position of msb of num
    int pos = 0;
    while(num){
        num >>= 1;
        pos++; 
    }
    //print the ans
    cout << (1<<pos)-1;

    return 0;
}