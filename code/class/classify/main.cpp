#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	cout << "Please enter three numbers: ";
	cin >> x >> y >> z;

	// if equal print equal
	if (x == y && y == z) {
		cout << "Equal" << endl;
	}

	// if ascending print ascending
	else if (x <= y && y <= z) {
		cout << "Ascending" << endl;
	}

	// if descending print descending 
	else if (x >= y && y >= z) {
	cout << "Descending" << endl;
	}

	else {
		cout << "None" << endl;
	}
}
