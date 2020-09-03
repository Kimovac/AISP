#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return (a.first == b.first) ? (a.second > b.second) : (a.first > b.first);
}

int subjectivly_warm_num(vector<pair<int, int>> &arr) {
	if(arr.size() == 0)
		return 0;
	
	sort(arr.begin(), arr.end(), compare);
	int sub_warm = 1;
	pair<int, int> max = arr[0];
	for(int i=1; i<arr.size(); i++) {
		if(arr[i].second > max.second) {
			max = arr[i];
			sub_warm++;
		}
	}
	
	return sub_warm;
}

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	cout << subjectivly_warm_num(arr) << endl;

	return 0;
}