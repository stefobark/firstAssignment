#include <iostream>
#include <vector>
#include <string>

/*  
	* including IntCell.cpp also brings in IntCell.h because IntCell.h is included there
*/

#include "IntCell.cpp" 

using namespace std;


int main( )
{
    
	 IntCell a;
	 a.write(5);
	 
	 IntCell b;
	 b.write(5);
	 
	 const int & i = a.read();
	 const int & j = b.read();
	 
	 std::vector<int> nums {1,2,3,4,5,6};
	 cout << "I'm trying out passing by constant reference (in all the add and sub functions)." << endl;
	 cout << "\n" << "int addTwo( const IntCell & a, const IntCell & b ) const;\n";
	 cout << "\ta.add(a,b)" << endl;
	 cout << "\n\tThis takes any two IntCells, uses 'read()' to get their\n";
	 cout << "\tstoredValue and returns the (int) sum of the two stored values\n" << endl;
    cout << "\t" << "a = " << i << endl;
    cout << "\t" << "b = " << j << endl;
    cout << "\t" << i << " + " << j << " = " << a.addTwo(a,b) << "\n\n";
    
    cout << "\n" << "int subTwo( const IntCell & a, const IntCell & b ) const;" << endl;
    cout << "\n\tThis takes any two IntCells, uses 'read()' to get their";
    cout << "\n\tstoredValue and returns what is left after\n\t subtracting one of the storedValues\n" << endl;
    cout << "\n\t" << "a = " << i << endl;
    cout << "\t" << "b = " << j << endl;
    cout << "\t" << i << " - " << j << " = " << a.subTwo(a,b) << "\n\n";
    
    cout << "int add( const IntCell & a );" << endl;
    cout << "\n\tThis takes an IntCell, adds it to the storedValue of \n";
    cout << "\tthis IntCell and returns the (int) sum\n" << endl;
    cout << "\n\t" << "a = " << i << endl;
    cout << "\t" << "b = " << j << endl;
    cout << "\t" << i << " + " << j << " = " << a.add(b) << "\n\n";
    
    cout << "int sub( const IntCell & a );\n\ta.sub(b) " << endl;
    cout << "\n\tThis takes an IntCell, subtracts it from the storedValue \n";
    cout << "\tof this IntCell and returns whats left\n" << endl;
    cout << "\n\t" << "a = " << a.read() << endl;
    cout << "\t" << "b = " << b.read() << endl;
    cout << "\t" << "a" << " - " << "b" << " = " << a.sub(b) << "\n\n";
    
    cout << "int add( const std::vector<int> & a );" << endl;
    cout << "\n\tThis takes an array of ints and adds its sum to this \n";
    cout << "\tIntCell's storedValue and returns the new storedValue\n" << endl;
    
    cout << "\n\t";
     
    for(int i : nums){
    	cout << i << " + ";
    }
    
    cout << "storedValue: {{" << a.read() << "}}";
    
    cout << " = " << a.add(nums) << "\n\n";
    
    cout << "int sub( const std::vector<int> & a );\n\ta.sub(nums)" << endl; 
    cout << "\n\tThis takes an array of ints and subtracts its sum from this \n";
    cout << "\tIntCell's storedValue and returns whats left\n" << endl;
    
    cout << "\n\t";
    cout << "current storedValue: " << "{{"<< a.read() << "}}";
    for(int i : nums){
    	cout << " - " << i ;
    }
    
    
    
    cout << " = " << a.sub(nums) << "\n\n";
    
    return 0;
}


