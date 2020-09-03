#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longest_commong_substring(const string &s1, const string &s2) {
	int n = s1.length();
	int m = s2.length();
	vector<int> row1(m+1, 0);
	vector<int> row2(m+1);
	
	int index = 0;
	int max = 0;
	for(int i=1; i<n+1; i++) {
		row2[0] = 0;
		for(int j=1; j<m+1; j++) {
			if(s1[i-1] == s2[j-1])
				row2[j] = row1[j-1] + 1;
			else
				row2[j] = 0;

			if(row2[j] > max) {
				max = row2[j];
				index = j - max;
			}
		}
		row1 = row2;
	}

	return s2.substr(index, max);
}

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	cout << longest_commong_substring(s1, s2) << endl;

	return 0;
}