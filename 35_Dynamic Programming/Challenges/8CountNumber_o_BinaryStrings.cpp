//8: Count Number of Binary Strings

#include<iostream>
#include <vector>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <pair <long long int,long long int> > dp (n+1);	//ends with 0,1
		dp[0] = make_pair(0,0);
		dp[1] = make_pair(1,1);
		for(int i=2; i<=n; i++){
			long long int endWith1 = dp[i-1].first;
			long long int endWith0 = dp[i-1].first + dp[i-1].second;
			dp[i] = make_pair(endWith0, endWith1);
		}
		cout << dp[n].first + dp[n].second << endl;
	}
	return 0;
}

// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Constraints
// 1<=t<=100 1<=n<=90

// Output Format
// Print the number of all possible binary strings.

// Sample Input
// 2
// 2
// 3
// Sample Output
// 3
// 5
// Explanation
// 1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

