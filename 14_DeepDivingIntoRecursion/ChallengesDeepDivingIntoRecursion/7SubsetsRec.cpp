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