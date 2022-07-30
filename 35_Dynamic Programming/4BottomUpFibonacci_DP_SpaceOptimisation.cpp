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

//bottom up approach with space optimization
int fibBU_space_Opt(int n) {

    //base case
    if(n == 0 || n == 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for(int i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c; 
    }

    return c; 
}

int main() {

    int n;
    cin >> n;

    cout << fibBU_space_Opt(n);
    return 0;
}
