//All Subsequences

#include<iostream>
#include<algorithm>
using namespace std;

void printSubsequences(string *op, int i, string str, string temp, int &pos){
    if(i == str.size()){
        op[pos] = temp;
        pos++;
        return;
    }

    printSubsequences(op, i+1, str, temp, pos);
    // str[i] Stores character present at i-th index of str
    printSubsequences(op, i+1, str, temp + str[i], pos);
}

void Print(string *str, int n){
    for(int i=0; i<n; i++){
        cout << str[i] << endl;
    }
}

int main() {
    int N;                      //no of String
    cin >> N;
    string str;

    for(int i=0; i< N; i++){
        cin>>str;
        string op[100];         //for store the op string
        int pos = 0;            //store the no of o/p(all subsequences) for one string with help of &pos in function
        printSubsequences(op, 0, str, "", pos);
        sort(op, op+pos);       //sort string in lexcicographical
        Print(op, pos);
    }
}