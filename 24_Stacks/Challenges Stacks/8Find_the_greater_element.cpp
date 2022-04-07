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