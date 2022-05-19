//String Window

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	string p;
	getline(cin,s);
	getline(cin,p);

	map<char,int>sm;
	map<char,int>pm;

	for(auto c : p)pm[c]++;

	int si=0;
	int count=0;
	int ans = INT_MAX;
    int asi = -1;               // ans start index

	for(int i=0;i<s.length();i++){
		sm[s[i]]++;

        // pattern me h aur zyada h
		if(pm[s[i]] != 0 and pm[s[i]] >= sm[s[i]]){
			count++;
		}
		
        // look up ? can we reduce
        if(count==p.length()){
            while(pm[s[si]] == 0 or pm[s[si]] < sm[s[si]]){
                sm[s[si]]--;
                si++;
            }

            int window = i-si+1;
            if(ans > window){
                ans = window;
                asi = si;
            }
        }
	}

    if(asi==-1)cout<<"No String"<<endl;
    else cout<<s.substr(asi,ans)<<endl;
    
	return 0;
}