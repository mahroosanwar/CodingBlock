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


// Take as input str, a string. Write a recursive function which returns all the words possible by rearranging the characters of this string which are in dictionary order smaller than the given string. The output strings must be lexicographically sorted.

// Input Format
// Single line input containing a string

// Constraints
// Length of string <= 25

// Output Format
// Display all the words which are in dictionary order smaller than the string entered in a new line each. The output strings must be sorted.

// Sample Input
// cab
// Sample Output
// abc
// acb
// bac
// bca
// Explanation
// The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only four of them are lexicographically less than "cab". We print them in lexicographical order.
