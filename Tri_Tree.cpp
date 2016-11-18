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
	if (check_if_repeat(tree)) insert_tree_helper(tree);
	return false;
}

// Inserts every element in a tree into this tree
template <class T>
void Tri_Tree<T>::insert_tree_helper(Tri_Tree<T>* tree)
{
	if (tree->left) insert_tree_helper(tree->left);
	if (tree->middle) insert_tree_helper(tree->middle);
	if (tree->right) insert_tree_helper(tree->right);
	if (tree->flags & 1) insert(tree->value_a);
	if (tree->flags & 2) insert(tree->value_b);
}

// Returns true if no values in tree are equal to any values in this
template <class T>
bool Tri_Tree<T>::check_if_repeat(Tri_Tree<T>* tree) const
{
	if ((tree->flags & 1) && find(tree->value_a)) return false;
	if ((tree->flags & 2) && find(tree->value_b)) return false;
	if (tree->left) return check_if_repeat(tree->left);
	if (tree->middle) return check_if_repeat(tree->middle);
	if (tree->right) return check_if_repeat(tree->right);
	return true;
}

// Removes a value from the tree
template <class T>
bool Tri_Tree<T>::remove(const T& value)
{
	// check if value is in this node, remove it if so
	// value_a
	if ((flags & 1) && (value == value_a)) {
		if (flags & 2) { flags = 0; return true; }
		if (!left && !middle && !right) delete this;
		repopulate(1);
		return true;
	}
	// value_b
	if ((flags & 2) && (value == value_b)) {
		if (flags & 1) { flags = 0; return true; }
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

// NEED WORK
// Repopulates after a node is removed
template <class T>
void Tri_Tree<T>::repopulate(unsigned char remove_flag)
{
	/*
	if (left) {
		value = left->value;
		left->repopulate();
	} else {
		value = right->value;
		right->repopulate();
	}
	*/
}

// Prints out this tree
template <class T>
void Tri_Tree<T>::display() const
{
	display_helper();
	cout << endl;
}

// Prints out tree in order from left to right
template <class T>
void Tri_Tree<T>::display_helper() const
{
	if (left) left->display_helper();
	if (flags & 1) cout << value_a << ' ';
	if (middle) middle->display_helper();
	if (flags & 2) cout << value_b << ' ';
	if (right) right->display_helper();
}

// Returns the pointer to the left Tri_Tree
template <class T>
Tri_Tree<T>* Tri_Tree<T>::get_left() const
{
	return left;
}

// Returns the pointer to the middle Tri_Tree
template <class T>
Tri_Tree<T>* Tri_Tree<T>::get_middle() const
{
	return middle;
}

// Returns the pointer to the right Tri_Tree
template <class T>
Tri_Tree<T>* Tri_Tree<T>::get_right() const
{
	return right;
}

// Gets the first value in this tree (value_a)
template <class T>
T Tri_Tree<T>::get_value_a() const
{
	return value_a;
}

// Gets the second value in this tree (value_b)
template <class T>
T Tri_Tree<T>::get_value_b() const
{
	return value_b;
}

// Sets the left pointer to tree
template <class T>
void Tri_Tree<T>::set_left(Tri_Tree<T>* tree)
{
	if (left) delete left;
	left = tree;
}

// Sets the middle pointer to tree
template <class T>
void Tri_Tree<T>::set_middle(Tri_Tree<T>* tree)
{
	if (middle) delete middle;
	middle = tree;
}

// Sets the right pointer to tree
template <class T>
void Tri_Tree<T>::set_right(Tri_Tree<T>* tree)
{
	if (right) delete right;
	right = tree;
}

// Sets the values of the current tree to _value_a and _value_b
template <class T>
void Tri_Tree<T>::set_values(const T& _value_a, const T& _value_b)
{
	value_a = _value_a;
	value_b = _value_b;
	flags = 3;
}

// Sets value_a of the current tree to value
template <class T>
void Tri_Tree<T>::set_value_a(const T& value)
{
	value_a = value;
	flags |= 1;
}

// Sets value_b of the current tree to value
template <class T>
void Tri_Tree<T>::set_value_b(const T& value)
{
	value_b = value;
	flags |= 2;
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
