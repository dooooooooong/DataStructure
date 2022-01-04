// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
#include <string>

void printfunc(int n, char *names[]) {
	for (int i = 1; i < n; i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

void printfunc(std::vector <std::string> names) {
	for (auto name : names) {
		std::cout << "Hello " << name << "!" << std::endl;
	}
}