#include <bits/stdc++.h>
using namespace std;

string encode(string s){
    if (s.size() == 0){
        return "";
    }
    int a=1;
    string str="";
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            a++;
        }
        else
        {
            str=str+s[i];
            str=str+to_string(a);
            a=1;
        }
    }

   if(s[s.length()-2]!=s[s.length()-1]){
       str=str+s[s.length()-1];
       str=str+'1';
   }
   else{
       str=str+s[s.length()-1];
       str=str+to_string(a);
   }
   return str;
}

int main(){
    string s;
    cin >> s;

    cout << encode(s) << endl;

    return 0;
}
