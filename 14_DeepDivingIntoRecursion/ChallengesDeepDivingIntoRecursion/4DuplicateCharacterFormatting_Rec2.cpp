#include<iostream>
#include<cstring>
using namespace std;

void  dupc(char str[],int i){
    // base case
    if(str[i]=='\0'){
        return ;
    }
    cout<<str[i];
    if(str[i]==str[i+1]){
        cout<<"*";
    }
    dupc(str,i+1);
}
int main()
{
	char str[100];
	cin>>str;
	dupc(str,0);
}