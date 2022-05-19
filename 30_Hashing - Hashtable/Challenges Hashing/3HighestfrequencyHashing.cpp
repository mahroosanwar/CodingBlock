//Highest frequency( Hashing )

#include<iostream>
#include<unordered_map>
using namespace std;

int HighestFreq(int arr[], int n) {

    unordered_map<int , int> m;

    for(int i=0; i<n; i++) {
        m[arr[i]]++;
    }

    int max_freq = 0;
    int ans = -1;
    for(auto i : m) {
        if(max_freq < i.second) {
            ans = i.first;
            max_freq = i.second;
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << HighestFreq(arr, n);

    return 0;
}