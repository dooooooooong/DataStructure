// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

#include <iostream>
#include <sstream>

using namespace std;

int add (int a, int b) { return a + b; }
int mul (int a, int b) { return a * b; }
int sub (int a, int b) { return a - b; }
int dvd (int a, int b) { if (b != 0) return a / b; else return 0; }

int get_int() {
    int x;
    do {
        cout << "Enter an integer: ";
        string str;
        getline(cin, str);
        try {
            x = stoi(str);
            break;
        }
        catch (invalid_argument& e) {
            cerr << e.what() << " error occurred. Retry~" << endl;
        }
    } while (true);

    return x;
}

pair <char, int> get_op(string opstr) {
    char op;
    size_t x;

    do {
        stringstream ss;
        string str;
        cout << "Enter an operator(" << opstr << "): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        x = opstr.find(op);                             // find index of op in opstr
    } while (opstr.find(op) == string::npos);           // while op is not found in opstr
    return make_pair(op, x);                            // returns an operator and its index
}

int main() {
    int (*funptr[4])(int a, int b) = { add, sub, mul, dvd }; // array of function pointers 

    string opstr {"+-*/"};

    int a { get_int() };
    pair <char, int> op { get_op(opstr) };
    int b { get_int() };

    cout << a << " " << op.first << " " << b << " = " << funptr[op.second](a, b) << endl;
    return 0;


}