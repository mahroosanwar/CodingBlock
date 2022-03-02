//Duplicate Character Formatting_Rec Method 3

#include<bits/stdc++.h>
using namespace std;
void replacei(string & s,string & t,int i=0){
    t=t+s[i];
    if(s[i]=='\0')return ;
    if(s[i]==s[i+1])t=t+'*';
    replacei(s,t,i+1);
}
int main(){
    string s ,t="";
	cin>>s;//added this
    replacei(s,t);
	t.pop_back();//because null is also added to string that should not cause an issue but idk its causing here
    cout<<t;
return 0;
}