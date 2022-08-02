//  Recursion-Subsequences

#include <iostream>
using namespace std;
int cnt = 0;
void  Rec_Subsequences(char *ip, char *op, int i, int j){
    //base case
    
    if(ip[i] == '\0'){
        cnt++;
        op[j] = '\0';
        cout << op << " ";
        return;
    }

    //recursion case
    //1--> ignore the ith char;  
    Rec_Subsequences(ip, op, i+1, j);

    //2--> take the ith char
    op[j] = ip[i];

    //and increase i and j

    Rec_Subsequences(ip, op, i+1, j+1);

}
int main(){
    char a[100];
    cin >> a;
    char op[100];
    Rec_Subsequences(a, op, 0, 0);
    cout << '\n' << cnt;

}

//  Recursion-Subsequences

#include <iostream>
using namespace std;
int cnt = 0;
void  Rec_Subsequences(char *ip, char *op, int i, int j){
    //base case
    
    if(ip[i] == '\0'){
        cnt++;
        op[j] = '\0';
        cout << op << " ";
        return;
    }

    //recursion case
    //1--> ignore the ith char;  
    Rec_Subsequences(ip, op, i+1, j);

    //2--> take the ith char
    op[j] = ip[i];

    //and increase i and j

    Rec_Subsequences(ip, op, i+1, j+1);

}
int main(){
    char a[100];
    cin >> a;
    char op[100];
    Rec_Subsequences(a, op, 0, 0);
    cout << '\n' << cnt;

}

// Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

// a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

// b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string (void is the return type for function).
// Note: Use cin for input for C++

// Input Format
// Enter a string

// Constraints
// None

// Output Format
// Print all the subsequences in a space separated manner and isplay the total no. of subsequences.

// Sample Input
// abcd
// Sample Output
//  d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
// 16
// Explanation
// Print all possible subsequences of the given string.
