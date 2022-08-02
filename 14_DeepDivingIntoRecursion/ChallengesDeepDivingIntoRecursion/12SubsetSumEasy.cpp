#include<iostream>
using namespace std;

bool generate_subset(int* arr,int i,int n,int sum,int count){
	//base case
    if(i == n){
		if(sum==0 &&count>0){
			return true;
		}
		else{ 
			return false;
		}
	}

    //recursive case    
	bool opt1=generate_subset(arr,i+1,n,sum+arr[i],count+1);

	bool opt2=generate_subset(arr,i+1,n,sum,count);
    return opt1 || opt2;
}

int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int input[n];
		for(int i=0;i<n;i++){
			cin>>input[i];
		}
		if(generate_subset(input,0,n,0,0)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}

// Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the sum of any of the non-empty subsets of the set A is zero.

// Input Format
// The first line contains an integer T, which is the total number of test cases.
// T test cases follow.
// Each test case consists of two lines.
// The first line consists of a single integer N, which is the number of elements present in the set A.
// The second line contains N space separated integers denoting the elements of the set A.

// Constraints
// 1 ≤ T ≤10
// 1 ≤ N ≤ 4
// -10^5 ≤ A[i] ≤ 10^5

// Output Format
// Print the answer for each testcase in a new line.
// If the sum of any of the subset is zero, then print “Yes” (without quotes) else print “No”(without quotes).

// Sample Input
// 1
// 4
// 1 3 2 -3
// Sample Output
// Yes
// Explanation
// The sum of the subset {3,-3} is zero.
