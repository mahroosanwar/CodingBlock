// C++ program to find minimum number
// of swaps required to sort an array
#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int indexOf(int arr[], int ele, int N)
{
	for(int i = 0; i < N; i++)
	{
		if (arr[i] == ele)
		{
			return i;
		}
	}
	return -1;
}

// Return the minimum number
// of swaps required to sort the array
int minSwaps(int arr[], int N)
{
	int ans = 0;
	// vector<int> temp(arr.begin(),arr.end());
	// sort(temp.begin(),temp.end());
    int temp[N];
    for(int i=0;i<N;i++){
        temp[i] = arr[i];
    }
    sort(temp, temp+N);
	
	for(int i = 0; i < N; i++)
	{
		
		// This is checking whether
		// the current element is
		// at the right place or not
		if (arr[i] != temp[i])
		{
			ans++;

			// Swap the current element
			// with the right index
			// so that arr[0] to arr[i] is sorted
			swap(arr, i, indexOf(arr, temp[i], N));
		}
	}
	return ans;
}

// Driver Code
int main(){

	// vector<int> a = {101, 758, 315, 730,
	// 			472, 619, 460, 479};
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	
	// int n = a.size();
	
	// Output will be 5
	cout << minSwaps(a, n);
	
	return 0;
}


// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

// Input Format
// N
// N elements

// Constraints
// N<=10^7

// Output Format
// Minimum steps

// Sample Input
// 4
// 2 8 5 4
// Sample Output
// 1
// Explanation
// swap 8 with 4.
