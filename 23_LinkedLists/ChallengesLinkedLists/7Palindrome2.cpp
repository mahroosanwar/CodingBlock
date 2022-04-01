//Palindrome (method-2)

#include<bits/stdc++.h>
using namespace std;

bool Palindrome(list<int> l)
{
	if(l.empty())
		return true;
	while(!l.empty())
	{
		if(l.front() == l.back())
		{
			l.pop_front();
            
			if(l.empty()){
				return true;
			}
            l.pop_back();
			
		}else
			return false;
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	list<int> l;
	for(int i = 0;i<n;i++)
	{
		int k;
		cin>>k;
		l.push_back(k);
	}

	if(Palindrome(l))
	{
		cout<<"true";
	}else
		cout<<"false";

	
	return 0;
}