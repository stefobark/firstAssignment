# firstAssignment

##simpleProgram+floats
"(Very simple!) Write a C++ program to prompt the user to enter 3 integers. Then print them in forward and reverse order, find and print the max and the min, and give the average."

For this, I figured we could use floats so that we could return more accurate averages. And, I created a loop of functions that:

  * get user input (a switch statement that checks the *first* character in the user input to see what function to call)
  * process it (because I use getline() to get the input as a string and then convert it to a float if possible)

  ```
  // makes sure we can make a float from the user's string
    void procInput(){
	    if(uNum = stof(uInput)){
		    //we were able to convert it to a float, so add it to our collection
		    storeInput();
	    }
    }
  ```
  
  * store it in a vector so the size can change
  
  ```
  // adds user input to (vector) array of floats
    void storeInput(){
	    if(uNum){
		    nums.push_back(uNum);
	  	  cout << "\t" << uNum << endl;
		    cout << "\t# of Numbers: " << nums.size() << endl;
	  }
	  getInput();
  }
  ```
  * and then wait for more user input. 

Users can input 'i' to see the available commands.
Looks like this:

```
Enter a number or a command 
(or, enter 'i' to see all commands) 
i
	'1234...' 	: 	enter numbers to add them to your collection
	'a' 		: 	add all the numbers in your collection
	'v' 		: 	get the average of all the numbers in your collection
	'c' 		: 	clear all numbers from your collection
	'm' 		: 	find the highest number in your collection
	'l' 		: 	find the lowest number in your collection
	's' 		: 	sort collection from high to low
	'b' 		: 	sort collection from low to high
	'q' 		: 	quit the program
```

##simpleProgram+IntCells
This does exactly the same thing as above, but with the user-defined "IntCell" type. Works just fine.

##TestIntCell
This is for part 2 of the six simple exercises. ```IntCellp.cpp``` implements various functions for IntCells and includes the interface at ```IntCell.h```. 

We can now:
  * add an IntCell to another IntCell's storedValue
  * add two IntCells and get their (int) sum
  * do the same things with subtract
  * and we can use this in the simple program above (which is demonstrated by ```simpleProgram+IntCells```).
  * I wrote a little program that prints out these operations so we can see that it is working
 
The program looks like this:
```
stefo@ubuntu:~/CppStuff/firstAssignment/TestIntCell$ ./intCells
I'm trying out passing by constant reference (in all the add and sub functions).

int addTwo( const IntCell & a, const IntCell & b ) const;
	a.add(a,b)

	This takes any two IntCells, uses 'read()' to get their
	storedValue and returns the (int) sum of the two stored values

	a = 5
	b = 5
	5 + 5 = 10


int subTwo( const IntCell & a, const IntCell & b ) const;

	This takes any two IntCells, uses 'read()' to get their
	storedValue and returns what is left after
	 subtracting one of the storedValues


	a = 5
	b = 5
	5 - 5 = 0

int add( const IntCell & a );

	This takes an IntCell, adds it to the storedValue of 
	this IntCell and returns the (int) sum


	a = 5
	b = 5
	5 + 5 = 10

int sub( const IntCell & a );
	a.sub(b) 

	This takes an IntCell, subtracts it from the storedValue 
	of this IntCell and returns whats left


	a = 10
	b = 5
	a - b = 5

int add( const std::vector<int> & a );

	This takes an array of ints and adds its sum to this 
	IntCell's storedValue and returns the new storedValue


	1 + 2 + 3 + 4 + 5 + 6 + storedValue: {{5}} = 26

int sub( const std::vector<int> & a );
	a.sub(nums)

	This takes an array of ints and subtracts its sum from this 
	IntCell's storedValue and returns whats left


	current storedValue: {{26}} - 1 - 2 - 3 - 4 - 5 - 6 = 5
```

##IntCellArrayWithPointers
This is for part 3 and 4. The three executable example files are outlined below. 

###iArray.cpp
```iArray.cpp``` was my first attempt. I just used the IntCell class we wrote to do addition and subtraction. I tried different ways of passing the vectors to copy functions and looked at the number of clicks it took for them to copy the array.

Running ```iArray.cpp``` looks like this:
```
Total: 10000000
10000000 elements.
0: 0
1: 1
2: 2
...

CopyA.
Passing pointer:

It took me 297640 clicks (0.297640 seconds) to copy.
10000000 elements.
0: 0
1: 1
2: 2
...

CopyB.
Passing constant reference:

It took me 321455 clicks (0.321455 seconds) to copy.
10000000 elements.
0: 0
1: 1
2: 2
...

CopyC.
Passing value:

It took me 600760 clicks (0.600760 seconds) to copy.
10000000 elements.
0: 0
1: 1
2: 2
...

Default '=':

It took me 1 clicks (0.000001 seconds) to copy.
10000000 elements.
0: 0
1: 1
2: 2
...

--->clearing newICell1 (created with copyA)

	original iCell size:	10000000 elements.

--->clearing newICell2 (created with copyB)

	original iCell size:	10000000 elements.

--->clearing newICell3 (created with copyC)

	original iCell size:	10000000 elements.

--->clearing newICell4 (created with default '=')

	original iCell size:	0 elements.


The original was cleared. I think this demonstrates the problem with shallow copies.
Seems that the other methods create a new space 
to hold the same values, while this default '=' points to the
same address as the thing it is copying (because newICell is a pointer).
```
###wFigureOneSixteen.cpp
Then, I tried to do the same kind of thing with the book's "buggy example" (figures 1.16 and 1.17-- I modified 1.17 so I could play with vectors).

