#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

long int hopping_max_sum(const vector<long int> &arr) {
	int n = arr.size();
	if(n == 1)
		return arr[0];
	if(n == 2)
		return arr[0] + arr[1];

	long int dp[3];
	dp[0] = arr[0]; dp[1] = arr[1] + arr[0];
	for(int i=2; i<n; i++) {
		dp[2] = arr[i] + max(dp[0], dp[1]);
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	
	return dp[2];
}

int main() {

	int n;
	cin >> n;
	if(n < 1 || n > 1000000)
		return -1;

	vector<long int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(abs(arr[i]) > 1000000000)
			return -1;
	}

	cout << hopping_max_sum(arr) << endl;

	return 0;
}