//============================================================================
// Name        : parking-lot.cpp
// Author      : Arturo Santiago-Rivera
// Version     :
// Copyright   : Your copyright notice
// Description : 2D Vector simulating a parking lot.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> carParking(vector<vector<int>> loc, int car) {
	for (int i = 0; i < loc.size(); i++) {
		for (int j = 0; j < loc[i].size(); j++) {
			if (loc[j][i] == 0) {
				loc[j][i] = car;
				cout << "Car " << car << " is in row " << j + 1 << " space " << i + 1 << "." << endl;
				return loc;
			}
		}
	}
	cout << "Car " << car << " not parked. Lot is Full!" << endl;
	return loc;
}

vector<vector<int>> carRemoval(vector<vector<int>> loc, int car) {
	for (int i = 0; i < loc.size(); i++) {
		for (int j = 0; j < loc[i].size(); j++) {
			if (loc[j][i] == car) {
				loc[j][i] = 0;
				cout << "Car " << car << " removed from parking." << endl;
				return loc;
			}
		}
	}
	cout << "Car " << car << " not found on parking." << endl;
	return loc;
}

int main() {
	int no_of_rows;
	int no_of_cols;
	int cars_to_park;
	int userInput;
	int initial_value = 0;
	int car = 0;

	vector<vector<int>> lot;

	cout << "\nEnter the amount of rows in the parking lot: ";
	cin >> userInput;

	no_of_rows = userInput;
	no_of_cols = no_of_rows;

	lot.resize(no_of_rows, vector<int>(no_of_cols, initial_value));

	cout << "\nEnter the number of cars to park: ";
	cin >> userInput;
	cout << endl;

	cars_to_park = userInput;

	while (cars_to_park != 0) {
		car++;
		lot = carParking(lot, car);
		cars_to_park--;
	}

	// Displaying the 2D vector
	cout << "\nLot view:" << endl;
	for (unsigned i = 0; i < lot.size(); i++) {
		for (unsigned j = 0; j < lot[i].size(); j++) {
			cout << lot[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
