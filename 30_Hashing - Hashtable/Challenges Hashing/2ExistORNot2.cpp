//Exist OR Not

#include <bits/stdc++.h>
using namespace std;

void ExistORNot(int arr[], int Q[], int n, int q) {
    set<int> s;

    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
    }

    for(int i=0; i<q; i++) {
        if(s.find(Q[i]) != s.end()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int L;
        cin >> L;

        int arr[L];

        for(int i=0; i<L; i++) {
            cin >> arr[i];
        }

        int q;
        cin >> q;

        int Q[q];
        for(int i=0; i<q; i++) {            
            cin >> Q[i];            
        }
        
        ExistORNot(arr, Q, L, q);

    }
	return 0;
}
