#ifndef _MYBINTREE_
#define _MYBINTREE_

#include <iostream>

// DECLARATION

template <class T> class MyBinTree {
private:
	typedef struct treeNode {
		treeNode *left;
		treeNode *right;
		T data;
		treeNode(const T d);
	} treeNode;
	treeNode *root;
	bool insertRecursion(const T d, treeNode *node);
	bool searchRecursion(const T d, treeNode *node);
	bool removeRecursion(const T d, treeNode *node, treeNode **parentNodeSidePtr);
	void *removeRecursionRightSlide(treeNode *node, treeNode **parentNodeSidePtr);
	void *removeRecursionLeftSlide(treeNode *node, treeNode **parentNodeSidePtr);
	void traversePreOrderRecursion(treeNode *node);
	void traverseInOrderRecursion(treeNode *node);
	void traversePostOrderRecursion(treeNode *node);
	void flushRecursion(treeNode *node);
public:
	MyBinTree();
	~MyBinTree();
	bool insert(const T d);
	bool search(const T d);
	bool remove(const T d);
	void traversePreOrder();
	void traverseInOrder();
	void traversePostOrder();
	void flush();
};




// IMPLEMENTATION

template <class T> MyBinTree<T>::MyBinTree() {
	root = NULL;
}

template <class T> MyBinTree<T>::~MyBinTree() {
	flush();
}

template <class T> MyBinTree<T>::treeNode::treeNode(const T d) {
	data = d;
	left = NULL;
	right = NULL;
}

template <class T> bool MyBinTree<T>::insert(const T d) {
	if (root == NULL) {
		root = new treeNode(d);
	} else {
		return insertRecursion(d, root);		
	}
	return true;
}

template <class T> bool MyBinTree<T>::insertRecursion(const T d, treeNode *node) {
	if (d == node->data) {
		return false;
	}
	if (d > node->data) {
		if (node->right == NULL) {
			node->right = new treeNode(d);
		} else {
			return insertRecursion(d, node->right);
		}
	} else {
		if (node->left == NULL) {
			node->left = new treeNode(d);
		} else {
			return insertRecursion(d, node->left);
		}
	}
	return true;
}


template <class T> bool MyBinTree<T>::search(const T d) {
	if (root == NULL) {
		return false;
	} else {
		return searchRecursion(d, root);		
	}
	return false;
}

template <class T> bool MyBinTree<T>::searchRecursion(const T d, treeNode *node) {
	if (node->data == d) {
		std::cout << d << "\t";
		if (node->left == NULL) {
			std::cout << "Left\t:\tNULL\t";
		} else {
			std::cout << "Left\t:\t" << node->left->data << "\t";
		}
		if (node->right == NULL) {
			std::cout << "Right\t:\tNULL\t";
		} else {
			std::cout << "Right\t:\t" << node->right->data << "\t";
		}
		std::cout << std::endl;
		return true;
	}
	if (d > node->data) {
		if (node->right == NULL) {
			return false;
		} else {
			return searchRecursion(d, node->right);
		}
	} else {
		if (node->left == NULL) {
			return false;
		} else {
			return searchRecursion(d, node->left);
		}
	}
	return false;
}


template <class T> void MyBinTree<T>::traversePreOrder() {
	if (root == NULL) {
		return;
	} 
	return traversePreOrderRecursion(root);
}

template <class T> void MyBinTree<T>::traversePreOrderRecursion(treeNode *node) {
	if (node == NULL) {
		return;
	} 
	std::cout << node->data << "\t";
	traversePreOrderRecursion(node->left);
	traversePreOrderRecursion(node->right);
}


template <class T> void MyBinTree<T>::traverseInOrder() {
	if (root == NULL) {
		return;
	} 
	return traverseInOrderRecursion(root);
}

template <class T> void MyBinTree<T>::traverseInOrderRecursion(treeNode *node) {
	if (node == NULL) {
		return;
	} 
	traverseInOrderRecursion(node->left);
	std::cout << node->data << "\t";
	traverseInOrderRecursion(node->right);
}


template <class T> void MyBinTree<T>::traversePostOrder() {
	if (root == NULL) {
		return;
	} 
	return traversePostOrderRecursion(root);
}

template <class T> void MyBinTree<T>::traversePostOrderRecursion(treeNode *node) {
	if (node == NULL) {
		return;
	} 
	traversePostOrderRecursion(node->left);
	traversePostOrderRecursion(node->right);
	std::cout << node->data << "\t";
}


template <class T> bool MyBinTree<T>::remove(const T d) {
	if (root == NULL) {
		return false;
	} 
	return removeRecursion(d, root, &root);
}

template <class T> bool MyBinTree<T>::removeRecursion(const T d, treeNode *node, treeNode **parentNodeSidePtr) {
	if (node->data == d) {
		if (node->left == NULL && node->right == NULL) {
			delete node;
			*parentNodeSidePtr = NULL;
		} else if (node->left == NULL) {
			*parentNodeSidePtr = node->right;
			delete node;
			node = NULL;
		} else if (node->right == NULL) {
			*parentNodeSidePtr = node->left;
			delete node;
			node = NULL;
		} else {
			*parentNodeSidePtr = (treeNode *)removeRecursionRightSlide(node->left, &(node->left));
			(*parentNodeSidePtr)->left = node->left;
			(*parentNodeSidePtr)->right = node->right;
			delete node;
		}
		return true;
	}
	if (d > node->data) {
		if (node->right == NULL) {
			return false;
		} else {
			return removeRecursion(d, node->right, &(node->left));
		}
	} else {
		if (node->left == NULL) {
			return false;
		} else {
			return removeRecursion(d, node->left, &(node->left));
		}
	}
	return false;
}

template <class T> void *MyBinTree<T>::removeRecursionRightSlide(treeNode *node, treeNode **parentNodeSidePtr) {
	if (node->right == NULL) {
		if (node->left == NULL) {
			*parentNodeSidePtr = NULL;
			return (void *)node;
		} else {
			*parentNodeSidePtr = node->left;
			return (void *)node;
		} 
	} else {
		return (treeNode *)removeRecursionRightSlide(node->right, &(node->right));
	}
}

template <class T> void *MyBinTree<T>::removeRecursionLeftSlide(treeNode *node, treeNode **parentNodeSidePtr) {
	if (node->left == NULL) {
		if (node->right == NULL) {
			*parentNodeSidePtr = NULL;
			return (void *)node;
		} else {
			*parentNodeSidePtr = node->right;
			return (void *)node;
		} 
	} else {
		return (treeNode *)removeRecursionRightSlide(node->left, &(node->left));
	}
}


template <class T> void MyBinTree<T>::flush() {
	if (root == NULL) {
		return;
	} 
	return flushRecursion(root);
}

template <class T> void MyBinTree<T>::flushRecursion(treeNode *node) {
	if (node == NULL) {
		return;
	} 
	std::cout << "left" << std::endl;
	flushRecursion(node->left);
	std::cout << "right" << std::endl;
	flushRecursion(node->right);
	delete node;
}

#endif

