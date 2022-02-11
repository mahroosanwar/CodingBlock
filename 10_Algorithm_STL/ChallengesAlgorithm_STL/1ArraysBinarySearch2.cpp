//Array binary search method 2 using vector

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        arr.push_back(no);
    }
	int m;
    cin>>m;
	
	if(binary_search(arr.begin(), arr.end(), m)){
        cout<<upper_bound(arr.begin(), arr.end(),m) - arr.begin() - 1<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}
