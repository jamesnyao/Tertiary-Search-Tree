#include "Tri_Tree.h"

using namespace std;

// Default construction (values are undefined)
template <class T>
Tri_Tree<T>::Tri_Tree()
{
	left = nullptr;
	middle = nullptr;
	right = nullptr;
	flags = 0;
}

// Value constructor with one value
template <class T>
Tri_Tree<T>::Tri_Tree(const T &value) : Tri_Tree()
{
	value_a = value;
	flags = 1;
}

// Value constructor with two values
template <class T>
Tri_Tree<T>::Tri_Tree(const T &_value_a, const T &_value_b) : Tri_Tree()
{
	value_a = _value_a;
	value_b = _value_b;
	flags = 3;
}

// Copy constructor (makes deep copy)
template <class T>
Tri_Tree<T>::Tri_Tree(const Tri_Tree<T>& tree) : Tri_Tree()
{
	insert(tree);
}

// Finds if a value exists in this tree
template <class T>
bool Tri_Tree<T>::find(const T &value) const
{
	if (value == value_a) return true;
	if (value == value_b) return true;
	if ((value < value_a) && left)
		return left->find(value);
	if (((value > value_a) && (value < value_b)) && middle)
		return middle->find(value);
	if ((value > value_b) && right)
		return right->find(value);
	return false;
}

// Inserts a new value into the tree recursively
// Checks value in comparison to value_a and value_b, and places appropriately
template <class T>
bool Tri_Tree<T>::insert(const T &value)
{
	// if value repeats, deny the insert
	if ((value == value_a) || (value == value_b)) return false;
	
	// check for open spots in this node
	// value_a
	if (!(flags & 1)) {
		value_a = value;
		flags |= 1;
		return true;
	}
	// value_b
	if (!(flags & 2)) {
		value_b = value;
		flags |= 2;
		return true;
	}

	// if both values are full
	// left
	if (value < value_a) {
		if (!left) {
			left = new Tri_Tree<T>(value);
			return true;
		} left->insert(value); // inserts if left node exists
	}
	// right
	if (value > value_b) {
		if (!right) {
			right = new Tri_Tree<T>(value);
			return true;
		} right->insert(value); // inserts if right node exists
	}
	// middle
	if (!middle) {
		middle = new Tri_Tree<T>(value);
		return true;
	} middle->insert(value); // inserts if middle node exists
}

// Combine the values of a tree into this tree
template <class T>
bool Tri_Tree<T>::insert(Tri_Tree<T>* tree)
{
	if (checkIfRepeat(tree)) insertTreeHelper(tree);
	return false;
}

// Inserts every element in a tree into this tree
template <class T>
void Tri_Tree<T>::insertTreeHelper(Tri_Tree<T>* tree)
{
	if (tree->left) insertTreeHelper(tree->left);
	if (tree->middle) insertTreeHelper(tree->middle);
	if (tree->right) insertTreeHelper(tree->right);
	if (tree->flags & 1) insert(tree->value_a);
	if (tree->flags & 2) insert(tree->value_b);
}

// Returns true if no values in tree are equal to any values in this
template <class T>
bool Tri_Tree<T>::checkIfRepeat(Tri_Tree<T>* tree) const
{
	if ((tree->flags & 1) && find(tree->value_a)) return false;
	if ((tree->flags & 2) && find(tree->value_b)) return false;
	if (tree->left) return checkIfRepeat(tree->left);
	if (tree->middle) return checkIfRepeat(tree->middle);
	if (tree->right) return checkIfRepeat(tree->right);
	return true;
}

// Removes a value from the tree
template <class T>
bool Tri_Tree<T>::remove(const T& value)
{
	// check if value is in this node, remove it if so
	if ((flags & 1) && (value == value_a)) {
		if (flags & 2) { flag = 0; return true; }
		if (!left && !middle && !right) delete this;
		repopulate(1);
		return true;
	}
	if ((flags & 2) && (value == value_b)) {
		if (flags & 1) { flag = 0; return true; }
		if (!left && !middle && !right) delete this;
		repopulate(2);
		return true;
	}

	// value is not in this node, check below
	if (flags == 3) {
		if ((value < value_a) && left)
			return left->remove(value);
		if (((value > value_a) && (value < value_b)) && middle)
			return middle->remove(value);
		if ((value > value_b) && right)
			return right->remove(value);
	} if (flags == 2) {
		if (value < value_b)
			return left->remove(value) || middle->remove(value);
		return right->remove(value);
	} if (flags == 1) {
		if (value > value_a)
			return middle->remove(value) || right->remove(value);
		return left->remove(value);
	}

	// nothing is removed
	return false;
}

// Repopulates after a node is removed
template <class T>
void Tri_Tree<T>::repopulate(unsigned char remove_flag)
{
	if (left) {
		value = left->value;
		left->repopulate();
	} else {
		value = right->value;
		right->repopulate();
	}
}

// Prints out tree in order from left to right
template <class T>
void Tri_Tree<T>::displayHelper() const
{
	if (left) left->displayHelper();
	cout << value << " ";
	if (right) right->displayHelper();
}

// Prints out this tree
template <class T>
void Tri_Tree<T>::display() const
{
	displayHelper();
	cout << endl;
}

// Returns the pointer to the left Tri_Tree
template <class T>
Tri_Tree<T>* Tri_Tree<T>::getLeft() const
{
	return left;
}

// Returns the pointer to the right Tri_Tree
template <class T>
Tri_Tree<T>* Tri_Tree<T>::getRight() const
{
	return right;
}

// Sets the value of the current tree to value
template <class T>
T Tri_Tree<T>::getContent() const
{
	return value;
}

// Sets the left pointer to tree
template <class T>
void Tri_Tree<T>::setLeft(Tri_Tree<T>* tree)
{
	if (left) delete left;
	left = tree;
}

// Sets the right pointer to tree
template <class T>
void Tri_Tree<T>::setRight(Tri_Tree<T>* tree)
{
	if (right) delete right;
	right = tree;
}

// Sets the value of the current tree to value
template <class T>
void Tri_Tree<T>::setContent(const T &value)
{
	value = value;
}

// Default destructor
template <class T>
Tri_Tree<T>::~Tri_Tree<T>()
{
	if (left) delete left;
	if (right) delete right;
}

// Add possible types
template class Tri_Tree<int>;
