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