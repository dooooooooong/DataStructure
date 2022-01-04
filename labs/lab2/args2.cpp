// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include <iostream>
#include <string>
#include <vector>
#include "printfunc.h"


int main(int argc, char **argv) {

	std::cout << "Print **argv using printfunc(**argv) except 1st one\n";
	printfunc(argc, argv);
	
	
	// copy **argv to a `vector<string> names;` except 1st one. 
	// use push_back() method in the vector class
	std::cout << "Copy **argv using vector<string> except 1st one\n";
	std::vector <std::string> names;

	for (int i = 1; i < argc; i++) {
		names.push_back(argv[i]);
	}

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	std::cout << "Print names using for-loop, but not argc/argv, ranged-for\n";
	printfunc(names);

	// print names using printfunc(vector<string>)
	// use ranged-for loop in printfunc(vector<string>)
	// do not use `using namespace std;` in printfunc.cpp 
	// cout << "Print names using printfunc(vector<string>)\n";
	// printfunc(names);

	return 0;
}
