//Working in ranges

#include <iostream>
#include <cmath>
using namespace std;

//(clear the first ith bits)
void ClearBit_Range(int &n, int i){
    int mask = ~0;
    mask = mask << i;
    n = n & mask;
}

//Clear bit from jth to ith
void ClearBits_j_to_i(int &n,int j, int i){
    int ma = ~0;
    ma = ma << j;
    //mb = 2^i-1
    int mb  = (1<<i) - 1;
    int mask = (ma | mb);
    n = n & mask;
}

int main(){
    int n, i;
    cin >> n >> i;

    // ClearBit_Range(n, i);
    // cout << n << endl;
    int j; 
    cin >>j;
    
    ClearBits_j_to_i(n,j,i);
    cout << n << endl;
    return 0;
}
