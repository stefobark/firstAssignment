#include <bitset>
#include <iostream>
#include<string>
using namespace std;

void findOnes(string uInput,  int & onesCount, int & totalOnes)
{
		
		size_t firstOne = uInput.find("1");
		string cutInput;
		/*if(firstOne != uInput.length())
		{
			
			uInput = uInput.substr(firstOne);
			
		}*/
		if(firstOne != string::npos){
			cutInput = uInput.substr(firstOne+1);
			onesCount++;
			findOnes(cutInput,onesCount,totalOnes);
		} 
		
		
}
	
int main()
{
  	 int i;
  	 string uInput;
  	 int onesCount = 0;
  	 int totalOnes = 0;
  	
	 cout << "convert int to binary" << endl;
	 while(true){
	 		 
	 		 cout << "Enter a number: ";
			 cin >> i;
			 bitset<32>      x(i);
			 uInput = x.to_string();
			 
			 cout << "Binary: " << uInput << endl;
			 findOnes(uInput,onesCount,totalOnes);
			 cout << "Number of Ones: " cd ../<< onesCount << endl;
			 onesCount = 0;
  	 		 totalOnes = 0;
			 
		}
	
}