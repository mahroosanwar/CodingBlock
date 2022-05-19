// Arrays-Intersection Of Two Arrays

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr1, vector<int>arr2, vector<int> &ans) {
	
    map<int, int> hs;

	for(int i=0; i<arr1.size(); i++) {
		hs[arr1[i]]++;
	}

	for(int i=0; i<arr2.size(); i++) {
		if(hs[arr2[i]]) {
			ans.push_back(arr2[i]);
			hs[arr2[i]]--;
		}
	}
	return;
}

int main() {
	int n;
	cin>>n;

	vector<int> arr1(n);
	vector<int> arr2(n);

	for(int i=0; i<n; i++) {
		int no;
		cin>>no;
		arr1[i] = no;
	}

	for(int i=0; i<n; i++) {
		int no;
		cin >> no;
		arr2[i] = no;
	}

	vector<int> ans;

	print(arr1,arr2,ans);

    sort(ans.begin(),ans.end());

	cout<<"[";

	for(int i=0; i<ans.size(); i++) {
		if(i == ans.size()-1) {
			cout << ans[i];
		}
		else{
			cout<<ans[i]<<", ";
		}
	}

    cout<<"]";

	return 0;
}