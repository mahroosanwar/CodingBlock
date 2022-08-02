//String Compression
#include <iostream>
using namespace std;

void StringCompression(char a[]){
     for(int i=0; a[i] != '\0';){
        char ch = a[i];
        // find freq of ch 
        int freq = 0;
        while(a[i]==ch){
            freq++;
            i++;
        }
        cout<<ch<<freq;
    }
}
   
int main(){
    char a[1000];
    cin >> a;

    StringCompression(a);

    cout << endl;
    return 0;
}


// Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

// Input Format
// A single String S

// Constraints
// 1 < = length of String < = 1000

// Output Format
// The compressed String.

// Sample Input
// aaabbccds
// Sample Output
// a3b2c2d1s1
// Explanation
// In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.
