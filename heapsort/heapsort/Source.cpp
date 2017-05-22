/**************************************
Heapsort
Running time: O(nlogn)
Space complexity: O(1) In-place sorting
***************************************/
#include <iostream>
#include <cstdlib>
#include "array.h"

using namespace std;

void max_heapify(int a[], int node,int num);
void build_max_heap(int a[],int num);
void heapsort(int a[], int num);

int main() {
	int a[MAX_ELEMENTS];
	int num;
	cout << "Enter Number of elements:";
	cin >> num;
	getarray(a, num);
	
	cout << "Original Array\n";
	printarray(a, num);

	heapsort(a, num);

	cout << "Sorted Array\n";
	printarray(a, num);

	return 0;
}

void max_heapify(int a[], int node,int num) {
	int left = (2 * node) + 1;			//Access left and right child linearly
	int right= (2 * node) + 2;
	int largest;
	if (left <= num-1 && a[left] > a[node])
		largest = left;
	else
		largest = node;
	if (right <= num-1 && a[right] > a[largest])
		largest = right;
	if (largest != node) {
		swap(a[largest], a[node]);
		max_heapify(a, largest, num-1);
	}
}

void build_max_heap(int a[], int num) {
	for (int i = num / 2; i >=0; i--)
		max_heapify(a, i, num);
}

void heapsort(int a[], int num) {
	build_max_heap(a, num);
	int heap_size = num;
	while(heap_size >=1) {
		swap(a[0], a[heap_size-1]);
		heap_size = heap_size - 1;
		max_heapify(a, 0, heap_size);
	}
}