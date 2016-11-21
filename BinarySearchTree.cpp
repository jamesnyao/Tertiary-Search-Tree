#include "BinarySearchTree.h"

using namespace std;

// Default construction (contents are undefined)
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	left = nullptr;
	right = nullptr;
}

// Value constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree(const T &value)
{
	content = value;
	left = nullptr;
	right = nullptr;
}

// Inserts a new value into the tree recursively
// Checks value's place in comparison to content, and places appropriately
template <class T>
bool BinarySearchTree<T>::insert(const T &value)
{
	// Left
	if (value < content) {
		if (!left) {
			left = new BinarySearchTree<T>(value);
			return true;
		} left->insert(value); // If left node exists
	}
	// Right
	if (value > content) {
		if (!right) {
			right = new BinarySearchTree<T>(value);
			return true;
		} right->insert(value); // If right node exists
	}
	return false;
}

// Returns true if no values in tree are equal to any values in this
template <class T>
bool BinarySearchTree<T>::checkIfRepeat(BinarySearchTree<T>* tree) const
{
	if (find(tree->content)) return false;
	if (left && find(tree->left->content))
		return checkIfRepeat(tree->left);
	if (right && find(tree->right->content))
		return checkIfRepeat(tree->right);
	return true;
}

// Inserts every element in a tree into this tree
template <class T>
void BinarySearchTree<T>::insertTreeHelper(BinarySearchTree<T>* tree)
{
	if (tree->left) insertTreeHelper(tree->left);
	if (tree->right) insertTreeHelper(tree->right);
	insert(tree->content);
}

// Combine the contents of a tree into this tree
template <class T>
bool BinarySearchTree<T>::insert(BinarySearchTree<T>* tree)
{
	if (checkIfRepeat(tree)) insertTreeHelper(tree);
	return false;
}

// Removes a value from the tree
template <class T>
bool BinarySearchTree<T>::remove(const T& value)
{
	if (content == value) {
		if (!left && !right) delete this;
		repopulate();
		return true;
	}
	if ((value < content) && left) left->remove(value);
	if ((value > content) && right) right->remove(value);
	return false;
}

// Repopulates after a node is removed
template <class T>
void BinarySearchTree<T>::repopulate()
{
	if (left) {
		content = left->content;
		left->repopulate();
	} else {
		content = right->content;
		right->repopulate();
	}
}

// Finds if a value exists in this tree
template <class T>
bool BinarySearchTree<T>::find(const T &value) const
{
	if (content == value) return true;
	if ((value < content) && left) return left->find(value);
	if ((value > content) && right) return right->find(value);
	return false;
}

// Prints out tree in order from left to right
template <class T>
void BinarySearchTree<T>::displayHelper() const
{
	if (left) left->displayHelper();
	cout << content << " ";
	if (right) right->displayHelper();
}

// Prints out this tree
template <class T>
void BinarySearchTree<T>::display() const
{
	displayHelper();
	cout << endl;
}

// Returns the pointer to the left BinarySearchTree
template <class T>
BinarySearchTree<T>* BinarySearchTree<T>::getLeft() const
{
	return left;
}

// Returns the pointer to the right BinarySearchTree
template <class T>
BinarySearchTree<T>* BinarySearchTree<T>::getRight() const
{
	return right;
}

// Sets the content of the current tree to value
template <class T>
T BinarySearchTree<T>::getContent() const
{
	return content;
}

// Sets the left pointer to tree
template <class T>
void BinarySearchTree<T>::setLeft(BinarySearchTree<T>* tree)
{
	if (left) delete left;
	left = tree;
}

// Sets the right pointer to tree
template <class T>
void BinarySearchTree<T>::setRight(BinarySearchTree<T>* tree)
{
	if (right) delete right;
	right = tree;
}

// Sets the content of the current tree to value
template <class T>
void BinarySearchTree<T>::setContent(const T &value)
{
	content = value;
}

// Default destructor
template <class T>
BinarySearchTree<T>::~BinarySearchTree<T>()
{
	if (left) delete left;
	if (right) delete right;
}

// Add possible types
template class BinarySearchTree<int>;
