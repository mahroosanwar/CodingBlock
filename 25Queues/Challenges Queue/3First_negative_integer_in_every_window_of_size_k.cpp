// First negative integer in every window of size k

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int n, int k) {

    vector<int> ans;
    queue<int> q;

    for(int i=0; i<k-1; i++) {
        if(arr[i]<0) q.push(arr[i]);
    }

    for(int i=k-1; i<n; i++) {
        if(arr[i]<0) q.push(arr[i]);

        if(!q.empty()) {
            ans.push_back(q.front());

            if(q.front() == arr[i-k+1]) {
                q.pop();
            }
        }
        else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        for(auto x:printFirstNegativeInteger(arr, n, k)) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
