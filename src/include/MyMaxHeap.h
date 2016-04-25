#ifndef _MYMAXHEAP_
#define _MYMAXHEAP_

#include <iostream>

// DECLARATION

template <class T> class MyMaxHeap {
private:
	typedef struct heapNode {
		unsigned int priority;
		T data;
		heapNode(const T d, unsigned int p);
		heapNode();
	} heapNode;
	heapNode *heap;
	//T error_sig;
	unsigned int size;
	unsigned int next;
public:
	MyMaxHeap(unsigned int size);
	~MyMaxHeap();
	bool insert(const T d, unsigned int p);
	void printHeap();
	void flush();
	T extract();
};




// IMPLEMENTATION

template <class T> MyMaxHeap<T>::MyMaxHeap(unsigned int size) {
	this->size = size;
	//this->error_sig = error_signal;
	next = 0;
	heap = new heapNode[size];
}

template <class T> MyMaxHeap<T>::~MyMaxHeap() {
	size = 0;
	delete heap;
}

template <class T> MyMaxHeap<T>::heapNode::heapNode() {
	priority = 0;
}

template <class T> MyMaxHeap<T>::heapNode::heapNode(const T d, unsigned int p) {
	data = d;
	priority = p;
}

template <class T> bool MyMaxHeap<T>::insert(const T d, unsigned int p) {
	heapNode temp;
	unsigned int idx = next;
	if (next >= size) {
		return false;
	}
	heap[next].data = d;
	heap[next].priority = p;
	while ((idx != 0) && (heap[idx].priority > heap[((idx+1)/2)-1].priority)) {
		temp = heap[((idx+1)/2)-1];
		heap[((idx+1)/2)-1] = heap[idx];
		heap[idx] = temp;
		idx = ((idx+1)/2)-1;
	}
	next++;
	return true;
}

template <class T> void MyMaxHeap<T>::printHeap() {
	for (unsigned int i = 0; i < next; ++i) {
		std::cout << "data: " << heap[i].data << " priority: " << heap[i].priority << "\t";
	}
	std::cout << std::endl;
}

template <class T> T MyMaxHeap<T>::extract() {
	if (next == 0) {
		return (unsigned int)-1;
	}
	heapNode temp;
	
	unsigned int left_idx;
	unsigned int right_idx;

	heapNode root = heap[0];
	heap[0] = heap[next-1];
	next--;

	unsigned int i = 0;

	while (1) {
		left_idx = ((i+1)*2)-1;
		right_idx = (i+1)*2;

		if (left_idx >= next && right_idx >= next) {
			return root.data;
		}
		if (left_idx >= next && (heap[i].priority >= heap[right_idx].priority)) {
			return root.data;
		}
		if (right_idx >= next && (heap[i].priority >= heap[left_idx].priority)) {
			return root.data;
		}
		if ((heap[i].priority >= heap[left_idx].priority) && (heap[i].priority >= heap[right_idx].priority)) {
			return root.data;
		} 
		if ((heap[left_idx].priority >= heap[i].priority) && (heap[left_idx].priority >= heap[right_idx].priority)) {
			temp = heap[i];
			heap[i] = heap[left_idx];
			heap[left_idx] = temp;
			i = left_idx;
		} else {
			temp = heap[i];
			heap[i] = heap[right_idx];
			heap[right_idx] = temp;
			i = right_idx;
		}
	}


}

template <class T> void MyMaxHeap<T>::flush() {
	next = 0;
}

#endif

