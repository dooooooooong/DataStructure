#include <stack>
#include <string>
#include <iostream>

using namespace std;

void printStack (stack<string> s) {
    stack<string> t;

    while (!empty(s)) {
        cout << s.top() << ' ';
        t.push(s.top());
        s.pop();
    }

    while (!t.empty()) {
        s.push(t.top());
        t.pop();
    }
}

void printStack_recursion (stack<string> s) {
    if (s.empty()) return;

    cout << s.top() << " ";
    s.pop();
    printStack_recursion(s);

}

void printStack_fromBottom (stack<string> s) {
    stack<string> t;

    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }

    while (!t.empty()) {
        cout << t.top() << ' ';
        s.push( t.top());
        t.pop();
    }
}

void printStack_fromBottom_recursion (stack<string> s) {
    if (s.empty()) return;
   
    string str = s.top();
    s.pop();
    printStack_fromBottom_recursion(s);
    cout << str << " ";
}

int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack <string> s;
    for (auto item : list) {
        if (item != "-") {
            s.push(item);
        }
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize: " << s.size();
    cout << "\ntop: " << s.top();
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);
    cout << "\nHappy Coding\n";

    return 0;
}