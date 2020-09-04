//Program that inputs number k, followed by k sorted arrays.
//And outputs a sorted array which is a merger of all the 
//arrays. It does so by keeping a heap of k smallest elements.
//If an element is removed from the heap. A new element is
//inserted into it, that is from the same array that the
//removed element belonged to, if it exists. And so on until
//the heap is empty. Removed elements from the heap are stored
//in the final array which is the solution.

//Alogrithm is of time complexity O(k*n*logk), and space
//complexity O(k). Where n represents the average length
//of the sorted arrays.

#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> int_p;

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