//10: Coin Change Bottom Up [Code]

#include<iostream>
#include<climits>
using namespace std;

int minCoinsBU(int N, int coins[], int T) {
    int dp[100] = {0};

    for(int n=1; n<=N; n++) {
        //Init the current ans as int_max
        dp[n] = INT_MAX;

        for(int i=0; i<T; i++) {
            if(n-coins[i] >= 0) {
                int subprob = dp[n-coins[i]];
                dp[n] = min(dp[n], subprob+1); 
            }
        }
    }
    return dp[N];
}

int main() {

    int n;
    cin >> n;

    int coins[] = {1, 7, 10};
    int T = sizeof(coins)/sizeof(int);

    cout << minCoinsBU(n, coins, T) << endl;

    return 0;
}
