//Set Example - Unique Permutations

#include <iostream>
#include <set>
#include <string>
using namespace std;

void UniquePermute(char *in, int i, set <string> &s){
    //base case
    if(in[i] == '\0'){
        // cout << in << endl;
        
        //insted of print in[], -- we make a string t and initialize with array in[]
        //that is the current output and which will show on screen
        string t(in);

        //now push this string object inside the set
        //the string t that was initially output is not now output it will inside the set
        //that will maintain only unique string

        s.insert(t);
    }

    //recursive case
    for(int j=i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        UniquePermute(in, i+1, s);
        
        //Backtracking --> to restore the original array
        swap(in[i], in[j]);
    }
}

int main(){
    char in[100];
    cin >> in;
    set<string> s;

    UniquePermute(in, 0, s);

    //loop over the set
    //this set only store the unique string
    for(auto str:s){
        cout << str << endl;
    }
    return 0;
}

// Take as input str, a string. Write a recursive function which returns all the words possible by rearranging the characters of this string which are in dictionary order smaller than the given string. The output strings must be lexicographically sorted.

// Input Format
// Single line input containing a string

// Constraints
// Length of string <= 25

// Output Format
// Display all the words which are in dictionary order smaller than the string entered in a new line each. The output strings must be sorted.

// Sample Input
// cab
// Sample Output
// abc
// acb
// bac
// bca
// Explanation
// The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only four of them are lexicographically less than "cab". We print them in lexicographical order.
