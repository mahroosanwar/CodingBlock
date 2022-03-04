//Recursion Subsequences

#include<iostream>
using namespace std;

void printSubsequences(int i,string temp,string str,int &cnt){
    if(i == str.size()){
        cout<<temp<<" ";
        cnt++;
        return;
    }
    
    printSubsequences(i+1,temp,str,cnt);
    printSubsequences(i+1,temp+str[i],str,cnt);
}

int main() {
    string str;
    cin>>str;
    int cnt = 0;
    printSubsequences(0,"",str,cnt);
    cout<<endl<<cnt;
}
