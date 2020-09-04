//Program that inputs number of buidings n, followed by
//number of residents of each bulding. Program prints out
//in which building  to place the router so that the 
//total wiring length is minimal. Wiring lenght from a 
//building in which the router is placed to an other bulding
//is calculated by multiplying number of wires that go to
//that bulding by the distance between them. Numer of wires
//between the bulding is the number of residents in the non
//router bulding. Distance between the buidings is of value 1.
//Total sum for the router bulding is sum wiring lenght to all
//other buidlings. The algorithm can be solved in linear time.
//In exemple if we have and array: [2, 4, 1, 5, 2], where
//[a0, a1, a2, a3, a4] are number of residents. The sum for 
//the first bulding is 1*a1 + 2*a2 + 3*a3 + 4*a4. And for the
//second one is        1*a0 + 1*a2 + 2*a3 + 3*a4. 
//And if we subtrac these two sums we get -a0 + a1 + a2+ a3 + a4
//And as we can see the difference between two bulding is a
//prefix sum from i to n subtracted with prefix sum from 0 to i.
//We just need to find the sum for the first building and then
//we can calculate the next one by adding the difference between
//them by taking the prefix sums and subtracting then.

//Algorithm is of time complexity O(n), and space complexity O(n).
//Space comlexity if O(n) because we store the prefix sum for each
//of the buildings.


#include <iostream>
#include <vector>

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