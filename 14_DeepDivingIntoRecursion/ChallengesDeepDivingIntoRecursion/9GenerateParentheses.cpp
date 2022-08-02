//Generate Parentheses

#include <iostream>
using namespace std;

void GenerateParentheses(char *a, int n, int open, int close, int i){
    //base case
    if(i == 2*n){
        a[i] = '\0';
        cout << a << endl;
    }

    //recursive case
    if(open > close){
        a[i] = ')';
        GenerateParentheses(a, n, open, close+1, i+1);
    }
    if(open < n){
        a[i] = '(';
        GenerateParentheses(a, n, open+1, close, i+1);
    }
}

int main(){
    int n;
    cin >> n;
    char a[n];
    GenerateParentheses(a, n, 0, 0, 0);
    return 0;
}

// Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.

// Input Format
// Single line containing an integral value 'n'.

// Constraints
// 1<=n<=11

// Output Format
// Print the balanced parentheses strings with every possible solution on new line.

// Sample Input
// 2
// Sample Output
// ()() 
// (()) 
// Code Editor
