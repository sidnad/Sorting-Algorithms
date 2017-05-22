/*****************************************************************
Quicksort
Running time: Average case: O(nlogn)  Worst case: O(n^2)
Space complexity: O(logn)
Worst case scenario occurs when the partition causes the division
of the array in n-2 and n partitions
*****************************************************************/
#include <iostream>
#include "array.h"

using namespace std;

void quicksort(int a[], int p, int r);
int partition(int a[],int p,int r);

int main() {
	int num;
	int a[MAX_ELEMENTS];

	cout << "Enter number of elements:";
	cin >> num;
	getarray(a, num);

	cout << "Original array\n";
	printarray(a, num);

	quicksort(a, 0, num-1);

	cout << "Sorted array\n";
	printarray(a, num);

	return 0;
}

void quicksort(int a[], int p, int r) {
	int q = 0;
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= x) {
			i = i + 1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;

	return(i+1);
}