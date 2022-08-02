// Remove Duplicates 

#include <iostream>
using namespace std;

void RemoveDuplicates(char a[]){
    for(int i=0; a[i] != '\0'; ){
        char ch = a[i];
        int freq = 0;
        while(a[i] == ch){
            freq++;
            if(freq==1){
                cout << ch;
            }
            i++;
        }
    }
}

int main(){
    char a[1000];
    cin >> a;

    RemoveDuplicates(a);

    cout << endl;
    return 0;
}

// Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

// Input Format
// String

// Constraints
// A string of length between 1 to 1000

// Output Format
// String

// Sample Input
// aabccba
// Sample Output
// abcba
// Explanation
// For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

// After removing all of the consecutive occurences, the Final ans will be : - "abcba".
