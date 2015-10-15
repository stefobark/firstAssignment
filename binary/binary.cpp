/*
	Steve Barker
	Exercise 1.5
	
	Converts an int (from user input with infinite while loop) 
	to a binary string and then counts the 1 by recursively calling findOnes()
*/

#include <bitset>
#include <iostream>
#include<string>
using namespace std;

void findOnes(string uInput,  int & onesCount)
{
		// this will return the position of the first 1 in the binary string
		size_t firstOne = uInput.find("1");
		
		//this will hold everything after the first 1 we find in the string
		string cutInput;
		
		//if we actually find a 1, do these things
		if(firstOne != string::npos){
			//get everything after the 1
			cutInput = uInput.substr(firstOne+1);
			//increment our counter
			onesCount++;
			//call findOnes again with the substring as input (repeat...look for 1s again)
			findOnes(cutInput,onesCount);
		} 
		
		
}
	
int main()
{
  	 int i;
  	 string uInput;
  	 int onesCount = 0;
  	
	 cout << "convert int to binary" << endl;
	 while(true){
	 		 
	 		 cout << "Enter a number: ";
			 cin >> i;
			 bitset<32>      x(i);
			 uInput = x.to_string();
			 
			 cout << "Binary: " << uInput << endl;
			 findOnes(uInput,onesCount);
			 cout << "Number of Ones: " << onesCount << endl;
			 onesCount = 0;
			 
		}
	
}
