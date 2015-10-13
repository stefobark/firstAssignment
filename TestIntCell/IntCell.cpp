#include "IntCell.h"

/*
	this is the implementation of IntCells (interface is at IntCell.h).
	I read about passing by constant reference and so I brought it in here. 
	the compiler complains:
	warning: reference to local variable ‘x’
	for both addTwo and subTwo
	I think that is because I'm returning a constant reference.
	Is this a problem?
	

/**
 * Construct the IntCell with initialValue
 */
IntCell::IntCell( int initialValue ) : storedValue( initialValue )
{
}

/**
 * Return the stored value.
 */
int IntCell::read( ) const
{
    return storedValue;
}

/**
 * Store x.
 */
void IntCell::write( const int x )
{
    storedValue = x;
}

/**
 * Add two IntCells, return the sum
 * get two constant references to two different IntCells and return a reference
 */
  
int IntCell::addTwo(const IntCell & a, const IntCell & b ) const
{
	 int x = a.read() + b.read();
	 
	 return x;
}

/**
 * Subtract two IntCells, return whats left
 * passing constant reference and returning reference
 */
  
int IntCell::subTwo( const IntCell & a, const IntCell & b ) const
{
	 int x = a.read() - b.read();
	 
	 return x;
}

/**
 * add another intcell's storedValue to this one's storedValue, return the sum
 */
  
int IntCell::add( const IntCell & a)
{
	 storedValue = storedValue + a.read();
	 
	 return  storedValue;
}

/**
 * subtract another intcell's storedvalue from this one's stored value, return whats left
*/
  
int IntCell::sub( const IntCell & a)
{
	 storedValue = storedValue - a.read();
	 
	 return  storedValue;
}

/**
 * add the sum of an array of intcells to this one's storedValue
*/

int IntCell::add( const std::vector<int> & a )
{
	for(int x : a){
	 	storedValue = storedValue + x;
	}
	 return  storedValue;
}

/**
 * subtract the sum of an array of intcells from this one's storedValue
*/

int IntCell::sub( const std::vector<int> & a )
{
	for(int x : a){
	 	storedValue = storedValue - x;
	}
	 return  storedValue;
}
