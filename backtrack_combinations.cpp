//Program inputs numbes n and m. And proceeds to to print out
//all combinations of length n from a selection of numbers
//in range [1, m] in lexicographic order.

//Combinations are generated by generating variations, 
//which are backtracked if they don't meet the
//requierments to be a combinations. Those requierments
//are that no numbers in range [0, k-1] are equal or greater
//to the kth number in a variation/combination. They cant be
//grater so that we don't get repeating combinations.


#include <iostream>
#include <vector>

using namespace std;


void print_combination(const vector<int> &arr) {
	for(auto x : arr)
		cout << x << " ";
	cout << "\n";
}

bool test_combination(const vector<int> &arr, int k) {
	for(int i=0; i<k; i++) {
		if(arr[i] == arr[k])
			return false;

		if(arr[i] > arr[k])
			return false;
	}

	return true;
}

void print_combinations(vector<int> &arr, const int m, int k) {
	int n = arr.size();
	if(k == n) {
		print_combination(arr);
		return;
	}

	for(int i=1; i<=m; i++) {
		arr[k] = i;
		if(test_combination(arr, k))
			print_combinations(arr, m, k+1);
	}
	return;
}

void print_combinations(vector<int> &arr, const int m) {
	for(int i=1; i<=m; i++) {
		arr[0] = i;
		print_combinations(arr, m, 1);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	print_combinations(arr, m);

	return 0;
}