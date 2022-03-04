#include<bits/stdc++.h>
using namespace std;

vector<string>v;

void checkSum(int *a, int i, int j, int n, int *out, int key, int sum){
	if(sum == key){
		string ans;
		for(int k=0;k<j;k++)ans += to_string(out[k]) + " ";
		v.push_back(ans);
		return;
	}	

	if(i<0)return;

	sum += a[i];
	out[j] = a[i];
	checkSum(a,i-1,j+1,n,out,key,sum);
	sum -= a[i];
	checkSum(a,i-1,j,n,out,key,sum);
}

bool comp(string a, string b){
	return a.length() < b.length();
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;
	cin>>key;

	int out[100];
	checkSum(a,n-1,0,n,out,key,0);

	sort(v.begin(),v.end(),comp);
	for(auto x : v)cout<<x<<endl;

	return 0;
}