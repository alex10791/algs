#ifndef _MYLINKEDLIST_
#define _MYLINKEDLIST_

template <class T>
class MyLinkedList {
	private:
		typedef struct listLayer {
			listLayer* next;
			T data;
			listLayer();
			listLayer(const T d);
		} listLayer;
		listLayer* head;
		listLayer* tail;
		int len;
	public:
		MyLinkedList();
		~MyLinkedList();
		bool add(const T d);
		T getByIndex(const int idx);
		bool remove(const T d);
		bool removeByIndex(const int idx);
		void flush();
		int getLength();
		bool isempty();
};

template <class T> MyLinkedList<T>::MyLinkedList() {
	head = NULL;
	tail = NULL;
	len = 0;
}

template <class T> MyLinkedList<T>::~MyLinkedList() {
	flush();
}

template <class T> MyLinkedList<T>::listLayer::listLayer() {
	data = (T)NULL;
	next = NULL;
}

template <class T> MyLinkedList<T>::listLayer::listLayer(const T d) {
	data = d;
	next = NULL;
}

template <class T> bool MyLinkedList<T>::add(const T d) {
	listLayer* temp = new listLayer(d);
	if (temp == NULL) {
		return false;
	}
	if (tail != NULL) {
		tail->next = temp;
	}
	tail = temp;
	if (head == NULL) {
		head = temp;
	}
	len++;
	return true;
}

template <class T> T MyLinkedList<T>::getByIndex(const int idx) {
	listLayer* listPtr = head;
	for (int i = 0; i < idx; ++i) {
		if (listPtr == NULL) {
			return (T)NULL;
		}
		listPtr = listPtr->next;
	}
	if (listPtr == NULL) {
		return (T)NULL;
	}
	return listPtr->data;
}

// THIS METHOD SHOULD PROBABLY BE AVOIDED
template <class T> bool MyLinkedList<T>::remove(const T d) {
	listLayer* listPtr = head;
	listLayer* listPtrPrev = NULL;
	while (listPtr != NULL) {
		if (listPtr->data == d) {		// THIS IS NOT PROPER EQUALITY CHECK!!!
			if (listPtr == tail) {
				tail = listPtrPrev;
			}
			if (listPtrPrev != NULL) {
				listPtrPrev->next = listPtr->next;
				delete listPtr;
			} else {
				head = listPtr->next;
				delete listPtr;
			}
			len--;
			return true;
		}
		listPtrPrev = listPtr;
		listPtr = listPtr->next;
	}
	return false;
}

template <class T> bool MyLinkedList<T>::removeByIndex(const int idx) {
	listLayer* listPtr = head;
	listLayer* listPtrPrev = NULL;
	for (int i = 0; i < idx; ++i) {
		if (listPtr == NULL) {
			return false;
		}
		listPtr = listPtr->next;
	}

	if (listPtr == NULL) {
		return false;
	}

	// REMOVE PROCESS
	if (listPtr == tail) {
		tail = listPtrPrev;
	}
	if (listPtrPrev != NULL) {
		listPtrPrev->next = listPtr->next;
		delete listPtr;
	} else {
		head = listPtr->next;
		delete listPtr;
	}
	len--;
	return true;
}

template <class T> void MyLinkedList<T>::flush() {
	listLayer* listPtr = head;
	listLayer* listPtrTemp = NULL;
	while (listPtr != NULL) {
		listPtrTemp = listPtr->next;
		delete listPtr;
		listPtr = NULL;
	}
	head = NULL;
	tail = NULL;
	len = 0;
}

template <class T> int MyLinkedList<T>::getLength() {
	return len;
}

template <class T> bool MyLinkedList<T>::isempty() {
	return !(bool)len;
}

#endif

