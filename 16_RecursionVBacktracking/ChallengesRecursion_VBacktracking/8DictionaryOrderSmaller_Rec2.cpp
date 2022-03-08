#include<iostream>
#include<set>
using namespace std;

bool myCompare(string a,string b)
{
    if(a<b)
    {
        return true;
    }
    return false;
}
set<string>ans;
void permute(string str,string out,int i)
{
	//base case
	if(str[i] == '\0')
    {
	   if(myCompare(str,out))
       {
          ans.insert(str);
       }
       return;
	}
	//to find all the possible words
	for(int j=i; str[j] != '\0'; j++){
		swap(str[i],str[j]);
		//recursive case
		permute(str,out,i+1);
		swap(str[i],str[j]);
	}
}

int main()
{
	string str;
	cin>>str;
    string out;
    out=str;
	permute(str,out,0);

    for(auto it:ans)
        cout<<it<<endl;

	return 0;
}
