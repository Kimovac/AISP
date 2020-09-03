#include<iostream>
#include<algorithm>
#include<functional>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> int_p;

//function that sorts k sorted arrays into a single sorted array of lenght n
void sort_arrays(vector<int> &arr, vector<vector<int>> arrays) {
	int k = arrays.size();

	priority_queue<int_p, vector<int_p>, greater<int_p>> heap;
	for(int i=0; i<k; i++) {
		heap.push(make_pair(arrays[i][0], i));
		arrays[i].erase(arrays[i].begin());
	}


	int arr_i = 0;
	while(!heap.empty()) {
		int_p min = heap.top();	heap.pop();
		if(!arrays[min.second].empty()) {
			heap.push(make_pair(arrays[min.second][0], min.second));
			arrays[min.second].erase(arrays[min.second].begin());
		}

		arr[arr_i++] = min.first;
	}
}

int main() {

	int k;
	cin >> k;
	vector<vector<int>> arrays(k);
	int n = 0;
	for(int i=0; i<k; i++) {
		int k_num;
		cin >> k_num;
		arrays[i].resize(k_num);
		for(int j=0; j<k_num; j++)
			cin >> arrays[i][j];

		n += k_num;
	}

	vector<int> sorted_array(n);
	sort_arrays(sorted_array, arrays);
	for(auto i: sorted_array)
		cout << i << " ";

	cout << "\n";

	return 0;
}