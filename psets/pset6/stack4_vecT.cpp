#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct Stack {
    vector <T> item;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
void free (stack<T> s) { delete s; }

template <typename T>
int size (stack<T> s) { return s->item.size(); }

template <typename T>
bool empty (stack<T> s) { return s->item.empty(); }

template <typename T>
T top (stack<T> s) { return s->item.back(); }

template <typename T>
void pop (stack<T> s) { s->item.pop_back(); }

template <typename T>
void push (stack<T> s, T item) { s->item.push_back(item); }

template <typename T>
void printStack_recursion (stack<T> s) {
    if (empty(s)) return;

    cout << top(s) << " ";
    pop(s);
    printStack_recursion(s);

}

template <typename T>
void printStack_fromBottom_recursion (stack<T> s) {
    if (empty(s)) return;
   
    string str = top(s);
    pop(s);
    printStack_fromBottom_recursion(s);
    cout << str << " ";
}



int main() {
    int list1[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list2[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack <int> s1 = new Stack <int>();
    stack <string> s2 = new Stack <string>();

    cout << "\nInt Type Stack Example: ";
    for (auto item : list1) {
        if (item != 0) {
            push(s1, item);
        }
        else {
            cout << top(s1) << ' ';
            pop(s1);
        }
    }

    cout << "\nsize: " << size(s1);
    cout << "\ntop: " << top(s1);
    cout << "\nstack is: "; printStack_recursion(s1);
    cout << "\nHappy Coding\n";

    cout << "\nString Type Stack Example: ";
    for (auto item : list2) {
        if (item != "-") {
            push(s2, item);
        }
        else {
            cout << top(s2) << ' ';
            pop(s2);
        }
    }
    
    cout << "\nsize: " << size(s2);
    cout << "\ntop: " << top(s2);
    cout << "\nstack is: "; printStack_recursion(s2);
    cout << "\nHappy Coding\n";

    return 0;
}