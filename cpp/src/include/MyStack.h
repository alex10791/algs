#ifndef _MYSTACK_
#define _MYSTACK_

#include <iostream>

// DECLARATION

template <class T> class MyStack {
private:
	typedef struct stackLayer {
		stackLayer* next;
		T data;
		stackLayer();
		stackLayer(const T d);
	} stackLayer;
	stackLayer* top;
	int len;
public:
	MyStack();
	~MyStack();
	bool push(const T d);
	T pop();
	void flush();
	int getLength();
	bool isempty();
};





// IMPLEMENTATION

template <class T> MyStack<T>::MyStack() {
	top = NULL;
	len = 0;
}

template <class T> MyStack<T>::~MyStack() {
	flush();
}

template <class T> MyStack<T>::stackLayer::stackLayer() {
	data = (T)NULL;
	next = NULL;
}

template <class T> MyStack<T>::stackLayer::stackLayer(const T d) {
	data = d;
	next = NULL;
}

template <class T> bool MyStack<T>::push(const T d) {
	if (top == NULL){
		top = new stackLayer(d);
	} else {
		stackLayer* temp = new stackLayer();
		if (temp == NULL) {
			return false;				// Should return an ERROR
		}
		temp->next = top;
		top = temp;
		top->data = d;
	}
	len++;
	return true;
}

template <class T> T MyStack<T>::pop() {
	T ret;
	if (top == NULL) {
		return 0;
	} else {
		stackLayer* temp = top;
		top = top->next;
		ret = temp->data;
		delete temp;
		len--;
		return ret;
	}
}

template <class T> void MyStack<T>::flush() {
	stackLayer* temp;
	while(top != NULL){
		temp = top;
		top = top->next;
		delete temp;
		//len--;
	}
	len = 0;
}

template <class T> int MyStack<T>::getLength() {
	return len;
}

template <class T> bool MyStack<T>::isempty() {
	return !(bool)len;
}




#endif


