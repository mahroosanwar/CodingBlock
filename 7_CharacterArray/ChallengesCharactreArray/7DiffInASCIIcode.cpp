//Take as input S, a string. Write a program that inserts between each pair of 
//characters the difference between their ascii codes and print the ans.

#include <iostream>
#include <cstring>
using namespace std;

void DiffInASCIIcode(char a[]){
    int len = strlen(a);
    int e = len-1;
    for(int i=1; a[i] != '\0'; i++){
        int x = a[i] - a[i-1];
        cout << a[i-1] << x;
    }
    cout << a[e] << endl;
}
int main(){
    char a[2000];
    cin>> a;

    DiffInASCIIcode(a);
    
    cout << endl;
    return 0;
}

// Take as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes and print the ans.

// Input Format
// String

// Constraints
// Length of String should be between 2 to 1000.

// Output Format
// String

// Sample Input
// acb
// Sample Output
// a2c-1b
// Explanation
// For the sample case, the Ascii code of a=97 and c=99 ,the difference between c and a is 2.Similarly ,the Ascii code of b=98 and c=99 and their difference is -1. So the ans is a2c-1b.
