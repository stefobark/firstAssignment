#ifndef iCell_H
#define iCell_H
#include <vector>

// this is example 1.14

class iCell
{
  public:
    explicit iCell( int initialValue = 0 )
      { storedValue = new int( initialValue ); }

    int read( ) const
      { return *storedValue; }
    void write( const int & x )
      { *storedValue = x; }
  private:
    int *storedValue;
};
#endif
