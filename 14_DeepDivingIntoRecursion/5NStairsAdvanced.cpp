//NStairs-Advanced

#include <iostream>
using namespace std;

int NStairsAdvanced(int n, int k){
    //base case
    if(n==0)return 1;

    if(n<0)return 0;

    //recursive case
    int ans = 0;
    for(int i = 1; i<=k; i++){
        ans += NStairsAdvanced(n-i, k);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;

    cout << NStairsAdvanced(n, k);

    return 0;
}