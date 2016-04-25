#ifndef _MYREDBLACKTREE_
#define _MYREDBLACKTREE_

#include <iostream>

// DECLARATION

template <class T> class MyRedBlackTree {
private:
	enum Color { Red, Black };
	typedef struct treeNode {
		treeNode *left;
		treeNode *right;
		treeNode *parent;
		treeNode *nilNode;
		Color color;
		T data;
		treeNode();
		treeNode(const T d, treeNode *nn);
	} treeNode;
	treeNode *root;
	treeNode *nilNode;
	void insertRecursion(treeNode *z);
	bool searchRecursion(const T d, treeNode *node);
	void printTreeRecursion(treeNode *node);
	void leftRotate(treeNode *x);
	void rightRotate(treeNode *x);
	//bool removeRecursion(const T d, treeNode *node, treeNode **parentNodeSidePtr);
	//void *removeRecursionRightSlide(treeNode *node, treeNode **parentNodeSidePtr);
	//void *removeRecursionLeftSlide(treeNode *node, treeNode **parentNodeSidePtr);
	void flushRecursion(treeNode **node);
public:
	MyRedBlackTree();
	~MyRedBlackTree();
	bool insert(const T d);
	bool search(const T d);
	void printTree();
	//bool remove(const T d);
	void flush();
};




// IMPLEMENTATION

template <class T> MyRedBlackTree<T>::MyRedBlackTree() {
 	nilNode = new treeNode();
	root = nilNode;
}

template <class T> MyRedBlackTree<T>::~MyRedBlackTree() {
	flush();
}

template <class T> MyRedBlackTree<T>::treeNode::treeNode() {
	left = this;
	right = this;
	color = Black;
}

template <class T> MyRedBlackTree<T>::treeNode::treeNode(const T d, treeNode *nn) {	//
	this->nilNode = nn;
	data = d;
	left = nn;
	right = nn;
	color = Black;
}

template <class T> bool MyRedBlackTree<T>::insert(const T d) {
	treeNode *z = new treeNode(d, nilNode);
	treeNode *y = nilNode;
	treeNode *x = root;
	while (x != nilNode) {
		y = x;
		if (z->data < x->data) {
			x = x->left;
		} else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == nilNode) {
		root = z;
	} else if (z->data < y->data) {
		y->left = z;
	} else {
		y->right = z;
	}
	z->left = nilNode;
	z->right = nilNode;
	z->color = Red;
	insertRecursion(z);
	return true;
}

template <class T> void MyRedBlackTree<T>::insertRecursion(treeNode *z) {
	treeNode *y;
	while (z->parent->color == Red) {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if (y->color == Red) {
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = Black;
				z->parent->parent->color = Red;
				rightRotate(z->parent->parent);
			}
		} else {
			y = z->parent->parent->left;
			if (y->color == Red) {
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = Black;
				z->parent->parent->color = Red;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = Black;
}

template <class T> void MyRedBlackTree<T>::leftRotate(treeNode *x) {
	//std::cout << "leftRot" << std::endl;
	treeNode *y = x->right;
	x->right = y->left;
	if (y->left != nilNode) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nilNode) {
		root = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

template <class T> void MyRedBlackTree<T>::rightRotate(treeNode *x) {
	//std::cout << "rightRot" << std::endl;
	treeNode *y = x->left;
	x->left = y->right;
	if (y->right != nilNode) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nilNode) {
		root = y;
	} else if (x == x->parent->right) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}


template <class T> bool MyRedBlackTree<T>::search(const T d) {
	if (root == NULL) {
		return false;
	} else {
		return searchRecursion(d, root);		
	}
	return false;
}

template <class T> bool MyRedBlackTree<T>::searchRecursion(const T d, treeNode *node) {
	/*
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
	*/
	return false;
}



template <class T> void MyRedBlackTree<T>::printTree() {
	//std::cout << "nilNode: " << nilNode << std::endl;
	printTreeRecursion(root);
	std::cout << std::endl;
}

template <class T> void MyRedBlackTree<T>::printTreeRecursion(treeNode *node) {
	if (node == nilNode) {
		return;
	}
	char* col;
	if (node->color == Red) {
		col = "Red";
	} else {
		col = "Black";
	}
	std::cout << "node: " << node << " data: " << node->data << " color: " << col << " left: " << node->left << " right: " << node->right << std::endl;
	//std::cout << "LEFT\n";
	printTreeRecursion(node->left);
	//std::cout << "RIGHT\n";
	printTreeRecursion(node->right);
}



template <class T> void MyRedBlackTree<T>::flush() {
	/*
	if (root == NULL) {
		return;
	} 
	flushRecursion(&root);
	*/
}

template <class T> void MyRedBlackTree<T>::flushRecursion(treeNode **node) {
	if (*node == NULL) {
		return;
	} 
	flushRecursion(&((*node)->left));
	flushRecursion(&((*node)->right));
	delete (*node);
	(*node) = NULL;
}

#endif

