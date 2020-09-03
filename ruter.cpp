#include<iostream>
#include<vector>

using namespace std;

int place_router(vector<int> buildings, int n) {
	vector<int> prefix_sum(n);
	prefix_sum[0] = buildings[0];
	int curr_sum = 0;
	for(int i=1; i<n; i++) {
		prefix_sum[i] = prefix_sum[i-1] + buildings[i];
		curr_sum += buildings[i]*i;
	}

	int min_sum = curr_sum;
	for(int i=1; i<n; i++) {
		int l_sum = prefix_sum[i-1];
		int r_sum = prefix_sum[n-1] - l_sum;
		curr_sum += l_sum - r_sum;
		if(curr_sum < min_sum)
			min_sum = curr_sum;
	}

	return min_sum;
}

int main() {


	int n;
	cin >> n;
	if(n < 1 || n > 50000)
		return -1;
	vector<int> buildings(n);

	for(int i=0; i<n; i++)
		cin >> buildings[i];

	int router_building = place_router(buildings, n);
	cout << router_building << endl;

	return 0;
}