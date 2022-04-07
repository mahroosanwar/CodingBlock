//8 Find the greater element 2

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the NGE for the
// given circular array arr[]
void printNGE(int* arr, int n)
{
	// Initialize stack and nge[] array
	stack<int> s;
	int nge[n], i = 0;

	// Initialize nge[] array to -1
	for (i = 0; i < n; i++) {
		nge[i] = -1;
	}
	i = 0;

	// Traverse the array
	while (i < 2 * n) {

		// If stack is not empty and
		// current element is greater
		// than top element of the stack
		while (!s.empty()
			&& arr[i % n] > arr[s.top()]) {

			// Assign next greater element
			// for the top element of the stack
			nge[s.top()] = arr[i % n];

			// Pop the top element
			// of the stack
			s.pop();
		}

		s.push(i % n);
		i++;
	}

	// Print the nge[] array
	for (i = 0; i < n; i++) {
		cout << nge[i] << " ";
	}
}

// Driver Code
int main()
{
    int n;
    cin>> n;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

	printNGE(a, n);
	return 0;
}
