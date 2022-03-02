
#include<bits/stdc++.h>
using namespace std; // tower of hanoi

int towerofhanoi(int n, string src, string dest, string helper) {
	int count = 1;
	if (n == 0) {
		return 0;
	}
	count += towerofhanoi(n - 1, src, helper, dest);
	cout << "Move " << n << "th disk from " << src << " to " << dest << endl;

	count += towerofhanoi(n - 1, helper, dest, src);
	return count;
}

int main() {
	int n ;
	cin >> n;
	cout << towerofhanoi(n, "T1", "T2", "T3");
	return 0;
}
