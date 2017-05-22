/**********************************************************************
Bubblesort
Running time: O(n^2)
Spcae complexity: O(1) In-place sorting
This is a non optimized implementation of bubble sort.
It does not check whether the input array is already sorted or
whether the array is sorted before all n-1 passes have been completed.
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include "array.h"

using namespace std;

void bubblesort(int a[], int num);

int main() {
	int num, a[MAX_ELEMENTS];
	cout << "Enter number of elements:";
	cin >> num;
	getarray(a, num);

	cout << "Original array\n";
	printarray(a,num);

	bubblesort(a, num);

	cout << "Sorted array\n";
	printarray(a, num);

	return 0;
}

void bubblesort(int a[], int num) {
	for (int i = 0; i < num-1; i++) {
		for (int j = 0; j < num-1-i; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}

}