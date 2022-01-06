#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Stack {
    vector <string> item;
};

using stack = Stack *;


void free (stack s) { 
    delete s; 
}

int size (stack s) { return s->item.size(); }
bool empty (stack s) { return s->item.empty(); }

void pop (stack s) { 
    s->item.pop_back();
}

string top (stack s) { return s->item.back(); }

void push (stack s, string item) {
    s->item.push_back(item);
    DPRINT(cout << "size:" << s->item.size() << " " << "capa:" << s->item.capacity() << endl;);
}


void printStack_recursion (stack s) {
    if (empty(s)) return;

    cout << top(s) << " ";
    pop(s);
    printStack_recursion(s);

}


int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = new Stack;
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
        }
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nThe stack is: "; printStack_recursion(s);
    cout << "\nHappy Coding\n";

    return 0;
}