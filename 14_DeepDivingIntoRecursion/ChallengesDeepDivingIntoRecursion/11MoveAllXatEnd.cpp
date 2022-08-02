//move all x to end
#include <bits/stdc++.h>
using namespace std;

// Function to move all 'x' in the end
void moveAtEnd(string s, int i){
	//base case
    if (s[i] == '\0')
		return;

	//current character is not 'x'
	if (s[i] != 'x')
		cout << s[i];

	// recursive case
	moveAtEnd(s, i + 1);

	//current character is 'x'
	if (s[i] == 'x')
		cout << s[i];

	return;
}


int main()
{
	string s;
    cin >> s;

	moveAtEnd(s, 0);

	return 0;
}


// Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end.
// E.g. for “abexexdexed” return “abeedeedxxx”.
// Print the value returned

// Input Format
// Single line input containing a string

// Constraints
// Length of string <= 1000

// Output Format
// Single line displaying the string with all x's moved at the end

// Sample Input
// axbxc
// Sample Output
// abcxx
// Explanation
// All x's are moved to the end of string while the order of remaining characters remain the same.
