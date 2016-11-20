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
	void insertFixup(treeNode *z);
	void printTreeRecursion(treeNode *node);
	void leftRotate(treeNode *x);
	void rightRotate(treeNode *x);
	void transplant(treeNode *u, treeNode *v);
	void removeFixup(treeNode *node);
	void *treeMax(treeNode *node);
	void *treeMin(treeNode *node);
	void remove(treeNode *z);
	void *search(const T d);
	void flushRecursion(treeNode **node);
public:
	MyRedBlackTree();
	~MyRedBlackTree();
	bool insert(const T d);
	bool searchItem(const T d);
	void printTree();
	bool removeItem(const T d);
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
	insertFixup(z);
	return true;
}

template <class T> void MyRedBlackTree<T>::insertFixup(treeNode *z) {
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


template <class T> bool MyRedBlackTree<T>::searchItem(const T d) {
	if (search(d) == NULL) {
		return false;
	}
	return true;
}

template <class T> void *MyRedBlackTree<T>::search(const T d) {
	treeNode *node = root;
	while (node != nilNode) {
		if (node->data > d) {
			node = node->left;
		} else if (node->data < d) {
			node = node->right;
		} else {
			return node;
		}
	}
	return NULL;
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
		col = (char*)"Red";
	} else {
		col = (char*)"Black";
	}
	std::cout << "node: " << node << " data: " << node->data << " color: " << col << " left: " << node->left << " right: " << node->right << std::endl;
	//std::cout << "LEFT\n";
	printTreeRecursion(node->left);
	//std::cout << "RIGHT\n";
	printTreeRecursion(node->right);
}

template <class T> bool MyRedBlackTree<T>::removeItem(const T d) {
	treeNode *item = (treeNode *)search(d);
	if (item == NULL) {
		return false;
	}
	remove(item);
	return true;
}


template <class T> void MyRedBlackTree<T>::remove(treeNode *z) {
	treeNode *x = NULL;
	treeNode *y = z;
	Color yinitcol = y->color;
	if (z->left == nilNode) {
		x = z->right;
		transplant(z, z->right);
	} else if (z->right == nilNode) {
		x = z->left;
		transplant(z, z->left);
	} else {
		y = (treeNode *)treeMin(z->right);
		yinitcol = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		} else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		x->left->parent = y;
		y->color = z->color;
	}
	if (yinitcol == Black) {
		removeFixup(x);
	}
	delete z;
}

template <class T> void MyRedBlackTree<T>::removeFixup(treeNode *x) {
	treeNode *w;
	while (x != root && x->color == Black) {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == Red) {
				w->color = Black;
				x->parent->color = Red;
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == Black && w->right->color == Black) {
				w->color = Red;
				x = x->parent;
			} else {
				if (w->right->color == Black) {
					w->left->color = Black;
					w->color = Red;
					rightRotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				w->right->color = Black;
				leftRotate(x->parent);
				x = root;
			}
		} else {
			w = x->parent->left;
			if (w->color == Red) {
				w->color = Black;
				x->parent->color = Red;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == Black && w->left->color == Black) {
				w->color = Red;
				x = x->parent;
			} else {
				if (w->left->color == Black) {
					w->right->color = Black;
					w->color = Red;
					leftRotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				w->left->color = Black;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = Black;
}

template <class T> void MyRedBlackTree<T>::transplant(treeNode *u, treeNode *v) {
	if (u->parent == nilNode) {
		root = v;
	} else if (u == u->parent->left) {
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

template <class T> void *MyRedBlackTree<T>::treeMax(treeNode *node) {
	while (node->right != nilNode) {
		node = node->right;
	}
	return node;
}

template <class T> void *MyRedBlackTree<T>::treeMin(treeNode *node) {
	while (node->left != nilNode) {
		node = node->left;
	}
	return node;
}


template <class T> void MyRedBlackTree<T>::flush() {
	if (root == nilNode) {
		return;
	} 
	flushRecursion(&root);
}

template <class T> void MyRedBlackTree<T>::flushRecursion(treeNode **node) {
	if (*node == nilNode) {
		return;
	} 
	flushRecursion(&((*node)->left));
	flushRecursion(&((*node)->right));
	delete (*node);
	(*node) = nilNode;
}

#endif

