#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string>ans;
void DictionaryOrderLarger(string original, string str, int cnt)
{
	if (str[cnt] == '\0')
	{
		if (str > original) {
			ans.push_back(str);
		}
		return;
	}
	for (int i = cnt; str[i] != '\0'; i++)
	{
		swap(str[i], str[cnt]);
		DictionaryOrderLarger(original, str, cnt + 1);
		swap(str[i], str[cnt]);
	}
}
int main()
{
	string str;
	cin >> str;
	DictionaryOrderLarger(str, str, 0);
	// sort the output string
	sort(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << endl;
	}
	return 0;
}

// Take as input str, a string. Write a recursive function which prints all the words possible by rearranging the characters of this string which are in dictionary order larger than the given string.
// The output strings must be lexicographically sorted.

// Input Format
// Single line input containing a string

// Constraints
// Length of string <= 10

// Output Format
// Display all the words which are in dictionary order larger than the string entered in a new line each. The output strings must be sorted.

// Sample Input
// cab

// Sample Output
// cba
// Explanation
// The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only one of them is lexicographically greater than "cab". We only print "cba".
