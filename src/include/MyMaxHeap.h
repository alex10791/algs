#ifndef _MYMAXHEAP_
#define _MYMAXHEAP_

#include <iostream>

// DECLARATION

template <class T> class MyMaxHeap {
private:
	T *data;
	T error_sig;
	unsigned int size;
	unsigned int next;
public:
	MyMaxHeap(unsigned int size, T error_signal);
	~MyMaxHeap();
	bool insert(const T d);
	void printHeap();
	void flush();
	T extract();
};




// IMPLEMENTATION

template <class T> MyMaxHeap<T>::MyMaxHeap(unsigned int size, T error_signal) {
	this->size = size;
	this->error_sig = error_signal;
	next = 0;
	data = new T[size];
}

template <class T> MyMaxHeap<T>::~MyMaxHeap() {
	size = 0;
	delete data;
}

template <class T> bool MyMaxHeap<T>::insert(const T d) {
	T temp;
	unsigned int idx = next;
	if (next >= size) {
		return false;
	}
	data[next] = d;
	while ((idx != 0) && (data[idx] > data[((idx+1)/2)-1])) {
		temp = data[((idx+1)/2)-1];
		data[((idx+1)/2)-1] = data[idx];
		data[idx] = temp;
		idx = ((idx+1)/2)-1;
	}
	next++;
	return true;
}

template <class T> void MyMaxHeap<T>::printHeap() {
	for (int i = 0; i < next; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

template <class T> T MyMaxHeap<T>::extract() {
	if (next == 0) {
		return error_sig;
	}
	T temp;
	
	unsigned int left_idx;
	unsigned int right_idx;

	T root = data[0];
	data[0] = data[next-1];
	next--;

	unsigned int i = 0;

	while (1) {
		left_idx = ((i+1)*2)-1;
		right_idx = (i+1)*2;

		if (left_idx >= next && right_idx >= next) {
			return root;
		}
		if (left_idx >= next && (data[i] >= data[right_idx])) {
			return root;
		}
		if (right_idx >= next && (data[i] >= data[left_idx])) {
			return root;
		}
		if ((data[i] >= data[left_idx]) && (data[i] >= data[right_idx])) {
			return root;
		} 
		if ((data[left_idx] >= data[i]) && (data[left_idx] >= data[right_idx])) {
			temp = data[i];
			data[i] = data[left_idx];
			data[left_idx] = temp;
			i = left_idx;
		} else {
			temp = data[i];
			data[i] = data[right_idx];
			data[right_idx] = temp;
			i = right_idx;
		}
	}


}

template <class T> void MyMaxHeap<T>::flush() {
	next = 0;
}

#endif

