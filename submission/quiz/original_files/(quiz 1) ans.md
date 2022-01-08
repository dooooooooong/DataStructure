On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.

서명: ___강동인_______ 학번: ____21500002___



1. What kind of error?

```c++
int main() {
    int *pi;
    *pi = 17;
    std::cout << "i =" << *pi << std::endl;
    return 0;
}
```

1. link error
2. <span style="color:red">run-time error</span>
3. syntax error
4. a logic error





2. Fix the above code

```c++
#include <iostream>
using namespace std;


// 1. adding two line
#if 1
int main() {
    int a;
    int *pi;
    pi = &a;
    *pi = 17;
    cout << "i = " << *pi << endl;
    return 0;
}

// 2. using new and delete
#else

int main() {
    int *pi;
    pi = new int;
    *pi = 17;
    cout << "i = " << *pi << endl;
    delete pi; 
    return 0;
}

#endif
```

