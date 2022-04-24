#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

void printAllPermutationsFast(string s, string l)
{
	if (s.length() < 1) {
		cout << l + s << endl;
	}
	unordered_set<char> uset;
	for (int i = 0; i < s.length(); i++) {
		if (uset.find(s[i]) != uset.end()) {
			continue;
		}
		else {
			uset.insert(s[i]);
		}
		string temp = "";
		if (i < s.length() - 1) {
			temp = s.substr(0, i) + s.substr(i + 1);
		}
		else {
			temp = s.substr(0, i);
		}
		printAllPermutationsFast(temp, l + s[i]);
	}
}

int main()
{
	string s = "ACBC";
	sort(s.begin(), s.end());
	printAllPermutationsFast(s, "");
	return 0;
}
