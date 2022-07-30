//4: Bottom Up Fibonacci DP & Space Optimisation

#include<iostream>
using namespace std;

int fibBU(int n) {

    int dp[n] = {0};
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {

    int n;
    cin >> n;

    cout << fibBU(n);
    return 0;
}