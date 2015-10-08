#include "./../TestIntCell/iCell.h"
#include <iostream>
#include<cstdio>
using namespace std;

/*
	this is part 4 of the 'six simple c++ exercises. 'iCell.cpp' is the IntCell using pointers (1.14) 
	
	
	https://www.youtube.com/watch?v=IyXxgaIEFpU <-- good introduction to shallow vs. deep copy
	
*/

vector<iCell> iCells(int size);
void printA(vector<iCell> iC);
vector<iCell> copyA(vector<iCell> * iC);
vector<iCell> copyB(const vector<iCell> & iC);
int aSize = 99999;
vector<iCell> iCells(int size){

	vector<iCell> intcells;
	for(int i = 0; i < size; i++){
		iCell j;
		j.write(i);
		intcells.push_back(j);
	}
	return intcells;

}

void printA(vector<iCell> iC){
	cout << "Original vector size: " << iC.size() << endl;
}

vector<iCell> copyA(vector<iCell> iC){
	vector<iCell> n;
	for(int i = 0; i < iC.size(); i++){
		n.push_back(iC[i]);
	}
	return n;
}

vector<iCell> copyB(const vector<iCell> & iC){
	const vector<iCell> & newA { iC }; // a constant reference to iC
	return newA; // dereference newA so we can return the value pointed to by newA
}

vector<iCell> copyC(vector<iCell> iC){
	vector<iCell> newA;
	newA = iC;
	return newA; 
}

int main(){
	
	vector<iCell> theIntCell = iCells(aSize);
	cout << "\n\n***Things are starting to make sense***\n\n";
	printA(theIntCell);
	
	clock_t t;
	t= clock();
	// pointer vector to  theIntCell vector
	vector<iCell>* newICell = &theIntCell;
	t = clock() - t;
	cout << "\nvector<iCell>* newICell = &theIntCell";
	printf ("\nIt took me %d clicks (%f seconds) to do default ' = ' copy.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	cout << "\nShallow Copy with a pointer-- two variables are pointing to the same address," << endl;
	cout << "which therefore hold the same values. But, if I delete one of them, \nthe other is pointing to something that doesn't exist anymore. \n\n";

	cout << "This can be a problem with shallow copying.\n\nSo, if I clear the copy with: 'newICell->clear();' then the original copy is cleared\n" << endl;
	newICell->clear();
	cout << "\n\t";
	printA(theIntCell); //now, theIntCell has nothing.
	
	cout << "\nBut, if we do things differently... with a copy function like this: \n\n";
	cout << "\t vector<iCell> copyA(vector<iCell> iC){\n";
	cout << "\t\tvector<iCell>  n = iC\n";
	cout << "\t\treturn n";
	cout << "\n\t}\n\n";
	
	cout << "It passses in iC then, we have a pointer pointing at iC (but, is this pointing at a new iC? a local iC?\n";
	cout << "Because, we didn't pass this parameter as a pointer?!)\n\n";
	cout << "Looks like this:\n\n\t";
	cout << "newNext = copyA(nextIntCells);\n";
	cout << "\nbut now, we can use this function to copy a vector-- then we can delete this copy and we will find that the original will be left intact.\n";

	// try again with a new vector of iCells
	vector<iCell> nextIntCells = iCells(aSize);
	
	t= clock();
	vector<iCell> newNext;
	newNext = copyA(nextIntCells);
	t = clock() - t;

	cout << "\n\n";
	printf ("It took me %d clicks (%f seconds) to do copyA.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	// clearing this new vector should not destroy the old vector
	newNext.clear();
	cout << "\nSee that this size is not 0: \n";
	printA(nextIntCells);
	
	cout << "\nOr what if we pass the vector to the function as a constant reference? And return a constant reference to it's instance array of IntCells?:\n\n";
	cout << "like this: \n\n";
	cout << "\tvector<iCell> copyB(const vector<iCell> & iC){\n";
	cout << "\t\tconst vector<iCell> & newA { iC };";
	cout << "\t\treturn newA;\n";
	cout << "\t}";
	
	t= clock();
	vector<iCell> moreNew = copyB(nextIntCells);
	t = clock() - t;
	printf ("\n\nIt took me %d clicks (%f seconds) to do copyB.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	// clearing this new vector should not destroy the old vector
	moreNew.clear();
	printA(nextIntCells);
}
