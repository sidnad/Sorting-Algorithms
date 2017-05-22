/*****************************
Mergesort
Running time: O(nlogn)
Space complexity: O(n)
Divide and conquer algorithm
*****************************/
#include <iostream>
#include "array.h"

using namespace std;

#define INFINITY 99999


void mergesort(int a[], int p, int r);
void merge(int a[], int p, int q, int r);

int main() {

	int num;
	int a[MAX_ELEMENTS] = {};
	cout << "Enter number of elements:";
	cin >> num;
	getarray(a, num);

	cout << "Original array\n";
	printarray(a, num);
	
	mergesort(a, 0, num-1);

	cout << "Sorted array\n";
	printarray(a, num);

	return 0;
}

void merge(int a[], int p, int q,int r) {
	int i, j,k;
	int n1 = q - p+1;
	int n2 = r - q;
	int left[20] = {}, right[20] = {};
	for (i = 0; i < n1; i++)
		left[i] = a[p + i];
	for (j = 0; j < n2; j++)
		right[j] = a[q+1+j];
	left[n1] = INFINITY;
	right[n2] = INFINITY;

	i = 0;
	j = 0;
	k = p;
	while (k<=r)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
}

void mergesort(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(a, p, q);
		mergesort(a, q + 1, r);
		merge(a, p, q, r);
	}
}