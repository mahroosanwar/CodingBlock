// recursion-codesOfString.cpp
#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void possibleCodes(string str, int i, string out) {
	if (str[i] == '\0') {
		//base Case
		ans.push_back(out);
		return;
	}
	// select only one digit
	out.push_back(str[i] - '0' - 1 + 'a');
	possibleCodes(str, i + 1, out);
	out.pop_back();

	// consider 2 digits
	if (str[i + 1] != '\0') {
		int num = str[i] - '0';
		num = num * 10 + str[i + 1] - '0';
		if (num <= 26) {
			out.push_back(num - 1 + 'a');
			possibleCodes(str, i + 2, out);
			out.pop_back();
		}
	}
}
int main() {
	string str;
	cin >> str;
	possibleCodes(str, 0, "");
	cout << "[";
	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[ans.size() - 1] << "]"<<endl;
	return 0;
}


// Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

// Input Format
// Enter a number

// Constraints
// None

// Output Format
// Display all the possible codes

// Sample Input
// 1125
// Sample Output
// [aabe, aay, ale, kbe, ky]
