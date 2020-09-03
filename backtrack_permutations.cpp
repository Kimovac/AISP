#include<iostream>
#include<vector>

using namespace std;


bool check_permutation(const vector<int> &arr, const int &k) {
	for(int i=1; i<=k; i++) {
		if(arr[i-1] == arr[k])
			return false;
	}

	return true;
}

void print_permutation(const vector<int> &arr) {
	for(auto x : arr)
		cout << x << " ";
	cout << "\n";
}

void print_permutations(vector<int> &arr, int k) {
	int n = arr.size();
	if(k == n) {
		print_permutation(arr);
		return;
	}

	for(int i=1; i<=n; i++) {
		arr[k] = i;
		if(check_permutation(arr, k))
			print_permutations(arr, k+1);
	}
	return;
}

void print_permutations(vector<int> &arr) {
	int n = arr.size();
	for(int i=1; i<=n; i++) {
		arr[0] = i;
		print_permutations(arr, 1);
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	print_permutations(arr);

	return 0;
}