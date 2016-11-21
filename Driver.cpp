#include <sys/time.h>
#include <stdlib.h>
#include "Tri_Tree.h"
#include "BinarySearchTree.h"
#include <ctime>

using namespace std;

#define BST BinarySearchTree

// Change the number of iterations for the tests here
#define TEST_ITERATIONS 20

// Print trees?
#define PRINT_TREES 1

// Calculates time difference
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);

// Prints time taken in seconds and micro seconds
void timeval_print(string str, struct timeval *tv);

// Main Function:
// Running tests for balanced tree and unbalanced tree
int main()
{
	struct timeval tvDIFF, tvStart, tvEnd;
	srand(time(0));
	// Testing with integers (balanced tree)
	{
        int values[TEST_ITERATIONS + 2];
	    cout << "Testing " << TEST_ITERATIONS << " integers (TST balanced tree):" << endl << endl;

		// Start timer
		gettimeofday(&tvStart, NULL);
		cout << "Timer start" << endl << endl;

		// Make tree
		Tri_Tree<int>* tree = new Tri_Tree<int>(300000, 700000);
		for (unsigned int i = 0; i < TEST_ITERATIONS; i++){
            values[i] = rand() % 1000000;
            tree->insert(values[i]);
        }

		if (PRINT_TREES) tree->display();

		// Stop timer
		gettimeofday(&tvEnd, NULL);
		cout << "Timer end" << endl << endl;

		timeval_subtract(&tvDIFF, &tvEnd, &tvStart);
		timeval_print ("This took: ", &tvDIFF);

		cout << "--------------------------------" << endl;

	    // TESTING REMOVE
		{
			cout << "Testing " << TEST_ITERATIONS << " removals (TST balanced tree):" << endl << endl;
			gettimeofday(&tvStart, NULL);
			cout << "Timer start" << endl << endl;
            if(PRINT_TREES) cout << "Before: "; tree->display();
            cout << "Delete: ";
			for(int i = 0; i < TEST_ITERATIONS; i++){
                cout << values[i] << " ";
				tree->remove(values[i]);
			}
            cout << endl;
            //tree->remove(300000);
			if(PRINT_TREES) cout << "After: "; tree->display();
			gettimeofday(&tvEnd, NULL);
			cout << "Timer stop" << endl << endl;
			timeval_subtract(&tvDIFF, &tvEnd, &tvStart);
			timeval_print("This took: ", &tvDIFF);
			cout << "--------------------------------" << endl;
		}
	}

	// Testing with integers (unbalanced tree)
	{
		cout << "Testing " << TEST_ITERATIONS << " integers (unbalanced tree):" << endl << endl;

		// Start timer
		gettimeofday(&tvStart, NULL);
		cout << "Timer start" << endl << endl;

		// Make tree
		Tri_Tree<int>* tree = new Tri_Tree<int>(1);
		for (int i = 0; i < TEST_ITERATIONS; i++) tree->insert(i+2);

		if (PRINT_TREES) tree->display();

		// Stop timer
		gettimeofday(&tvEnd, NULL);
		cout << "Timer end" << endl << endl;

		timeval_subtract(&tvDIFF, &tvEnd, &tvStart);
		timeval_print ("This took: ", &tvDIFF);

		cout << "--------------------------------" << endl;
	}

	// Testing with integers (balanced tree BST)
	{
		cout << "Testing " << TEST_ITERATIONS << " integers (balanced tree):" << endl << endl;

		// Start timer
		gettimeofday(&tvStart, NULL);
		cout << "Timer start" << endl << endl;

		// Make tree
		BST<int>* tree = new BST<int>(500000);
		for (unsigned int i = 0; i < TEST_ITERATIONS; i++) tree->insert(rand() % 1000000);

		if (PRINT_TREES) tree->display();

		// Stop timer
		gettimeofday(&tvEnd, NULL);
		cout << "Timer end" << endl << endl;

		timeval_subtract(&tvDIFF, &tvEnd, &tvStart);
		timeval_print ("This took: ", &tvDIFF);

		cout << "--------------------------------" << endl;
	}

	// Testing with integers (unbalanced tree)
	{
		cout << "Testing " << TEST_ITERATIONS << " integers (unbalanced tree):" << endl << endl;

		// Start timer
		gettimeofday(&tvStart, NULL);
		cout << "Timer start" << endl << endl;

		// Make tree
		BST<int>* tree = new BST<int>(1);
		for (int i = 0; i < TEST_ITERATIONS; i++) tree->insert(i+2);

		if (PRINT_TREES) tree->display();

		// Stop timer
		gettimeofday(&tvEnd, NULL);
		cout << "Timer end" << endl << endl;

		timeval_subtract(&tvDIFF, &tvEnd, &tvStart);
		timeval_print ("This took: ", &tvDIFF);

		cout << "--------------------------------" << endl;
	}
	return 0;
}

// Calculates time difference
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
	long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
	result->tv_sec = diff / 1000000;
	result->tv_usec = diff % 1000000;
	return (diff<0);
}

// Prints time taken in seconds and micro seconds
void timeval_print(string str, struct timeval *tv)
{
	cout << str;
	printf("%ld sec, %06ld micro sec", tv->tv_sec, tv->tv_usec);
	cout << endl;
}
