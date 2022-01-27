//WAP to find  nCr

#include <iostream>
using namespace std;

int fact(int n){
    int ans = 1;
    for(int no = 1; no<=n; no++){
        ans *= no;
    }
    return ans;
}

int nCr(int n, int r){
    int a = fact(n);
    int b = fact(r);
    int c = fact(n-r);

    int ans = a/(b*c);
    return ans;
}
int main(){
    int n, r;
    cin >> n >>r;

    cout << nCr(n,r) << endl;
    cout << endl;
    return 0 ;
}