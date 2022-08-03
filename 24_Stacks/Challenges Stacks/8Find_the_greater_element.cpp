//Find the greater element

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!s.empty() && nums[s.top()] <= nums[i % n])
        {
            s.pop();
        }

        res[i % n] = (s.empty() ? -1 : nums[s.top()]);
        s.push(i % n);
    }

    return res;
}

int main() {
	int n;
    cin>>n;
    vector<int> arr(n);
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    vector<int> res = nextGreaterElements(arr);

    for(auto x : res){
        cout<<x<<" ";
    }

	return 0;
}


// We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

// Input Format
// First line contains the length of the array n. Second line contains the n space separated integers.

// Constraints
// 1 <= n <= 10^6
// -10^8 <= Ai <= 10^8 , 0<= i< n

// Output Format
// Print n space separated integers each representing the next greater element.

// Sample Input
// 3
// 1 2 3
// Sample Output
// 2 3 -1
// Explanation
// Next greater element for 1 is 2,
// for 2 is 3 but not present for 3 therefore -1
