# MicroSoft Visual Studio 사용경험 에세이



## 1. 코드 일괄 수정

Pset 혹은 lab을 할 때 이전 작성했던 코드를 복사해와서 사용할 때가 있습니다. 그대로 사용하는 경우도 있지만 대부분 수정하여 사용하는 경우가 많습니다. 

Stack을 예시로 들어보겠습니다.

```c++
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
```

위 코드는 stl을 사용하지 않고 stack2_arrT.cpp 에서 사용한 코드입니다. 



```c++
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
```

위 코드는 stl을 사용한 stack4_vectT.cpp에서 사용한 코드입니다.



묘하게 닮아 있지만 코드를 수정하려면 많은 시간이 걸립니다. 이럴 때 저는 코드의 뼈대를 분석하고 어느 부분이 바뀌었나 생각한뒤 `ctrl+d`라는 단축키를 이용하여 같은 부분을 일괄 선택하여 빠르게 수정합니다.

위 부분에서는 `s.top()` 과 `top(s)`를 비교하면 `(s)`부분을 일괄 선택하여 s를 지우고 앞부분에 s.를 붙인다면 시간이 꽤나 단축됩니다. 



## 2. 파일기록 되돌리기 및 git commit 

실수로 파일을 덮어쓰거나 지웠을 때 `ctrl + z`로 해결되지 않는 경우가 많습니다. 

만약 제가 visual code에서 작업하고 있었다면 왼쪽 소스제어 탭에가서 변경사항을 추적하고 되돌릴수 있습니다. 

![image-20220107041345324](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220107041345324.png)

또한 버튼하나로 빠르게 commit하고 push할 수도 있습니다.

![image-20220107041437727](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220107041437727.png)





## 3. Remote SSH code editor

SSH로 리눅스 서버에 접속해 코드를 수정할 때가 있습니다. 리눅스를 vi 혹은 vim으로 작업하기 때문에 익숙하지 않은 사람은 매우 불편하고 느립니다. (vim 숙련자의 경우라면 엄청나게 빠릅니다.) 저는 아직 숙련자까진 아니여서 visual code에서 제공하는 ssh remote editor를 사용하여 코드를 편리하게 편집합니다.



## 4. Visual Code Extension

Visual code는 자주사용하는 언어, 툴을 감지하여 Extension이라는 편리한 기능을 제공합니다. 코드 자동완성, 메소드 추천, 에러 표시 등 다양한 extension을 제공하고 저는 그 중 C/C++ IntelliSense, Python, Cmake등 다양한 Extension을 사용하고 있습니다.