#include "./../TestIntCell/iCell.h"
#include <iostream>
#include<cstdio>
using namespace std;

/*
part 4 of the six simple exercises
*/

/*
 * Figure 1.17... with modifications.
 */
int f( )
{
	 iCell x {1};
	 iCell y {2};
	 iCell z {3};
	 
    vector<iCell> a { x,y,z };
    vector<iCell> b (a.begin(),a.end());
    vector<iCell> * c;
    
    for(int i =0; i < 3; i++){
    	c->push_back(b[i]);
    }
    
    a[0].write(9);
    cout << "first vector\n";
    for(int i = 0; i < 3; i++){
    	 cout << a[i].read( ) << endl;
 	 }
 	 cout << "\nsecond vector\n";
  	 for(int i = 0; i < 3; i++){
  	  	 cout << b[i].read( ) << endl;
  	 }
  	 cout << "\nthird vector\n";
  	 for(int i = 0; i < 3; i++){
  	  	 cout << c[i].read( ) << endl;
  	 }
    return 0;
}


int main( )
{
    f( );
    
    return 0;
}

