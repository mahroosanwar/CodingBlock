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
        cout<<ch;
        if(freq>1)
        cout<<freq;
    }
}
   
int main(){
    char a[1000];
    cin >> a;

    StringCompression(a);

    cout << endl;
    return 0;
}


// Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2ds.

// Input Format
// A single String S.

// Constraints
// A string of length between 1 to 1000

// Output Format
// The compressed String.

// Sample Input
// aaabbccds
// Sample Output
// a3b2c2ds
// Explanation
// In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice. But, 'd' and 's' occurred only once that's why we do not write their occurrence.
