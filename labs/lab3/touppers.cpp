// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

// Topic: Using a reference varaible
// 
// The C/C++ language do offer a function, `toupper()` to convert a character
// to an uppercase, but not for a word or a string. Write a function called 
// `touppers()` that converts a string to all uppercases in place where it 
// does not require extra memory. 
//  - Use a skeleton file, `touppers.cpp`, provided. 
//  - Use a reference variable and `toupper()`, but not functions in <algorithm>.
// 
// 2021/02/10   created by idebtor@gmail.com
// 
// Sample Run:
//  > g++ touppers.cpp -o touppers
//  > ./touppers
//  > Enter words: Hello Mr. Kim
//  > HELLO MR. KIM
//
#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////////////////
// Define touppers() here that converts an input arguments into all uppercases
void touppers(std::string& s) {
    for (std::size_t i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
}


///////////////////// your code above ////////////////////////////////////////
int main() {
    std::string str;
    std::cout << "Enter words: ";
    std::getline(std::cin, str);

    touppers(str);

    std::cout << str << std::endl;
}

