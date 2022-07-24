//9: Print LCS

#include <iostream>
#include<algorithm>
using namespace std;

void printLCS(string x,string y){
    int l1 = x.size();
    int l2 = y.size();

    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string str;
    int i = l1;
    int j = l2;

    while(i>0 and j>0){
        if(x[i-1] == y[j-1]){
            str += x[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]> dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;
}

int main() {
    string x,y;
    cin>>x>>y;
    printLCS(x,y);
}


// A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

// Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

// Note: It is gauranteed that there is only one unique longest common subsequence

// Input Format
// Two strings A and B.

// Constraints
// 1 <= n,m <= 10^3

// Output Format
// Output the LCS of A and B.

// Sample Input
// abc
// acd
// Sample Output
// ac