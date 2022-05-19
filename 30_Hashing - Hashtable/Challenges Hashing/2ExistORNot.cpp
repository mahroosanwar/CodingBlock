// Exist OR Not

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<int, bool> m;

    int t;
    cin >> t;

    while(t--) {

        int L;
        cin >> L;
        int num;

        while(L--) {
            cin >> num;
            m[num] = true;
        }

        int Q;
        cin >> Q;

        while(Q--) {
            cin >> num;

            if(m.count(num)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        m.clear();
    }

    return 0;
}


// Given an array arr of n length. You will be given Q queries for the array.
// Each query contains a number N.You have to determine whether a number exist in the array or not

// Input Format
// First line of input contains number of test cases T.
// First line of each case contains an integer L denoting the length of the array.
// The next line contains L space separated integers.
// The next line contains an integer Q denoting the number of queries.
// The next Q lines contains a number N to be searched in the array.

// Constraints
// 1<=t<=12
// 1<=L<=10^5 (n=number of elements in array).
// -10^5<=A[i]<=10^5 (A[i]=ith element of array).

// 1<=Q<=10^4
// -10^5<=x<=10^5

// Output Format
// For each Query print “Yes” if the number is present and “No” if it’s not.

// Sample Input
// 1
// 6
// 12 3 -67 67 34 2
// 4
// 4
// 5
// 67
// 7
// Sample Output
// No
// No
// Yes
// No