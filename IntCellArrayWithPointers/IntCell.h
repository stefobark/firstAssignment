#include <algorithm>    // std::swap

class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 ) 						// no parameter default constructor
	 { 
		storedValue = new int{ initialValue }; 
	 }
		
    IntCell( const IntCell & rhs ) 										// copy constructor
    {
    	storedValue = new int( *rhs.storedValue );
	 }
	 
    IntCell( IntCell && rhs ) : storedValue{ rhs.storedValue } // move constructor
	 { 
			rhs.storedValue = nullptr;  // i think this is to stop memory leaks? setting the passed IntCell's *storedValue to null? hmm
	 } 									
    
    ~IntCell( )																// destructor
	 {
		delete storedValue;
	 }
	 
    const IntCell & operator=( const IntCell & rhs )				// copy assignment
    {
    	if( this != &rhs ) *storedValue = *rhs.storedValue;  		// I think this is saying that if these are not the same object then copy 
																					// the value that is pointed to by rhs to this object's storedValue
    	return *this;															// and return it.
	 }
	 
	 IntCell & operator=( IntCell & rhs ) 								// move assignment.
	 {
	 	std::swap( storedValue, rhs.storedValue );
	 	return *this;
	 }
	 
	

    int read( ) const;
    void write( int x );
  private:
    int *storedValue;
};



int IntCell::read( ) const
{
    return *storedValue;
}

void IntCell::write( int x )
{
    *storedValue = x;
}
