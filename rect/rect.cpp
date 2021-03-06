/*
	Steve Barker.
	Chapter 1. 
	Problem 1.15
	A program with a rectangle class that is comparable to other rectangle objects.
	We can change its dimensions and use < and > to compare the area of two triangles.
	There is also a comparePerimeter function.
	
	I wasn't able to finish implementing the findMax template function from example 1.25.
	Will do this soon!
*/

#include<iostream>
#include<string.h>
#include<string>
#include <vector>
using namespace std;

class Rectangle
{
  public:
    explicit Rectangle( vector<int> x)
    	: storedValue{ x }{};
    	
	 int getLength( ) const
      { return storedValue[0]; }
    void changeLength( int x )
      { storedValue[0] = x; }
      
    int getWidth( ) const
      { return storedValue[1]; }
    void changeWidth( int y )
      { storedValue[1] = y; }
    
    int getArea () const
    	{ return getLength() * getWidth(); }
    	
    int getPerimeter () const
    	{ return (getLength() * 2) + (getWidth() * 2); }
    
    bool comparePerimeter(Rectangle otherRectangle)
    	{ return otherRectangle.getPerimeter() > getPerimeter(); }
        	
    // overloading < -- will return true if other is less than this
    bool operator<(Rectangle otherRectangle)
    	{ return getArea() < otherRectangle.getArea(); }
    
    // overloading > -- will return true if other is more than this
    bool operator>(Rectangle otherRectangle)
    	{ return getArea() > otherRectangle.getArea(); }
     
  private:
  	 int x, y;
    vector<int> storedValue {x,y};
};

int main(){
	vector<int> size {5,5};
	Rectangle rectOne (size);
	Rectangle rectTwo (size);
	cout << "\nrectOne X = " << rectOne.getWidth() << endl;
	cout << "rectOne Y = " << rectOne.getLength() << endl;
	cout << "\nrectTwo X = " << rectTwo.getWidth() << endl;
	cout << "rectTwo Y = " << rectTwo.getLength() << endl;
	cout << "\nnow changing rectOne size" << endl;
	
	//changing the rectangles dimensions
	rectOne.changeLength(14);
	rectOne.changeWidth(3);
	
	cout << "\nnew rectX = " << rectOne.getWidth() << endl;
	cout << "new rectY = " << rectOne.getLength() << endl;
	cout << "\nnow checking area ( '<' and '>' which default to area comparison): " << endl;
	cout << "\n\trectTwo < rectOne" << endl;
	if(rectTwo < rectOne){
		cout << "\nrectTwo (area: " << rectTwo.getArea() << ") is less (area) than rectOne (area: " << rectOne.getArea() << ")\n" << endl;
	}
	
	cout << "and, now we're going to compare perimeters" << endl;
	cout << "\n\trectTwo.comparePerimeter(rectOne)" << endl;
	if(rectTwo.comparePerimeter(rectOne)){
		cout << "\nrectTwo (perimeter: " << rectTwo.getPerimeter() << ") is less (perimeter) than rectOne (perimeter: " << rectOne.getPerimeter() << ")\n" << endl;
	}
	
	cout << "Now, to create an array of Rectangles and find the biggest one" << endl;
	
	vector<Rectangle> rects;
	
	for(int i = 0; i < 10; i++)
	{
		vector<int> rSize { rand()%100, rand()%100 };
		Rectangle rect (rSize);
		rects.push_back(rect);
	}
	
	cout << "Vector size: " << rects.size() << endl;
	for(Rectangle r : rects)
		{
			cout << r.getArea() << endl;
		}
	

}

