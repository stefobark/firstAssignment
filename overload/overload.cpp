/*
	Steve Barker
	Six Simple C++ Exercises: part 7
	An example of overloading comparison operators for MemoryCells.
	
	Output of program looks like this:
	stefo@ubuntu:~/CppStuff/firstAssignment/overload$ ./overload
	m1 (1) < m2 (2)
	m1 (9) > m2 (3)
	m3 (Dog) < m4 (Zebra)
	m3 (Dog) != m4 (Zebra)
	changed m3 to Zebra
	m3 (Zebra) == m4 (Zebra)
*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <strings.h>
using namespace std;

/* 
	Here's the memory cell, now I'm going to overload those comparison operators
*/


/**
 * A template class for simulating a memory cell. Generic. Should accept any type.
 */
template <typename Object>
class MemoryCell
{
  public:
    explicit MemoryCell( const Object & initialValue = Object{ } )
      : storedValue{ initialValue } { }
    const Object & read( ) const
      { return storedValue; }
    void write( const Object & x )
      { storedValue = x; }

    /************************************************************************
    * for strings, I still have to fix the case sensitivity problem somehow *
    * and, the difference between friend and member function is that with a *
    * member function I just implicitly access *this and with a 'friend' I  *
    * would pass in two parameters and compare them (like with the << below)*
    ************************************************************************/

    // overloading < -- will return true if x is less than than y
    bool operator<(MemoryCell x)
    	{ return read() < x.read(); }
    	
     // overloading > -- will return true if x is greater than y
    bool operator>(MemoryCell x)
    	{ return read() > x.read(); }
    
    bool operator==(MemoryCell x)
    	{ return read() == x.read(); }
   
    bool operator!=(MemoryCell x)
    	{ return read() != x.read(); }
    
    //member function to print MemoryCells
    ostream& operator <<(ostream& os)
    	{ 
    		os << read();
    		return os;
    	}
    	
    //overloading the << with 'friend' to print MemoryCells
	 friend ostream& operator<<(ostream& os, const MemoryCell& memCell)
		{
			 os << memCell.read();
			 return os;
		}
    
  private:
    Object storedValue;
};

int main( )
{
    MemoryCell<int>    		m1;
    MemoryCell<int>   		m2;
    MemoryCell<string>    	m3;
    MemoryCell<string>    	m4;

    m1.write( 1 );
    m2.write( 2 );
    if(m1 < m2) cout << "m1 ("<< m1 << ") < m2 (" << m2 << ")" << endl;
    
    m1.write( 9 );
    m2.write( 3 );
    
    if(m1 > m2) cout << "m1 ("<< m1 << ") > m2 (" << m2 << ")" << endl;

	 m3.write( "Dog" );
	 m4.write( "Zebra" );
	 if(m3 < m4) cout << "m3 ("<< m3 << ") < m4 (" << m4 << ")" << endl;
	 if(m3 > m4) cout << "m3 ("<< m3 << ") > m4 (" << m4 << ")" << endl;
	 if(m3 != m4) cout << "m3 ("<< m3 << ") != m4 (" << m4 << ")" << endl;
	 cout << "changed m3 to Zebra" << endl;
	 m3.write("Zebra");
	 if(m3 == m4) cout << "m3 ("<< m3 << ") == m4 (" << m4 << ")" << endl;
    return 0;
}
