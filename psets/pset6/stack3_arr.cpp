#include <string>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 1) {
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

void pop (stack s) { 
    // DPRINT(cout << "size = " << s->N << ", " << "capacity = " << s->capacity << endl;);
    if (s->N * 2 <= s->capacity) {
        string *newItems = new string[s->capacity / 2];
        copy(s->item, s->item + s->N, newItems);
        delete[] s->item;

        s->item = newItems;
        s->capacity /= 2;  
    }
    s->N--; 
}


string top (stack s) { return s->item[s->N - 1]; }

void push (stack s, string item) {
    if (s->N >= s->capacity) {
        string *newItems = new string[s->capacity * 2];
        copy(s->item, s->item + s->N, newItems);
        delete[] s->item;

        s->item = newItems;
        s->capacity *= 2;
        
    }

    s->item[s->N++] = item;
    DPRINT(cout << "size:" << s->N << " " << "capa:" << s->capacity << endl;);
    
}

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

void printStack_recursion (stack s) {
    if (empty(s)) return;

    cout << top(s) << " ";
    pop(s);
    printStack_recursion(s);

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

void printStack_fromBottom_recursion (stack s) {
    if (empty(s)) return;
   
    string str = top(s);
    pop(s);
    printStack_fromBottom_recursion(s);
    cout << str << " ";
}


int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = newStack();
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