//9: Coin Change Top Down

#include<iostream>
#include<climits>
using namespace std;

int minCoins(int n, int coins[], int T, int dp[]) {

    //base case
    if(n==0) {
        return 0;
    }

    //LookUp
    if(dp[n] !=0 ) {
        return dp[n];
    }

    //rec case
    int ans = INT_MAX;

    for(int i=0; i<T; i++) {
        if(n-coins[i]>=0) {
            int subprob = minCoins(n-coins[i], coins, T, dp);
            ans = min(ans, subprob+1);
        }
    }
    return dp[n] = ans;
}

int main() {

    int n;
    cin >> n;

    int coins[] = {1, 7, 10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);

    cout << minCoins(n, coins, T, dp) << endl;

    return 0;
}