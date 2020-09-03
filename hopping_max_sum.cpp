//Program that inputs number n, and then an array of length n.
//It prints out the maximum sum of elements that are picked up
//by hopping through the array from the first to the last
//element in the array. You can hop from the current element 
//to the next or one afther that. Alogrithm finds the
//maximum sum by calculating maxium sum up to the ith element.
//Maximum of ith element is calculated as maximum of the
//previous two elements i-1, i-2 plus ith element. 
//In exemple, for the array: [1, -2, -1, 2, -2, 2], 
//maximum hopping sum is 4. Max sum for every index in the 
//previos array is [1, -1, 0, 2, 0, 4]. We don't have to
//save sum for all the index just the current one and the
//previous two. And finnaly the max hopping sum for the
//whole array is stored in the current element which is 4.

//Algorithm is of time complexity O(n), and space 
//complexity O(1). It does so using dynamic programming.

#include <iostream>
#include <stdlib.h>
#include <vector>

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