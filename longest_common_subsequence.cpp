//Program that finds the longest comong subsequence between two strigns
//It does so by using dynamic programing.

//Time compexity of the algorithm is O(n*m), and
//space complexity is O(n*m). Where n and m are the
//lenghts of the strings.

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string longest_commong_subsequence(const string &s1, const string &s2) {

	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int subsequnece_len = dp[n][m];

	string s;
	int i = n;
	int j = m;
	while(subsequnece_len > 0) {
		char ci = s1[i-1];
		char cj = s2[j-1];
		if(ci == cj) {
			s +=ci ;
			subsequnece_len--;
			i--;
			j--;
		}
		else {
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}
	}

	reverse(s.begin(), s.end());
	return s;

}

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	cout << longest_commong_subsequence(s1, s2) << endl;

	return 0;
}