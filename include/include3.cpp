#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*--------------------------------------------------------------------------------*
 *																											 *
 *	I'm not sure I understood the problem correctly. What I did was to look at a	 *
 * file and read it line by line. If this line includes "#include" then I take 	 *
 * the file name that is included and store it in a vector. Then, I get all lines *
 * that have no includes and store them in a different vector. After that, I use	 *
 * the file name to call getFromFile() again (recursively) until the fileName		 *
 * is "end".																							 *
 *--------------------------------------------------------------------------------*/

void getFromFile(string & f, vector<string> & files, vector<string> & contents){
	//start reading in this file
	ifstream infile(f);
	
	//this will hold the new fileName;
	string fileName;
	
	//this will hold the rest of the content of the file
	string content;
	
	//we'll read the file line by line. this will hold our line.
	string line;
	
	//while we can get lines from this file..
	while (getline(infile, line))
	{
		
		 if(line.find("#include") == 0){
		 	size_t beginIncludeName = line.find("<")+1;
		 	
		 	fileName = line.substr(beginIncludeName);
		 	fileName.pop_back();
		 
			//let's see the file names
			//cout << fileName << endl;
		 
		 	//add them to this vector so we can write to a file later
		 	files.push_back(fileName);
		 	
		 } else {
		 	content = line;
		 	contents.push_back(content);
		 }
		 
		 // change f for the new getFromFile() call
		 f = fileName;
	}
	
	if(fileName != "end"){
		//do it again
		getFromFile(f,files,contents);
	} 
}

int main()
{
	//write to this file
	fstream file("test");
	
	fstream & write = file;
	string f = "1";
	vector<string> files = {f};
	vector<string> contents;
	
	getFromFile(f,files,contents);
	
	for(int i = 0; i < files.size(); i++){
			cout << files[i] << endl;
			cout << contents[i] << endl;
			write << files[i] << endl;
			write << contents[i] << endl;
		}
			
}
