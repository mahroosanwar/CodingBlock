//2  : Indian Coin Change Code

#include<iostream>
#include<algorithm>
using namespace std;

int make_changes(int *coins, int n, int money) {
    
    int ans = 0;
    while(money>0) {
        //upper_bound gives (ex-it will give  the number >  39 i.e. 50 (idx 0f 50))
        int idx = upper_bound(coins, coins+n, money) - 1 -coins;
        cout << coins[idx] << " + ";
        money = money - coins[idx];
        ans++;
    }
    cout << endl;
    return ans;
}

int main() {
    int money;
    cin >> money;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);

    cout << "coins needed " << make_changes(coins, t, money);

    return 0;
}
