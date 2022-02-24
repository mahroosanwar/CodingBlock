//Power

#include <iostream>
using namespace std;

int Power(int a,int n){
    //base case
    if(n==0){
        return 1;
    }
    return a*Power(a,n-1);
}
int main(){
    int a, n;
    cin >> a >> n;

    cout << Power(a,n);
    return 0;
}