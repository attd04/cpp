# -----------------------------------TASK 2----------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//find largest element of array
   // find sum of elements up to the last positive element
   // compress the array by removing from it all elements whose absolute value is in the interval [a,b]
   // fill the free places in the end with 0

	int size;

	cout << "How many elements in your array?: ";
	cin >> size;

	vector<int> v(size);

	cout << "Input your array: ";
	for (int i = 0; i < size; i++)
		cin >> v[i];

	int big = v[0];
	int sum = 0;

	// finding largest element
	for (int i = 1; i < size; i++) {

		if (v[i] > big) {
			big = v[i];
		}
	}

	int p = -1;

	// sum
	for (int k = 0; k < size; k++)
		sum += v[k];

	// finding last element
	int last_element = v.back();

	for (int i = 0; i < size; i++) {
		if (v[i] > 0) {
			if (p != -1) {
				break;
			}
			p = i;
		}
		sum += v[i];
	}
	int iv1, iv2;
	vector<int> new_v;

	// part c, enter interval
	cout << "\nEnter an interval [a, b]: ";
	cin >> iv1 >> iv2;

	// put elements outside of interval into new array
	for (int i = 0; i < size; i++) {
		if (abs(v[i]) < iv1 || abs(v[i]) > iv2) {
			new_v.push_back(v[i]);
		}
	}

	int zeros = v.size() - new_v.size();

	for (int i = 0; i < zeros; i++) {
		new_v.push_back(0);
	}



	cout << "\nA) The biggest element is: " << big << endl;
	cout << "B) The sum of the elements up to the last positive = " << sum << endl;
	cout << "C) The compressed array: ";
	for (int i = 0; i < new_v.size(); i++) {
		cout << new_v[i] << " ";
	}
		

}
