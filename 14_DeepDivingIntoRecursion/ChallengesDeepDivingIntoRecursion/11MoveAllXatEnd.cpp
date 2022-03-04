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
