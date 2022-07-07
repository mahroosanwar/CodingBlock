//Load Balancer Code

#include<iostream>
using namespace std;

int main() {
    int arr[9000];
    int n, i, val, diff;

    while(1) {
        //take input Current Test case
        int max_load = 0, load = 0;
        cin >> n;
        //stop taking if N = -1;
        if(n == -1) {
            break;
        }

        for(int i=0; i<n; i++) {
            cin >> arr[i];
            load += arr[i];
        } 

        if(load % n != 0) {
            cout << -1 << endl;
            continue;
        }

        //find the laod that is to be divided equally
        load = load/n;
         
         diff = 0;
        //greedy step
        for(int i = 0; i < n; i++) {
            //find the difference bwt final load to be assigned and current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;

        return 0;
    }
}