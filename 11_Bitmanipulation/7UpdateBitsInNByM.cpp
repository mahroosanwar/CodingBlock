//Update Bits in N by M

#include <iostream>
using namespace std;

void clearBits(int &n, int j, int i){
    int ma = ~0;
    ma = ma << j;
    int mb = (1<<i) - 1;
    int mask = ma | mb;
    n = n & mask;
}

void UpdateBits(int &n, int m, int j, int i){
    clearBits(n,j,i-1);
    m = m << (i-1);
    n = n | m;
}
int main(){
    int n, m, j, i;
    cin >> n >> m >> j >> i;
    UpdateBits(n,m,j,i);
    cout << n << endl;
}