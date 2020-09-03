#include<iostream>
#include<vector>

using namespace std;

//function that finds number of paths from [0][0] to [n-1][m-1]
//with blockades while only moving left and right
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