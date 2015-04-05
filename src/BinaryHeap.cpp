/*
 * BinaryHeap.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: kunzejo
 */

#include "BinaryHeap.h"
#include <math.h>
#include <string.h>
#include <iostream>

BinaryHeap::BinaryHeap(bool isMaxHeap) :
		isMaxHeap_(isMaxHeap), bufferSize_(1), heap_(new int[bufferSize_]), length_(
				0) {
}

BinaryHeap::~BinaryHeap() {
}

void BinaryHeap::insert(int i) {
	if (bufferSize_ == length_) {
		resizeBuffer(2 * length_);
	}
	heap_[length_] = i;
	length_++;
	upHeap();
}

int BinaryHeap::extractRoot() {
	int root = heap_[0];
	swap(0, length_ - 1);
	length_--;
	downHeap();
	return root;
}

void BinaryHeap::downHeap() {
	size_t currentElement = 0;
	size_t childposition;
	if(length_==0){
		return;
	}

	while (currentElement != length_ - 1) {
		childposition = getLeftChildPosition(currentElement);
		for (unsigned int i = 0; i != 2; i++) {
			if (childposition >= length_ - 1) {
				goto stopWhile;
			}
			if ((heap_[currentElement] < heap_[childposition]) == isMaxHeap_) {
				swap(currentElement, childposition);
				currentElement = childposition;
				break;
			} else {
				childposition++;
				continue;
			}
		}
	}
	stopWhile:{}
}

void BinaryHeap::upHeap() {
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

void BinaryHeap::resizeBuffer(size_t newLength) {
	int* newBuffer = new int[newLength];
	memcpy(newBuffer, heap_, length_);
	delete[] heap_;
	heap_ = newBuffer;
}

size_t BinaryHeap::getLeftChildPosition(size_t parent) {
	return 2 * parent + 1;
}

size_t BinaryHeap::getParentPosition(size_t child) {
	return floor((child - 1) / 2);
}

void BinaryHeap::swap(size_t a, size_t b) {
	int dummy = heap_[a];
	heap_[a] = heap_[b];
	heap_[b] = dummy;
}

void BinaryHeap::print() {
	for (size_t i = 0; i < length_; i++) {
		std::cout << heap_[i] << " ";
	}
	std::cout << std::endl;
}
