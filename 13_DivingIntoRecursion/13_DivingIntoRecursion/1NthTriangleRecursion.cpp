// Nth Triangle Recursion

#include <iostream>
using namespace std;

int NthTriangleRec(int n){
    //base case
    if(n==1){
        return 1;
    }
    //Recursive Case
    return n+NthTriangleRec(n-1);
}

int main(){
    int n;
    cin >> n;

    int ans = NthTriangleRec(n);
    cout << ans;

    return 0;
}