I found that there was a problem. I made some IntCells, put them in a vector, copied it and wrote to the IntCell in vector[0]:
```
   IntCell x {1};
   IntCell y {2};
   IntCell z {3};
	 
   vector<IntCell> a { x,y,z };
   vector<IntCell> b (a.begin(),a.end());
   IntCell * c[3];
    
   a[0].write(9); // this demonstrates the shallow copy problem. changing the values of a changes the values of b
```
It makes sense that the values in the pointer array 'c' would change when a[0] is changed, because its a pointer, but I don't think it makes sense that the vector 'b' changes (this happens because the IntCell data member is a pointer!).

The rest of the program prints the contents of the array.

It looks like this:
```
first vector
9
2
3

second vector
9
2
3

third array
9
2
3
```

###bigFive
Then, I implemented IntCell differently-- using figure 1.18-- with the "big-five".

Running ```./bigFive``` looks like this:
```
first vector
9
2
3

second vector
1
2
3

third vector
9
2
3
```
Notice that the second vector's [0] IntCell's storedValue didn't change after we wrote to the first vector's [0] IntCell. The problem was (according to the book): "the default copy assignment operator and copy constructor copy the pointer storedValue."

The new IntCell class includes:
  * copy and move constructors
  * copy and move assignments
  * a destructor
  * and, storedValue is still a pointer
```
  ...
  private:
    int *storedValue;
  ...
``` 

###wFigureOneEighteen
In my quest to understand what was happening, I also wrote a little program that told me how many clicks a copy function took to copy the vectors and it walked me through what was happening throughout the program.

Running ```./oneEighteen``` looks like this:
```
***This is using IntCell example 1.18***

Original vector size: 99999

vector<IntCell>* newICell = &theIntCell
It took 2 clicks (0.000002 seconds) to do default ' = ' copy.

This is a shallow copy-- two variables are pointing to the same address,
which therefore hold the same values. But, if I delete one of them, 
the other is pointing to something that doesn't exist anymore. 

This can be a problem with shallow copying.

So, if I clear the copy with: 'newICell->clear();' then the original is cleared as well.

See:
	Original vector size: 0

But, if we do things differently... with a copy function like this: 

	 vector<IntCell> copyA(vector<IntCell> iC){
		vector<IntCell> n = iC;
		return n
	}

We pass in a VALUE and return a copy, but as another VALUE

It is less efficient to copy, but now this copy is independent of the old vector.


It took me 36927 clicks (0.036927 seconds) to do copyA.

Then we clear() the copy to see if this destroys the old vector.

See that this size is not 0: 

	Original vector size: 99999

Perfect.

Or what if we pass the vector to the function as a constant reference?
And return a constant reference?

like this: 

	vector<IntCell> copyB(const vector<IntCell> & iC){
		const vector<IntCell> & newA { iC };
		return newA;
	}

It took me 18481 clicks (0.018481 seconds) to do copyB. Faster.

And then, if we clear() this vector, the original should be unchanged.

Let's see:

	Original vector size: 99999


 		 the end 
```

##include
This is the work I did for exercise 1.4 in the book. I wasn't sure that I totally understood the question. But, this is what I did:

Main points:
 * I used c++ strings.
 * I wrote a recursive function -- getFromFile() -- that looks for lines in a file that contain "#include" and follows the name to collect the content on the other file.
 * getFromFile() opens included files until it finds 'end' as the filename to be included.
 * while it's opening and reading these files, it is also inserting filenames and content into vectors
 * after the function is done running through the files, it writes the contents of those 2 vectors to a new file and prints everything to the standard output.

Running the program looks like this:
```
stefo@ubuntu:~/CppStuff/firstAssignment/include$ ./include
1
2
3
end
this is the content of file 1
another line
this is content of file 2
this is content of file 3
```
##binary
This is the work I did for exercise 1.5. The user gives an int and gets the binary string representation and also the number of 1s in that string.

I made a recursive function ("findOnes()") that uses find() to find the first 1 in the string that is passed to it. It increments a counter ("onesCount") then it uses substr() to get rid of everything up to and including the 1 that was found. After that it calls itself using the substring.

The running program looks like this:
```
stefo@ubuntu:~/CppStuff/firstAssignment/binary$ ./binary
convert int to binary
Enter a number: 1
Binary: 00000000000000000000000000000001
Number of Ones: 1
Enter a number: 2
Binary: 00000000000000000000000000000010
Number of Ones: 1
Enter a number: 3
Binary: 00000000000000000000000000000011
Number of Ones: 2
Enter a number: 4
Binary: 00000000000000000000000000000100
Number of Ones: 1
Enter a number: 5
Binary: 00000000000000000000000000000101
Number of Ones: 2
```
