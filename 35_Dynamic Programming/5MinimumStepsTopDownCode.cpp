//5: Minimum Steps Top Down [Code]

#include<iostream>
#include<climits>
using namespace std;

int minSteps(int n, int dp[]) {
    //base case
    if(n==1) {
        return 0;
    }

    //rec case
    //LookUp if n is already computed

    if(dp[n] != 0) {
        return dp[n];
    }

    int op1, op2, op3;

    op1 = op2 = op3 = INT_MAX;

    if(n%3==0) {
        op1 = minSteps(n/3, dp) + 1;
    }

    if(n%2==0) {
        op2 = minSteps(n/2, dp) + 1;
    }

    op3 = minSteps(n-1, dp) + 1;

    int ans = min(min(op1, op2), op3);

    return dp[n] = ans;
}

int main() {

    int n;
    cin >> n;

    int dp[n] = {0};

    cout << minSteps(n, dp) << endl;

    return 0;
}