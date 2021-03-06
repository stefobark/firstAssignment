//

#include "./../TestIntCell/IntCell.cpp"
#include <iostream>
using namespace std;

/*interface*/

vector<IntCell> iCells(int size); // create a vector of iCells
void printA(const vector<IntCell> & iC); // print the size of the vector
void printB(const vector<IntCell> & iC); // print the first 3 elements
vector<IntCell> copyA(vector<IntCell> * iC); // 
vector<IntCell> copyB(const vector<IntCell> & iC);
vector<IntCell> copyC(vector<IntCell> iC);
void checkPrint(vector<IntCell> original);

//implementation
vector<IntCell> iCells(int size){
	vector<IntCell> intcells;
	for(int i = 0; i < size; i++){
		IntCell j;
		j.write(i);
		intcells.push_back(j);
	}
	return intcells;
}

void printA(const vector<IntCell> & iC){
	cout << iC.size() << " elements." << endl;
	
}

void printB(const vector<IntCell> & iC){
	for(int i=0; i<3; i++){
		cout << i << ": " << iC[i].read() << endl;
	}
	cout << "...\n";
}

/*
	pass pointer
	return new vector
*/

vector<IntCell> copyA(vector<IntCell> * iC){
	vector<IntCell> * newA; // an array of pointers to IntCells
	newA = iC; // newA = address of iC
	return * newA; // return the value pointed to by newA
}


/*
	pass constant reference
	return new vector
*/

vector<IntCell> copyB(const vector<IntCell> & iC){
	const vector<IntCell> & newV = iC;
	return newV;
	}

vector<IntCell> copyC(vector<IntCell> iC){
	vector<IntCell> newV = iC;
	return newV;
	}

void checkPrint(vector<IntCell> original){
	cout << "\n\toriginal iCell size:\t";
	printA(original);
	}
	
void printTime(clock_t t, vector<IntCell> iCell){
	printf ("It took me %d clicks (%f seconds) to copy.\n",t,((float)t)/CLOCKS_PER_SEC);
	printA(iCell);
	printB(iCell);
}

int main(){
	
	vector<IntCell> iCell = iCells(10000000);
	cout << "Total: " << iCell.size() << endl;
	printA(iCell);
	printB(iCell);
	
	cout << "\nCopyA.\nPassing pointer:\n" << endl;
	
	vector<IntCell> newICell1;
	
	clock_t t; // for keeping track of the time for the different styles of copy
	
	t= clock();
	newICell1 = copyA(&iCell);
	t = clock() - t;
	
	printTime(t, newICell1);
	
	
	vector<IntCell> newICell2;
	cout << "\nCopyB.\nPassing constant reference:\n" << endl;
	
	t= clock();
	newICell2 = copyB(iCell);
	t = clock() - t;
	
	printTime(t, newICell2);
	
	vector<IntCell> newICell3;
	cout << "\nCopyC.\nPassing value:\n" << endl;
	
	t= clock();
	newICell3 = copyC(iCell);
	t = clock() - t;
	
	printTime(t, newICell3);
	
	vector<IntCell> * newICell4;
	cout << "\nDefault '=':\n" << endl;
	
	t= clock();
	newICell4 = &iCell;
	t = clock() - t;
	
	printTime(t, *newICell4);
	
	cout << "\n--->clearing newICell1 (created with copyA)\n";
	newICell1.clear();
	checkPrint(iCell);
	
	cout << "\n--->clearing newICell2 (created with copyB)\n";
	newICell2.clear();
	checkPrint(iCell);
	
	cout << "\n--->clearing newICell3 (created with copyC)\n";
	newICell3.clear();
	checkPrint(iCell);
	
	cout << "\n--->clearing newICell4 (created with default '=')\n";
	newICell4->clear();
	checkPrint(iCell);
	
	cout << "\n\nThe original was cleared. I think this demonstrates the problem with shallow copies.\n";
	cout << "Seems that the other methods create a new space \n";
	cout << "to hold the same values, while this default '=' points to the\n";
	cout << "same address as the thing it is copying (because newICell4 is a pointer).\n\n";
	

	
}
