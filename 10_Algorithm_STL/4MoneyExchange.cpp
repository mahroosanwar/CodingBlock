//Money exchange problem

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a<=b;
}
int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int n = sizeof(coins)/sizeof(int);

    int money;
    cin >> money;

    while(money>0){
        //compare function will change lower_bound function >=key to <=key
        int index = lower_bound(coins, coins+n, money, compare) - coins - 1;
        cout << "We would give exchange of coin: " << coins[index] << endl;
        money -= coins[index];
    }
    return 0;
}