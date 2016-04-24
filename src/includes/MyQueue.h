#ifndef _MYQUEUE_
#define _MYQUEUE_

#include <iostream>

// DECLARATION

template <class T> class MyQueue {
private:
	typedef struct queueLayer {
		queueLayer* next;
		queueLayer* prev;
		T data;
		queueLayer();
		queueLayer(const T d);
	} queueLayer;
	queueLayer* start;
	queueLayer* end;
	int len;
public:
	MyQueue();
	~MyQueue();
	bool enqueue(const T d);
	T dequeue();
	void flush();
	int getLength();
	bool isempty();
};




// IMPLEMENTATION

template <class T> MyQueue<T>::MyQueue() {
	start = NULL;
	end = NULL;
	len = 0;
}

template <class T> MyQueue<T>::~MyQueue() {
	flush();
}

template <class T> MyQueue<T>::queueLayer::queueLayer(){
	data = (T)NULL;
	next = NULL;
	prev = NULL;
}

template <class T> MyQueue<T>::queueLayer::queueLayer(const T d){
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T> bool MyQueue<T>::enqueue(const T d) {
	if (end == NULL) {
		start = new queueLayer(d);
		if (start == NULL) {
			return false;
		}
		end = start;
	} else {
		queueLayer* temp = new queueLayer(d);
		if (temp == NULL) {
			return false;
		}
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
	len++;
	return true;
}

template <class T> T MyQueue<T>::dequeue() {
	T ret;
	queueLayer* temp = end;
	if (temp == NULL) {
		return (T)NULL;
	}
	end = end->prev;
	ret = temp->data;
	delete temp;
	len--;
	return ret;
}

template <class T> int MyQueue<T>::getLength() {
	return len;
}

template <class T> bool MyQueue<T>::isempty() {
	return !(bool)len;
}

template <class T> void MyQueue<T>::flush() {
	// flush
	queueLayer* temp;
	while(end != NULL) {
		temp = end;
		end = end->prev;
		delete temp;
		//len--;
	}
	len = 0;
}


#endif

