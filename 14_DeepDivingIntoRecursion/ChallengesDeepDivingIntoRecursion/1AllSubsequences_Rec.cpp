// Recursion - All subsequences

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void AllSubsequences(string *str, char *in, char *op, int i, int j, int &a){
    //base cases

    if(in[i] == '\0'){
        op[j] = '\0';
        str[a] = op;
        a++;
        return;
    }

    //recursive case
    
    //1 --> ignore the ith char
    AllSubsequences(str, in, op, i+1, j, a);

    //copy ith char in op jth position
    op[j] = in[i];

    AllSubsequences(str, in, op, i+1, j+1, a);
}

void Print(string *str, int n){
    for(int i=0; i<n; i++){
        cout << str[i] << endl;
    }
}

int main(){
    int N;          //no of String
    cin >> N;           
    char ip[20];
    char op[100];

    for(int i = 0; i<N; i++){
        int n = 0;          //store the no of o/p(all subsequences) for one string with help of &a in function
        string s[100];      //for store the op string
        cin >> ip;
        AllSubsequences(s, ip, op, 0, 0, n);
        sort(s , s+n);          //sort string in lexcicographical
        Print(s, n);
    }
    return 0;
}


// Print all the subsequences of a string in lexicographical order.

// Input Format
// First line contains an integer N, the no of strings.
// Next, N lines follows one string per line.

// Constraints
// 1 < len(str) < 20

// Output Format
// No of subsequences one per line

// Sample Input
// 1  
// ab
// Sample Output
  
// a  
// ab  
// b  
// Explanation
// 4 subsequences are printed.
// Empty string is a subsequence.
