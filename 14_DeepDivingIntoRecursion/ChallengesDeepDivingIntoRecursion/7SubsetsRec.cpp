//Subset Recursion
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
bool myCompare(vector<int>&a,vector<int>&b){
    return a.size()<b.size();
}
void allsubsets(int arr[],int n,vector<int> v,int sum)
{  
    if(sum==0)
    {
        ans.push_back(v);
        return;
    }
    if(n==0)
    {
        return;
    }
    v.push_back(arr[n-1]);
    allsubsets(arr,n-1,v,sum-arr[n-1]);
    v.pop_back();
    allsubsets(arr,n-1,v,sum);
}
void printsub(int arr[],int n,int sum)
{
    vector<int>v;
    
    allsubsets(arr,n,v,sum);
}
int main() {
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    printsub(arr,n,k);
    sort(ans.begin(),ans.end(),myCompare);
    for(auto v:ans){
        for(auto ele:v){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}


// Find all the subsets of a given array that sum to k.

// Input Format
// The first line contains an integer N , the size of the array. The next line conatins N integers. The next line contains an integer K.

// Constraints
// 0 < N <= 20

// Output Format
// Output all the subsets that sum to K. The output should be printed as follows :

// 1. Sets with least no of elements should be printed first.
// 2. For equal length, elements that appear later in the original set,should be printed first.
// Sample Input
// 5
// 1 4 6 5 3
// 10
// Sample Output
// 6 4
// 3 6 1
// 5 4 1
// Explanation
// 4 + 6 = 10
// 1 + 4 + 5 = 10
// 1 + 3 + 6 = 10
