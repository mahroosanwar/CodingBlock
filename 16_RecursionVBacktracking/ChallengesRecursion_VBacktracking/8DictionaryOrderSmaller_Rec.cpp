// Recursion-Dictionary Order(smaller)


#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool cmp(string x,string y){
    return x < y;
}

void permute(string s,string p,int i, int n,vector<string> &ans)
{
    // thinking about the vse  cas
    if(i==n)
    {
        if(s<p)
        {
            ans.push_back(s);
            return ;
        }
        
        
    }

   // building recurssive case
   for(int j=i;j<n;j++)
   {
       swap(s[i],s[j]);
       permute(s,p,i+1,n,ans);
       swap(s[i],s[j]);
   }

}

int main()
{   
    string s;
    cin>>s;
    string p;
    p=s;
    
    vector<string> ans;
    int n = s.size();
    permute(s,p,0,n, ans);

    sort(ans.begin(), ans.end(), cmp);
    for(auto x:ans){
        cout<<x<<endl;
    }
	
}

