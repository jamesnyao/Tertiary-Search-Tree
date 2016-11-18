#ifndef _Tri_Tree_H_
#define _Tri_Tree_H_

#include <iostream>
#include <string>

template <class T>
class Tri_Tree
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
		T get_value_a() const;
		T get_value_b() const;

		// Setters for left, middle, right, value_a, and value_b
		void set_left(Tri_Tree<T>* tree);
		void set_middle(Tri_Tree<T>* tree);
		void set_right(Tri_Tree<T>* tree);
		void set_values(const T& _value_a, const T& _value_b);
		void set_value_a(const T& value);
		void set_value_b(const T& value);
		
		// Default destructor
		~Tri_Tree();

	// Private helper functions
	private:

		// Helper to insert a tree into this tree
		void insert_tree_helper(Tri_Tree<T>* tree);

		// Checks if any value in a tree is present in this tree
		bool check_if_repeat(Tri_Tree<T>* tree) const;

		// Moves tree values to fill a removed value
		void repopulate(unsigned char remove_flag);

		// Helper to print out values of this tree
		void display_helper() const;
};

#endif
