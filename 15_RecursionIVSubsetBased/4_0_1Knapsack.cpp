//0-1 KnapSack

#include <iostream>
using namespace std;

int Knapsack(int *wt, int *price, int n, int capacity){
    //base case
    if(capacity == 0 || n == 0) return 0;

    //recursive case
    int inc = INT_MIN, exc = INT_MIN;
    if(capacity >= wt[n-1]){
        //include (we pick (n-1)th product
        inc = price[n-1] + Knapsack(wt, price, n - 1, capacity - wt[n-1]); 
    }
    //exclude (we haven't pick (n-1)th product)
    exc = Knapsack(wt, price, n-1, capacity);

    return max(inc, exc);
}
int main(){
    int wt[] = {1 ,2 ,3, 5};
    int n = sizeof(wt)/sizeof(int);

    int price[] = {20, 50, 60, 100};
    int capacity = 6;

    cout << Knapsack(wt, price, n, 6);
    return 0;
}