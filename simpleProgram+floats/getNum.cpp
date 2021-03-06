/*
	Steve Barker
	Six Simple Exercises part 1
	
	This is the first problem on the assignment. I  created some functions so I could accept user input in a constant loop-- every time
	they enter something it is sent as a string, then converted to a float and added to a vector (array).
	(I chose to play with floats so that users could enter decimal values)
	I've got sortH(), sortL() to sort from high to low and low to high-- I've also got min() and max() to get the high and low values
	and avg() does pretty much the same thing as addEmAll() but it returns the total/nums.size() so we can see the average.
	next step-- implement IntCells
	
	there is an example (an image, a png) in this folder.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global variables


vector<float> nums; // resizable array to hold any number of numbers
float uNum; //user number
string uInput; // variable to hold the string that the user will enter


// AHA! I see why it is nice to separate interface and implementation. Compiler kept complaining that these functions
// weren't declared in the correct scope

void getInput();
void procInput();
void storeInput();
float addEmAll();
void pCmd();
void clear();
float max();
float min();
void swap();
void sortH();
void sortL();
float avg();
void printCollection();

// adds user input to (vector) array of floats
void storeInput(){
	if(uNum){
		nums.push_back(uNum);
		cout << "\t" << uNum << endl;
		cout << "\t# of Numbers: " << nums.size() << endl;
	}
	getInput();
}

// swaps the two nums we give it
void swap(float *x, float *y){
	float tmp = *x;
	*x = *y;
	*y =  tmp;
}

// makes sure we can make a float from the user's string
void procInput(){
	if(uNum = stof(uInput)){
		//we were able to convert it to a float, so add it to our collection
		storeInput();
	}
}

// sort from high to low
void sortH(){
	for(int i = 0; i < nums.size(); i++){
		for(int j = i; j < nums.size(); j++){
			if(nums[i] < nums[j]){
				swap(nums[i], nums[j]);
			}
		}
	}
	printCollection();
	getInput();
}	

// sort from low to high
void sortL(){
	for(int i = 0; i < nums.size(); i++){
		for(int j = i; j < nums.size(); j++){
			if(nums[i] > nums[j]){
				swap(nums[i], nums[j]);
			}
		}
	}
	printCollection();
	getInput();
}	

//print the content of nums
void printCollection(){
	cout << "Your collection sorted from high to low: " << endl;
	for(float i : nums){
		cout << i << endl;
	}
}

//print all commands
void pCmd(){
	cout << "\t'1234...' \t: \tenter numbers to add them to your collection" << endl;
	cout << "\t'a' \t\t: \tadd all the numbers in your collection" << endl;
	cout << "\t'v' \t\t: \tget the average of all the numbers in your collection" << endl;
	cout << "\t'c' \t\t: \tclear all numbers from your collection" << endl;
	cout << "\t'm' \t\t: \tfind the highest number in your collection" << endl;
	cout << "\t'l' \t\t: \tfind the lowest number in your collection" << endl;
	cout << "\t's' \t\t: \tsort collection from high to low" << endl;
	cout << "\t'b' \t\t: \tsort collection from low to high" << endl;
	cout << "\t'q' \t\t: \tquit the program" << endl;
	getInput();
}

//empty vector (array) of nums
void clear(){
	nums.clear();
	getInput();
}

//find the smallest number
float min(){
	float min = 999999999;
	for(float f : nums){
		if(f < min) min = f;
	}
	return min;
}

//find the highest number
float max(){
	float max = 0;
	for(float f : nums){
		if(f > max) max = f;
	}
	return max;
}

//exit the program
int quit(){
	return -1;
	}

//get user input and do something based on what the user wants
void getInput( ){
	
	getline(cin, uInput);	
	
	switch(uInput[0]){
		case 'a' :
			cout << "Total: " << addEmAll() << endl;
			getInput();
			break;
		case 'v' :
			cout << "Average: " << avg() << endl;
			getInput();
			break;
		case 'i' :
			pCmd();
			break;
		case 'm' :
			cout << "\tHighest number in your collection \t: \t" << max() << endl;
			getInput();
			break;
		case 'c' :
			clear();
			getInput();
			break;
		case 'l' :
			cout << "\tLowest number in your collection \t: \t" << min() << endl;
			getInput();
			break;
		case 'q' :
			quit();
			break;
		case 's' :
			sortH();
			break;
		case 'b' :
			sortL();
			break;
		default :
			procInput();
	}
}

// get the sum of all the nums in the collection
float addEmAll(){
	float total = 0;
	for(float i : nums){
		total = total + i;
	}
	return total;
}

// get the sum of all the nums in the collection
float avg(){
	float total = 0;
	for(float i : nums){
		total = total + i;
	}
	return total/nums.size();
}

//main program!
int main(){
	
	cout << "\nEnter a number or a command \n(or, enter 'i' to see all commands) " << endl;
	//loops forever (until user stops it) changing based on user input
	getInput();
	
}

