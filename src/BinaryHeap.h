/*
 * BinaryHeap.h
 *
 *  Created on: Apr 5, 2015
 *      Author: kunzejo
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <stddef.h>
#include <math.h>
#include <string.h>
#include <iostream>

template<class T>
class BinaryHeap {
public:
	BinaryHeap(bool isMaxHeap) :
			isMaxHeap_(isMaxHeap), bufferSize_(1), heap_(new T[bufferSize_]), length_(
					0) {
	}
	~BinaryHeap() {
		delete[] heap_;
	}

	void insert(T i) {
		if (bufferSize_ == length_) {
			resizeBuffer(2 * length_);
		}
		heap_[length_] = i;
		length_++;
		upHeap();
	}

	T extractRoot() {
		T root = heap_[0];
		swap(0, length_ - 1);
		length_--;
		downHeap();
		return root;
	}

	void print() {
		for (size_t i = 0; i < length_; i++) {
			std::cout << heap_[i] << " ";
		}
		std::cout << std::endl;
	}

	T* getHeapSortedArray(){
		T* array = new T [length_];
		size_t counter=0;
		while(length_!=0){
			array[counter++]=extractRoot();
		}
		return array;
	}

private:

	const bool isMaxHeap_;
	size_t bufferSize_;
	T* heap_;
	size_t length_;

	void downHeap() {
		size_t currentElement = 0;
		size_t childposition;
		if (length_ == 0) {
			return;
		}
		while (currentElement != length_ - 1) {
			childposition = getLeftChildPosition(currentElement);
			for (unsigned int i = 0; i != 2; i++) {
				if (childposition >= length_ - 1) {
					goto stopWhile;
				}
				if ((heap_[currentElement] < heap_[childposition])
						== isMaxHeap_) {
					swap(currentElement, childposition);
					currentElement = childposition;
					break;
				} else {
					childposition++;
					continue;
				}
			}
		}
		stopWhile: {
		}
	}

	void upHeap() {
		size_t currentElement = length_ - 1;
		size_t parentposition;
		while (currentElement != 0) {
			parentposition = getParentPosition(currentElement);
			if ((heap_[currentElement] > heap_[parentposition]) == isMaxHeap_) {
				swap(currentElement, parentposition);
				currentElement = parentposition;
			} else
				break;
		}
	}

	void resizeBuffer(size_t newLength) {
		T* newBuffer = new T[newLength];
		memcpy(newBuffer, heap_, length_*sizeof(T));
		delete[] heap_;
		heap_ = newBuffer;

		newBuffer = new T[newLength];
		memcpy(newBuffer, heap_, length_*sizeof(T));
		delete[] heap_;
		heap_ = newBuffer;
	}

	void swap(size_t a, size_t b) {
		T dummy = heap_[a];
		heap_[a] = heap_[b];
		heap_[b] = dummy;
	}

	static size_t getLeftChildPosition(size_t parent) {
		return 2 * parent + 1;
	}
	static size_t getParentPosition(size_t child) {
		return floor((child - 1) / 2);
	}

};

#endif /* BINARYHEAP_H_ */
