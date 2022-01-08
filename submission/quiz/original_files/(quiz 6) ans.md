On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.

서명: ___강동인_______ 학번: ____21500002___



```c++
int main() {
    queue q = newQueue();
    dequeue(q);			// fail
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);		// fail
    enqueue(q, 6);		// fail
    display(q);
    int elem = dequeue(q);
    if (elem != -1) cout << "dequeue: " << elem << endl;
    display(q);
    enqueue(q, 7);
    display(q);
    enqueue(q, 8);		// fail
    dequeue(q);
    dequeue(q);
    dequeue(q);
    return 0;
}
```



1.  failure 4 times
2. ![image-20220108230651966](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220108230651966.png) 