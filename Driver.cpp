#include "Tri_Tree.h"

int main()
{
	Tri_Tree<int> tree(10, 20);
	tree.display();
	
	tree.insert(15);
	tree.display();
	
	tree.insert(25);
	tree.display();
	
	tree.insert(5);
	tree.display();
	
	tree.insert(4);
	tree.display();
	
	tree.insert(8);
	tree.display();
	
	return 0;
}