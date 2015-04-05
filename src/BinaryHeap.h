/*
 * BinaryHeap.h
 *
 *  Created on: Apr 5, 2015
 *      Author: kunzejo
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <stddef.h>

class BinaryHeap {
public:
	BinaryHeap(bool isMaxHeap);
	virtual ~BinaryHeap();

	void insert(int i);
	int extractRoot();
	void print();

private:

	const bool isMaxHeap_;
	size_t bufferSize_;
	int* heap_;
	size_t length_;

	void downHeap();
	void upHeap();
	void resizeBuffer(size_t newLength);
	void swap(size_t a, size_t b);

	static size_t getLeftChildPosition(size_t parent);
	static size_t getParentPosition(size_t child);

};

#endif /* BINARYHEAP_H_ */
