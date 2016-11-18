#include "Tri_Tree.h"

int main()
{
	Tri_Tree<int> tree(10, 20);
	
	tree.insert(15);
	
	tree.display();
	
	return 0;
}