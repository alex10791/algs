
#include <iostream>
//#include <stdio>
//#include <stdlib>

#include "MyStack.h"
#include "MyQueue.h"
#include "MyLinkedList.h"
#include "MyBinTree.h"
#include "MyMaxHeap.h"
#include "MyRedBlackTree.h"


//using namespace std;

int main(int argc, char *argv[]) {	//
	
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
	
	std::cout << "MyRedBlackTree" << std::endl;
	MyRedBlackTree<int> rbtree = MyRedBlackTree<int>();
	std::cout << rbtree.insert(7) << std::endl;
	std::cout << rbtree.insert(6) << std::endl;
	std::cout << rbtree.insert(5) << std::endl;
	std::cout << rbtree.insert(4) << std::endl;
	std::cout << rbtree.insert(3) << std::endl;
	std::cout << rbtree.insert(2) << std::endl;
	std::cout << rbtree.insert(1) << std::endl;
	rbtree.printTree();

	//std:cout << rbtree.remove() << std::endl;

	std::cout << rbtree.removeItem(5) << std::endl;
	std::cout << rbtree.removeItem(5) << std::endl;
	rbtree.printTree();


	std::cout << "Searching 7: " << rbtree.searchItem(7) << std::endl;
	std::cout << "Searching 5: " << rbtree.searchItem(5) << std::endl;



	std::cout << "MyMaxHeap" << std::endl;
	MyMaxHeap<char> heap = MyMaxHeap<char>(10);
	std::cout << heap.insert('a', 1) << std::endl;
	std::cout << heap.insert('b', 5) << std::endl;
	std::cout << heap.insert('c', 3) << std::endl;
	std::cout << heap.insert('d', 10) << std::endl;
	std::cout << heap.insert('e', 7) << std::endl;
	std::cout << heap.insert('f', 12) << std::endl;
	std::cout << heap.insert('g', 4) << std::endl;
	std::cout << heap.insert('h', 5) << std::endl;
	std::cout << heap.insert('i', 20) << std::endl;

	std::cout << heap.insert('j', 15) << std::endl;
	std::cout << heap.insert('k', 40) << std::endl;
	std::cout << heap.insert('l', 50) << std::endl;
	heap.printHeap();

	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;

	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;

	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;

	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;
	std::cout << heap.extract() << std::endl;

	heap.printHeap();



	std::cout << "MyBinTree" << std::endl;
	MyBinTree<int> btree = MyBinTree<int>();

/*
	std::cout << "Inserting" << std::endl;
	std::cout << btree.insert(7) << std::endl;
	std::cout << btree.insert(1) << std::endl;
	std::cout << btree.insert(9) << std::endl;
	std::cout << btree.insert(0) << std::endl;
	std::cout << btree.insert(3) << std::endl;
	std::cout << btree.insert(8) << std::endl;
	std::cout << btree.insert(10) << std::endl;
	std::cout << btree.insert(2) << std::endl;
	std::cout << btree.insert(5) << std::endl;
	std::cout << btree.insert(4) << std::endl;
	std::cout << btree.insert(6) << std::endl;


	btree.traversePreOrder();
	std::cout << std::endl;
	btree.traverseInOrder();
	std::cout << std::endl;
	btree.traversePostOrder();
	std::cout << std::endl;

	return 0;


	std::cout << btree.insert(10) << std::endl;
	//std::cout << btree.insert(7) << std::endl;
	std::cout << btree.insert(20) << std::endl;

	std::cout << "Searching" << std::endl;
	std::cout << "5 : " << btree.search(10) << std::endl;

	std::cout << btree.remove(10) << std::endl;

	std::cout << "Searching" << std::endl;
	std::cout << "5 : " << btree.search(10) << std::endl;
	//std::cout << "6 : " << btree.search(7) << std::endl;
	std::cout << "7 : " << btree.search(20) << std::endl;
	
	return 0;
*/

	std::cout << "Inserting" << std::endl;
	std::cout << btree.insert(10) << std::endl;
	std::cout << btree.insert(7) << std::endl;
	std::cout << btree.insert(20) << std::endl;
	std::cout << btree.insert(8) << std::endl;
	std::cout << btree.insert(2) << std::endl;
	std::cout << btree.insert(15) << std::endl;
	std::cout << btree.insert(13) << std::endl;
	std::cout << btree.insert(17) << std::endl;

	std::cout << btree.insert(2) << std::endl;

	btree.traversePreOrder();
	std::cout << std::endl;
	btree.traverseInOrder();
	std::cout << std::endl;
	btree.traversePostOrder();
	std::cout << std::endl;

	std::cout << "Searching" << std::endl;
	std::cout << "5 : " << btree.search(2) << std::endl;
	std::cout << "6 : " << btree.search(7) << std::endl;
	std::cout << "7 : " << btree.search(8) << std::endl;
	std::cout << "1 : " << btree.search(10) << std::endl;
	std::cout << "5 : " << btree.search(13) << std::endl;
	std::cout << "6 : " << btree.search(15) << std::endl;
	std::cout << "7 : " << btree.search(17) << std::endl;
	std::cout << "1 : " << btree.search(20) << std::endl;

	std::cout << "1 : " << btree.search(1) << std::endl;


	
	std::cout << btree.remove(7) << std::endl;

	std::cout << "Searching" << std::endl;
	std::cout << "5 : " << btree.search(2) << std::endl;
	std::cout << "6 : " << btree.search(7) << std::endl;
	std::cout << "7 : " << btree.search(8) << std::endl;
	std::cout << "1 : " << btree.search(10) << std::endl;
	std::cout << "5 : " << btree.search(13) << std::endl;
	std::cout << "6 : " << btree.search(15) << std::endl;
	std::cout << "7 : " << btree.search(17) << std::endl;
	std::cout << "1 : " << btree.search(20) << std::endl;


	
	std::cout << btree.remove(10) << std::endl;

	std::cout << "Searching" << std::endl;
	std::cout << "5 : " << btree.search(2) << std::endl;
	std::cout << "6 : " << btree.search(7) << std::endl;
	std::cout << "7 : " << btree.search(8) << std::endl;
	std::cout << "1 : " << btree.search(10) << std::endl;
	std::cout << "5 : " << btree.search(13) << std::endl;
	std::cout << "6 : " << btree.search(15) << std::endl;
	std::cout << "7 : " << btree.search(17) << std::endl;
	std::cout << "1 : " << btree.search(20) << std::endl;


	btree.flush();


	
	std::cout << "MyStack" << std::endl;
	MyStack<int> stck = MyStack<int>();

	stck.flush();
	std::cout << "x" << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	
	std::cout << stck.push(1) << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.push(2) << " " << stck.getLength() << " " << stck.isempty() << std::endl;

	stck.flush();
	std::cout << "x" << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	
	std::cout << stck.push(3) << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.push(4) << " " << stck.getLength() << " " << stck.isempty() << std::endl;

	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	std::cout << stck.pop() << " " << stck.getLength() << " " << stck.isempty() << std::endl;
	

	std::cout << std::endl << "MyQueue" << std::endl;
	MyQueue<int> q = MyQueue<int>();

	q.flush();
	std::cout << "x" << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.enqueue(1) << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.enqueue(2) << " " << q.getLength() << " " << q.isempty() << std::endl;

	q.flush();
	std::cout << "x" << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.enqueue(3) << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.enqueue(4) << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.enqueue(1) << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.enqueue(2) << " " << q.getLength() << " " << q.isempty() << std::endl;

	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;
	std::cout << q.dequeue() << " " << q.getLength() << " " << q.isempty() << std::endl;



	std::cout << std::endl << "MyLinkedList" << std::endl;
	MyLinkedList<int> lst = MyLinkedList<int>();

	lst.flush();
	std::cout << "x" << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(1) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(2) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(3) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.add(1) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.add(2) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	lst.flush();
	std::cout << "x" << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.add(3) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.add(4) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.removeByIndex(20) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(1) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.add(1) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.add(2) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;
	std::cout << lst.removeByIndex(0) << " " << lst.getLength() << " " << lst.isempty() << std::endl;

	

	return 0;
}


//http://pastebin.com/kAmzHP5A

