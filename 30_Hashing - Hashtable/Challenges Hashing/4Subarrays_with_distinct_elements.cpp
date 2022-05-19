//Subarrays with distinct elements

#include<bits/stdc++.h>
using namespace std;

int sumoflength(int arr[], int n) {
	// For maintaining distinct elements.
	unordered_set<int> s;

	// Initialize ending point and result
	int j = 0, ans = 0;

	// Fix starting point
	for (int i=0; i<n; i++) {
		// Find ending point for current subarray with
		// distinct elements.
		while (j < n && s.find(arr[j]) == s.end()) {
			s.insert(arr[j]);
			j++;
		}

		// Calculating and adding all possible length
		// subarrays in arr[i..j]
		ans += ((j - i) * (j - i + 1))/2;

		// Remove arr[i] as we pick new starting point
		// from next
		s.erase(arr[i]);
	}

	return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

	cout << sumoflength(arr, n) << endl;
	return 0;
}

// Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct

// Input Format
// An integer n denoting size of array followed by n integers

// Constraints
// 1<=N<=10^5

// Output Format
// The answer mod 10^9+7

// Sample Input
// 3
// 1 2 3
// Sample Output
// 10
// Explanation
// {1, 2, 3} is a subarray of length 3 with distinct elements.
// Total length of length three = 3.
// {1, 2}, {2, 3} are 2 subarray of length 2 with distinct elements.
// Total length of lengths two = 2 + 2 = 4 {1}, {2}, {3} are 3 subarrays of length 1 with distinct element.
// Total lengths of length one = 1 + 1 + 1 = 3 Sum of lengths = 3 + 4 + 3 = 10
