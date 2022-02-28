//Subsequences

#include <bits/stdc++.h>
using namespace std;


void Subsequences(char *ip, char *op, int i, int j){
    //base case
    if(ip[i] == '\0'){
        op[j] = '\0';
        cout << op << endl;
        return;
    }

    //Recursive case
    //1 --> ignore the ith char
    Subsequences(ip, op, i+1, j);

    //copy ith char in op jth position

    op[j] = ip[i];
    Subsequences(ip, op, i+1, j+1);
}

int main(){
    char ip[] = "abc";
    char op[100];

    Subsequences(ip, op, 0, 0);
    
    return 0;
}