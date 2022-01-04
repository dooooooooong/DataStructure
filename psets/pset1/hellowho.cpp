// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    while (1) {
        cout << "Enter your name: ";
        getline(cin, str);
        if (str.length() > 0) cout << "Hello, " << str << ", Welcome to C+CC\n";
        else break;
    }

    cout << "Hello World!\n";

    return 0;
}