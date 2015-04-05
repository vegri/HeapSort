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

	BinaryHeap heap(true);
	heap.insert(3);
	heap.insert(6);
	heap.insert(19);
	heap.insert(45);
	heap.print();
	std::cout << "root: " << heap.extractRoot() << endl;
	std::cout << "root: " << heap.extractRoot() << endl;
	std::cout << "root: " << heap.extractRoot() << endl;
	std::cout << "root: " << heap.extractRoot() << endl;
	return 0;
}
