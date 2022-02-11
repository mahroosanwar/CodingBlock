//sort Game method 2 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<string,int> p1,pair<string,int> p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}

	return p2.second < p1.second;
}

int main() {
	int x,n,sal;
	cin>>x>>n;
	string str;
	vector<pair<string,int>> v;
	for(int i=0;i<n;i++){
		cin>>str;
		cin>>sal;
		if(sal >= x){
			v.push_back(make_pair(str,sal));
		}
	}

	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}

	return 0;
}