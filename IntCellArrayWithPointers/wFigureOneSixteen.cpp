
/*
	Steve Barker
	part 5 of the six simple exercises using pointer version of intCell without big 5
	shallow copy problem
	
	Example output (see how second vector is changed by changes to first vector):
	
	stefo@ubuntu:~/CppStuff/firstAssignment/IntCellArrayWithPointers$ ./oneSixteen
	first vector
	9
	2
	3

	second vector
	9
	2
	3

	third array
	9
	2
	3

*/

#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;


class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 )
      { storedValue = new int{ initialValue }; }

    int read( ) const
      { return *storedValue; }
    void write( int x )
      { *storedValue = x; }
    
  private:
    int *storedValue;
};


int f( )
{
	 IntCell x {1};
	 IntCell y {2};
	 IntCell z {3};
	 
    vector<IntCell> a { x,y,z };
    vector<IntCell> b (a.begin(),a.end());
    IntCell * c[3];
    
    a[0].write(9); // this demonstrates the shallow copy problem. changing the values of a changes the values of b
    
    cout << "first vector\n";
    for(int i = 0; i < 3; i++){
    	 cout << a[i].read( ) << endl;
 	 }
 	 
 	 cout << "\nsecond vector\n";
  	 for(int i = 0; i < 3; i++){
  	  	 cout << b[i].read( ) << endl; // this will show us that the second vector now also has a 9 at [0]
  	 }

	 // c[] is an array of pointers to the addresses of the values in a[]
    for(int i =0; i < 3; i++){
    	c[i] = &a[i];
    }
    
    // it makes sense that c[0] would change with a[0]'s change-- its a pointer.
  	 cout << "\nthird array\n";
  	 for(int i = 0; i < 3; i++){
  	  	 cout << c[i]->read( ) << endl;
  	 }
  	 
    return 0;
    
}


int main( )
{
    f( );
    
    return 0;
}

