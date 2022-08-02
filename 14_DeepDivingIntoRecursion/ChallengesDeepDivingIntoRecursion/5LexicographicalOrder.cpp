//Lexicographical Order

#include <bits/stdc++.h>
using namespace std;

void LexicographicalOrder_Nums(int n, int StartWith){
    //base case
    if(StartWith > n){
        return;
    }

    //recursive case
    cout << StartWith << " ";

    for(int i = 0; i <= 9; i++){
        int new_num = StartWith * 10 + i;
        LexicographicalOrder_Nums(n, new_num);
    }
}

int main(){
    int n;
    cin >> n;
    cout << "0 ";

    for(int i=1; i<=9; i++){
        LexicographicalOrder_Nums(n, i);
    }
    return 0;
}

// Take as input N, a number. Write a recursive function which prints counting from 0 to N in lexicographical order. In lexicographical (dictionary) order 10, 100 and 109 will be printed before 11.

// Input Format
// Enter a number N.

// Constraints
// None

// Output Format
// Display all the numbers upto N in a lexicographical order

// Sample Input
// 10
// Sample Output
// 0 1 10 2 3 4 5 6 7 8 9 
