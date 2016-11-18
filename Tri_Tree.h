#ifndef _TriTree_H_
#define _TriTree_H_

#include <iostream>
#include <string>

template <class T>
class TriTree
{
	private:

		// Values stored in this tree
		T value_a;
		T value_b;
		// Flags for valid value
		// (2 bits: bit 0 is value_a bit 1 is value_b)
		unsigned char flags;

		// Pointer to left subtree
		Tri_Tree<T>* left;
		
		// Pointer to middle subtree
		Tri_Tree<T>* middle;

		// Pointer to right subtree
		Tri_Tree<T>* right;

	public:

		// Default constructor
		Tri_Tree();

		// Value constructor using a value
		Tri_Tree(const T &value);
		
		// Value constructor with two values
		Tri_Tree(const T &_value_a, const T &_value_b);
		
		// Copy constructor (makes deep copy)
		Tri_Tree(const Tri_Tree<T>& tree);
		
		// Returns true if a value exists in this tree
		bool find(const T& value) const;

		// Inserts a value into this tree
		bool insert(const T& value);

		// Inserts a tree of values into this tree
		bool insert(Tri_Tree<T>* tree);

		// Removes the location where a value is located and repopulates the empty spot
		bool remove(const T& value);

		// Prints out the values of this tree in order
		void display() const;

		// Getters for left, middle, right, value_a, and value_b
		Tri_Tree<T>* get_left() const;
		Tri_Tree<T>* get_middle() const;
		Tri_Tree<T>* get_right() const;
		T getvalue_a() const;
		T getvalue_b() const;

		// Setters for left, middle, right, value_a, and value_b
		void set_left(Tri_Tree<T>* tree);
		void set_middle(Tri_Tree<T>* tree);
		void set_right(Tri_Tree<T>* tree);
		void setvalue_a(const T& value);
		void setvalue_b(const T& value);
		
		// Default destructor
		~Tri_Tree();

	// Helper functions
	private:

		// Helper to insert a tree into this tree
		void insertTreeHelper(Tri_Tree<T>* tree);

		// Checks if any value in a tree is present in this tree
		bool checkIfRepeat(Tri_Tree<T>* tree) const;

		// Moves tree values to fill a removed value
		void repopulate();

		// Helper to print out values of this tree
		void displayHelper() const;
};

#endif
