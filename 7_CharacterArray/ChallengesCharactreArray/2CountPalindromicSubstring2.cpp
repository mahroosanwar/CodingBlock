#include<iostream>
using namespace std;

bool isPalindrome(string str){
    int s = 0;
    int e = str.size()-1;
    while(s < e){
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main() {
    string str;
    cin>>str;
    int len = str.size();
    int cnt = 0;

    for(int i=0;i<len;i++){
        string temp;
        for(int j=i;j<len;j++){
            temp += str[j];
            if(isPalindrome(temp)){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}
