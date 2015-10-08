/*
	This is my original user input program using the IntCell class instead of floats. 
	The user enters a string, it is converted to an integer and the integer is written to an IntCell
*/

#include <iostream>
#include <vector>
#include <string>
#include "IntCell.cpp" 

using namespace std;

// Global variables


vector<IntCell> nums; // resizable array to hold any number of numbers
int uNum; //user number
string uInput; // variable to hold the string that the user will enter


// AHA! I see why we need to separate interface and implementation. Compiler kept complaining that these functions
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

// adds user input to an array (vector) of IntCells
// because we're using IntCell we create the IntCell, then write a value to it and then add it to the array of all IntCells
// but, all IntCells are identified by 'a'... hmm.. doesn't seem right. but it works. for now. how does this (all of them named 'a') limit the use of IntCells?
void storeInput(){
	if(uNum){
		IntCell a;
		a.write(uNum);
		nums.push_back(a);
		cout << "\t" << a.read() << endl;
		cout << "\t# of Numbers: " << nums.size() << endl;
	}
	
	//listen for more input
	getInput();
}

// swaps the two nums we give it
void swap(IntCell *x, IntCell *y){
	int tmp = x->read();
	x->write(y->read());
	y->write( tmp );
}

// makes sure we can make a float from the user's string
// now its stoi instead of stof because we want an integer to write to the storedValue of the IntCell
void procInput(){
	if(uNum = stoi(uInput)){
		//we were able to convert it to a int, so lets add it to our collection
		storeInput();
	}
}

// sort from high to low
// now that we're using IntCells we have to read() the int value that it contains in it's private storedValue instance variable.
void sortH(){
	for(int i = 0; i < nums.size(); i++){
		for(int j = i; j < nums.size(); j++){
			if(nums[i].read() < nums[j].read()){
				swap(nums[i], nums[j]);
			}
		}
	}
	printCollection();
	getInput(); //listen for more input
}	

// sort from low to high
// again... we're using IntCells now-- so we gotta read the int value otherwise the > doesn't work (yet).
void sortL(){
	for(int i = 0; i < nums.size(); i++){
		for(int j = i; j < nums.size(); j++){
			if(nums[i].read() > nums[j].read()){
				swap(nums[i], nums[j]);
			}
		}
	}
	printCollection();
	getInput();
}	

// print the content of nums
// because the storedValue is private, we can't just print it-- we have to use read() which is public and gets storedValue for us.
void printCollection(){
	cout << "Your collection sorted from high to low: " << endl;
	for(IntCell i : nums){
		cout << i.read() << endl;
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

// find the smallest number
// same thing about IntCells.. we can't read the storedValue, so we have to use read()
float min(){
	int min = 999999999;
	for(IntCell f : nums){
		if(f.read() < min) min = f.read();
	}
	return min;
}

//find the highest number
float max(){
	float max = 0;
	for(IntCell f : nums){
		if(f.read() > max) max = f.read();
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
	for(IntCell i : nums){
		total = total + i.read();
	}
	return total;
}

// get the sum of all the nums in the collection
float avg(){
	float total = 0;
	for(IntCell i : nums){
		total = total + i.read();
	}
	return total/nums.size();
}

//main program!
int main(){
	
	cout << "\nEnter a number or a command \n(or, enter 'i' to see all commands) " << endl;
	//loops forever (until user stops it) changing based on user input
	getInput();
	
}

