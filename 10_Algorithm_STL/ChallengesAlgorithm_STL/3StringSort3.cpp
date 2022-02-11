// String sort method 3

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2){
	if(mismatch(s1.begin(),s1.end(),s2.begin(),s2.end()).first == s1.end()) return false;
	else if(mismatch(s2.begin(),s2.end(),s1.begin(),s1.end()).first == s2.end()) return true;
	else return s1<s2;
}

int main(){
	int n;
	cin>>n;
	vector<string> names;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		names.push_back(s);
	}
	sort(names.begin(),names.end(),compare);
	for(int i=0;i<n;i++)
	{
		cout<<names[i]<<endl;
	}
	return 0;
}
