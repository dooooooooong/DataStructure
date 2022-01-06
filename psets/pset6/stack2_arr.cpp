#include <string>
#include <iostream>

using namespace std;

struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free (stack s) { 
    delete[] s->item;
    delete s; 
}

int size (stack s) { return s->N; }
bool empty (stack s) { return s->N == 0; }
void pop (stack s) { s->N--; }
string top (stack s) { return s->item[s->N - 1]; }
void push (stack s, string item) { s->item[s->N++] = item; }


void printStack (stack s) {
    stack t = newStack(s->capacity);

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

void printStack_fromBottom (stack s) {
    stack t = newStack(s->capacity);

    while (!empty(s)) {
        push(t, top(s));
        pop(s);
    }

    while (!empty(t)) {
        cout << top(t) << ' ';
        push(s, top(t));
        pop(t);
    }

    free(t);
}


int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    int N = sizeof(list)/sizeof(string);

    stack s = newStack(N);
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
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);
    cout << "\nHappy Coding\n";

    return 0;
}