#include "./../TestIntCell/IntCell.cpp"
#include <iostream>
using namespace std;


vector<IntCell> iCells(int size);
void printA(vector<IntCell> iC);
vector<IntCell> copyA(vector<IntCell> iC);
vector<IntCell> copyB(const vector<IntCell> iC);

vector<IntCell> iCells(int size){

	vector<IntCell> intcells;
	for(int i = 0; i < size; i++){
		IntCell j;
		j.write(i);
		intcells.push_back(j);
	}
	return intcells;

}

void printA(vector<IntCell> iC){
	cout << "Array with "<< iC.size() << " elements." << endl;
	
}



vector<IntCell> copyA(vector<IntCell> iC){
	vector<IntCell> * newA; // an array of pointers to IntCells
	newA = &iC; // newA = address of iC
	return *newA; // return the value pointed to by newA
}

vector<IntCell> copyB(const vector<IntCell> iC){
	const vector<IntCell> & newV = iC;
	return newV;
	}

int main(){
	
	vector<IntCell> iCell = iCells(10000000);
	cout << "Total: " << iCell.size() << endl;
	printA(iCell);
	
	cout << "CopyA:" << endl;
	
	vector<IntCell> newICell1;
	
	clock_t t;
	t= clock();
	newICell1 = copyA(iCell);
	printA(newICell1);
	t = clock() - t;
	printf ("It took me %d clicks (%f seconds) to do copyA.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	vector<IntCell> newICell2;
	t= clock();
	cout << "\nCopyB:" << endl;
	newICell2 = copyB(iCell);
	t = clock() - t;
	printf ("It took me %d clicks (%f seconds) to do copyB.\n",t,((float)t)/CLOCKS_PER_SEC);
	
	printA(newICell2);
	
}
