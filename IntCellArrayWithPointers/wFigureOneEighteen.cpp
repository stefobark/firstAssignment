/*
	Steve Barker
	Added big five to the pointer version of intcell and now
	the second vector is independent of the first
	
	the output of this program shows how long each style of copying takes and
	I write out what is happening to help me understand.
*/
	
#include "IntCell.h" // this version of IntCell has the destructor, copy and move constructor
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<IntCell> iCells(int size);
void printA(vector<IntCell> iC);
vector<IntCell> copyA(vector<IntCell> * iC);
vector<IntCell> copyB(const vector<IntCell> & iC);
vector<IntCell> & copyC(const vector<IntCell> & iC);
int aSize = 99999;

//this builds a vector of iCells of 'size' size
vector<IntCell> iCells(int size){
	vector<IntCell> intcells;
	for(int i = 0; i < size; i++){
		IntCell j;
		j.write(i);
		intcells.push_back(j);
	}
	return intcells;

}

//this used to print the whole vector, but now it just prints the size
void printA(vector<IntCell> iC){
	cout << "Original vector size: " << iC.size() << endl;
}

//pass vector by value, copy it into a new vector with push_back, and return the vector by value
vector<IntCell> copyA(vector<IntCell> iC){
	vector<IntCell> n;
	for(int i = 0; i < iC.size(); i++){
		n.push_back(iC[i]);
	}
	return n;
}

//pass by constant reference 
vector<IntCell> copyB(const vector<IntCell> & iC){
	const vector<IntCell> & newA { iC }; // a constant reference to iC
	return newA; // return the value pointed to by newA
}

int main(){
	
	vector<IntCell> theIntCells = iCells(aSize);
	cout << "\n\n***This is using IntCell example 1.18***\n\n";
	printA(theIntCells);
	
	clock_t t;
	t= clock();
	// pointer vector to  theIntCell vector
	vector<IntCell>* pointICell = &theIntCells;
	t = clock() - t;
	cout << "\nvector<IntCell>* newICell = &theIntCell";
	printf ("\nIt took %d clicks (%f seconds) to do default ' = ' copy.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	cout << "\nThis is a shallow copy-- two variables are pointing to the same address," << endl;
	cout << "which therefore hold the same values. But, if I delete one of them, \n";
	cout << "the other is pointing to something that doesn't exist anymore. \n\n";

	cout << "This can be a problem with shallow copying.\n\n";
	cout << "So, if I clear the copy with: 'newICell->clear();' then the original is cleared as well.\n\nSee:\n\t";
	pointICell->clear();
	printA(theIntCells); //now, theIntCell has nothing.
	theIntCells = iCells(aSize); // repopulate theIntCells
	cout << "\nBut, if we do things differently... with a copy function like this: \n\n";
	cout << "\t vector<IntCell> copyA(vector<IntCell> iC){\n";
	cout << "\t\tvector<IntCell> n = iC;\n";
	cout << "\t\treturn n";
	cout << "\n\t}\n\n";
	
	cout << "We pass in a VALUE and return a copy, but as another VALUE\n";
	cout << "\nIt is less efficient to copy, but now this copy is independent of the old vector.\n";

	t= clock();
	vector<IntCell> newICell = copyA(theIntCells);
	t = clock() - t;

	cout << "\n\n";
	printf ("It took me %d clicks (%f seconds) to do copyA.\n",t,((float)t)/CLOCKS_PER_SEC);
	cout << "\nThen we clear() the copy to see if this destroys the old vector.\n";
	// clearing this new vector should not destroy the old vector
	newICell.clear();
	cout << "\nSee that this size is not 0: \n\n\t";
	printA(theIntCells);
	cout << "\nPerfect.\n";
	cout << "\nOr what if we pass the vector to the function as a constant reference?\n";
	cout << "And return a constant reference?\n\n";
	cout << "like this: \n\n";
	cout << "\tvector<IntCell> copyB(const vector<IntCell> & iC){\n";
	cout << "\t\tconst vector<IntCell> & newA { iC };\n";
	cout << "\t\treturn newA;\n";
	cout << "\t}";
	
	t= clock();
	newICell = copyB(theIntCells);
	t = clock() - t;
	printf ("\n\nIt took me %d clicks (%f seconds) to do copyB. Faster.\n",t,((float)t)/CLOCKS_PER_SEC);
	cout << "\nAnd then, if we clear() this vector, the original should be unchanged.\n\nLet's see:\n\n\t";
	// clearing this new vector should not destroy the old vector
	newICell.clear();
	printA(theIntCells);
	cout << "\n\n \t\t the end \n\n";

}
