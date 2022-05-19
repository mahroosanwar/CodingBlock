// Arrays-Intersection Of Two Arrays

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;

void intersection(int A[], int B[], int n){
	map<int,int>m;
	for( int i  = 0; i <n; i++){
		m[A[i]]++; // store count
	}

	sort(B,B+n);

	for( int j = 0; j<n; j++){

		if(m.find(B[j]) !=  m.end()){
            v.push_back(B[j]);

            auto it = m.find(B[j]);
			it->second--;           // decrement count
			if(it->second==0)       // if 0 remove
			{
				m.erase(B[j]);
			}
		}
	}
}

int main() {
	int n;
	cin >>n;
	int A[n];
	int B[n];
	for( int i = 0; i<n; i++) {
		cin >> A[i];
	}

	for( int j = 0; j<n; j++) {
		cin >> B[j];
	}

	intersection(A,B,n);

    //Print

    cout<<"[";

	for(int i=0; i<v.size(); i++) {
		cout<<v[i];

		if(i<v.size()-1) {
			cout<<", ";
		}
	}

	cout<<"]";

	return 0;
}


// Take as input N, the size of array. Take N more inputs and store that in an array.
// Take N more inputs and store that in another array.
// Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.

// Input Format
// First line contains N denoting the size of the two arrays. 
// Second line contains N space separated integers denoting the elements of the first array.
// Third line contains N space separated integers denoting the elements of the second array.

// Constraints
// Length of Arrays should be between 1 to 100000.

// Output Format
// Display the repeating elements in a comma separated manner enclosed in square brackets.
// The numbers should be sorted in increasing order.

// Sample Input
// 7
// 1 2 3 1 2 4 1
// 2 1 3 1 5 2 2

// Sample Output
// [1, 1, 2, 2, 3]

// Explanation
// Check which integer is present in both the arrays and add them in an array .Print this array as the ans.
