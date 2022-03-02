//Ascii Subsequences

#include <bits/stdc++.h>
using namespace std;

void AsciiSubsequences(string str, int i, string curr, int &cnt){
    //base case
    if(i == str.size()){
        cnt++;
        cout << curr << " ";
        return;
    }

    //recursive case
    //1--> ignore the ith char
    AsciiSubsequences(str, i+1, curr, cnt);
    //2--> take the ith char and store in the op jth char 
    AsciiSubsequences(str, i+1, curr  + str[i], cnt);
    
    // Include the ASCII value to curr

    string ascii;
    ascii = to_string((int)str[i]);
    AsciiSubsequences(str, i+1, curr + ascii, cnt);
}

int main(){
    string s;
    cin >> s;

    int cnt = 0;
    AsciiSubsequences(s, 0, "", cnt);
    cout << '\n' << cnt;

    return 0; 
}