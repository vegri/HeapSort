//============================================================================
// Name        : Heapsort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main() {

	BinaryHeap<float> heap(true);
	heap.insert(3.);
	heap.insert(6.);
	heap.insert(19.);
	heap.insert(45.);
	heap.insert(4);
	heap.print();

	float* array=heap.getHeapSortedArray();
	for(int i=0; i<5; i++){
		cout << array[i] << " ";
	}
	return 0;
}
