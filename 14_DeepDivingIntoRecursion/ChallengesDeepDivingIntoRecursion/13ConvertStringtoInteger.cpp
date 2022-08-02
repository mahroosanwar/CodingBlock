//Convert String to Integer

#include <iostream>
using namespace std;

void Str_to_Int(string str, int i){
    //base case

    if(str[i] == '\0'){
        return;
    }

    // recursive case
    int digit = str[i] - '0';
    cout << digit;

    Str_to_Int(str, i+1);

}
int main(){
    string s;
    cin >> s;

    Str_to_Int(s, 0);

    return 0;
}


// Take as input str, a number in form of a string. Write a recursive function to convert the number in string form to number in integer form. E.g. for “1234” return 1234. Print the value returned.

// Input Format
// Enter a number in form of a String

// Constraints
// 1 <= Length of String <= 10

// Output Format
// Print the number after converting it into integer

// Sample Input
// 1234
// Sample Output
// 1234
// Explanation
// Convert the string to int. Do not use any inbuilt functions.
