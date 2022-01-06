 // On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Stack {
    T *item;
    int N;
    int capacity;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
stack<T> newStack(int capacity) {
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template <typename T>
void free (stack<T> s) { 
    delete[] s->item;
    delete s; 
}

template <typename T>
int size (stack<T> s) { return s->N; }

template <typename T>
bool empty (stack<T> s) { return s->N == 0; }

template <typename T>
void pop (stack<T> s) { s->N--; }

template <typename T>
T top (stack<T> s) { return s->item[s->N - 1]; }

template <typename T>
void push (stack<T> s, T item) { s->item[s->N++] = item; }

template <typename T>
void printStack (stack<T> s) {
    stack<T> t = newStack(s->capacity);

    while (!empty(s)) {
        cout << top(s) << ' ';
        push(t, top(s));
        pop(s);
    }

    while (!empty(t)) {
        push(s, top(t));
        pop(t);
    }

    free(t);
}

template <typename T>
void printStack_recursion (stack<T> s) {
    if (empty(s)) return;

    cout << top(s) << " ";
    pop(s);
    printStack_recursion(s);

}


int main() {
    int list1[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list2[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    int sizeInt = sizeof(list1) / sizeof(int);
    int sizeString = sizeof(list2) / sizeof(string);

    stack <int> s1 = newStack <int>(sizeInt);
    stack <string> s2 = newStack <string> (sizeString);

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