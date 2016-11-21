FLAGS = -std=c++11

all:	kappa.exe

kappa.exe:	Tri_Tree.o BinarySearchTree.o Driver.o
	g++ $(FLAGS) Tri_Tree.o BinarySearchTree.o Driver.o -o kappa.exe

Tri_Tree.o:	Tri_Tree.cpp
	g++ $(FLAGS) -c Tri_Tree.cpp

Driver.o:	Driver.cpp
	g++ $(FLAGS) -c Driver.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	g++ $(FLAGS) -c BinarySearchTree.cpp

clean:
	rm -f -v *.o kappa.exe
