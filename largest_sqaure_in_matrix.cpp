#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
} Point;

vector<Point> largest_square_in_matrix(const vector<vector<int>> &matrix) {
	vector<int> r0(matrix[0].size()+1, 0);
	vector<int> r1(matrix[0].size()+1);

	int largest_square_size = 0;
	Point bottom_right_position = Point();
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix[0].size(); j++) {
			if(matrix[i][j] == 1) {
				r1[j+1] = 1 + min({r1[j], r0[j+1], r0[j]});
				if(r1[j+1] > largest_square_size) {
					largest_square_size = r1[j+1];
					bottom_right_position = Point(i, j);

				}
			}
			else
				r1[j+1] = 0;

		}

		r0 = r1;
	}

	vector<Point> coordinates(4);
	//top left
	coordinates[0].x = bottom_right_position.x - largest_square_size + 1;
	coordinates[0].y = bottom_right_position.y - largest_square_size + 1;
	//top rigt
	coordinates[1].x = bottom_right_position.x - largest_square_size + 1;
	coordinates[1].y = bottom_right_position.y;
	//bottom left
	coordinates[2].x = bottom_right_position.x;
	coordinates[2].y = bottom_right_position.y - largest_square_size + 1;
	//bottom right
	coordinates[3].x = bottom_right_position.x;
	coordinates[3].y = bottom_right_position.y;

	return coordinates;
}

int main() {

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int> (n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> matrix[i][j];

	vector<Point> coordinates = largest_square_in_matrix(matrix);
	for(auto p : coordinates) {
		cout << "(" << p.x << ", " << p.y << ")\n";
	}

	return 0;
}