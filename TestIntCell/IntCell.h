#ifndef IntCell_H
#define IntCell_H
#include <vector>
/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 );
    int read( ) const;
    int & addTwo( const IntCell & a, const IntCell & b ) const;
    int add( const IntCell & a );
    int add( const std::vector<int> & a );
    int & subTwo( const IntCell & a, const IntCell & b ) const;
    int sub( const IntCell & a );
    int sub( const std::vector<int> & a );
    void write( int x );

  private:
    int storedValue;
};

#endif
