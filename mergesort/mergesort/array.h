#include<iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H
#define MAX_ELEMENTS 50

int getarray(int a[],int num) {
	if (num > MAX_ELEMENTS) {
		cout << "Max limit exceeded\n";
		return 0;
	}
	else if (num < 0) {
		cout << "Number of elements cannot be negative\n";
		return 0;
	}

	cout << "Enter elements:";
	for (int i = 0; i < num; i++)
		cin >> a[i];
}

void printarray(int a[], int num) {
	for (int i = 0; i < num; i++)
		cout << a[i] << " ";
	cout << endl;
}

#endif



