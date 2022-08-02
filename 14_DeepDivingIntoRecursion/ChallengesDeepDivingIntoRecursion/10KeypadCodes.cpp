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

// Take as input str, a string. str represents keys pressed on a nokia phone keypad. We are concerned with all possible words that can be written with the pressed keys.

// Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz

// E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

// a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.

// b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).

// Input Format
// Single line input containing a single integer.

// Constraints
// 1 <= Length of string <= 10^3

// Output Format
// Print all the words in a space separated manner. Also print the count of these numbers in next line.

// Sample Input
// 12
// Sample Output
// ad ae af bd be bf cd ce cf
// 9
// Explanation
// 1 can correspond to 'a' , 'b' or 'c' .
// 2 can correspond to 'd', 'e' or 'f'.
// We print all combinations of these
