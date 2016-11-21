#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include <iostream>
#include <string>

template <class T>
class BinarySearchTree
{
	private:

		// Value stored in this tree
		T content;

		// Pointer to left subtree
		BinarySearchTree<T>* left;

		// Pointer to right subtree
		BinarySearchTree<T>* right;


		// Checks if any value in a tree is present in this tree
		bool checkIfRepeat(BinarySearchTree<T>* tree) const;

		// Moves tree contents to fill a removed value
		void repopulate();

		// Helper to insert a tree into this tree
		void insertTreeHelper(BinarySearchTree<T>* tree);

		// Helper to print out contents of this tree
		void displayHelper() const;

	public:

		// Default constructor
		BinarySearchTree();

		// Value constructor using a value
		BinarySearchTree(const T &value);

		// Default destructor
		~BinarySearchTree();

		// Inserts a value into this tree
		bool insert(const T& value);

		// Inserts a tree of values into this tree
		bool insert(BinarySearchTree<T>* tree);

		// Removes the location where a value is located and repopulates the empty spot
		bool remove(const T& value);

		// Returns true if a value exists in this tree
		bool find(const T& value) const;

		// Prints out the contents of this tree in order
		void display() const;

		// Getters for left, right, and content
		BinarySearchTree<T>* getLeft() const;
		BinarySearchTree<T>* getRight() const;
		T getContent() const;

		// Setters for left, right, and content
		void setLeft(BinarySearchTree<T>* node);
		void setRight(BinarySearchTree<T>* node);
		void setContent(const T& value);
};

#endif
