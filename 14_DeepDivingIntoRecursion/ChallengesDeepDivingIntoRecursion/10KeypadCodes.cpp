#include<bits/stdc++.h>
using namespace std;

string key[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
int cnt = 0;

void keypad(char *in,char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<" ";
        cnt++;
        return;
    }
    int digit=in[i]-'0';
    for(int k=0;key[digit][k]!='\0';k++){
        out[j]=key[digit][k];
        keypad(in,out,i+1,j+1);
    }
}

int main() {
    char in[100],out[100];
    cin>>in;
    keypad(in,out,0,0);
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}