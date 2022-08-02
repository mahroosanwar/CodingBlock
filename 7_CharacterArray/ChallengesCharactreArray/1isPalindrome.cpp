#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char a[]){
    int len = strlen(a);
    int i = 0;
    while(i<len){
        if(a[i] != a[len-1]){
            return false;
        }
        i++, len--;
    }
    return true;
}

int main()
{
    char a[1000];
    cin >> a;

    if(isPalindrome(a)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    cout << endl;
    return 0;
}


// Take as input S, a string. Write a function that returns true if the string is a palindrome and false otherwise. Print the value returned.

// Input Format
// String

// Constraints
// String length between 1 to 1000 characters

// Output Format
// Boolean

// Sample Input
// abba
// Sample Output
// true
// Explanation
// A string is said to be palindrome if reverse of the string is same as string. For example, “abba” is palindrome as it's reverse is "abba", but “abbc” is not palindrome as it's reverse is "cbba".
