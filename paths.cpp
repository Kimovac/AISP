//Program that inputs number n, followed by an n x x matrix.
//And outputs the number of paths from position the (0, 0)
//to position (n-1, n-1) by only moving down or right. 
//Alogrithm works by using dynamic programing. It does so
//by starting from the position (n-1, n-1) and calculating
//for each position the distance to the end by adding 
//distances to the end for the element beneath and to the
//right of current one until they reach the position (0, 0)

//Algorithm time complexity O(n^2). And space complexity
//is 0(n^2), which can be lowered to O(n) by saving the
//curent row and the one above it.


#include<iostream>
#include<vector>

using namespace std;

int number_of_paths(vector<vector<int>> matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for(int i=n-1; i>=0; i--) {
		for(int j=m-2; j>=0; j--) {
			int down, right;
			if(i != n-1 && j != m-1) {
				down = matrix[i+1][j];
				right = matrix[i][j+1];
			}
			else if(i == n-1) {
				down = 0;
				right = matrix[i][j+1];
			}
			else if(j == m-1) {
				down = matrix[i+1][j];
				right = 0;
			}
			else {
				down = 0;
				right = 0;
			}

			if(matrix[i][j])
				matrix[i][j] = down + right;

		}
	}

	return matrix[0][0];
}

int main() {

	vector<vector<int>> matrix {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1},
		{0, 1, 0, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	cout << number_of_paths(matrix) << "\n";

	return 0;
}