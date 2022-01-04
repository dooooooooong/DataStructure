// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

#include <iostream>

long long unsigned factorial(int n) {
  if (n == 1 || n == 0) return n;
  auto result = n * factorial(n - 1);
  return result;
}

int main() {
    int n[] = {1, 2, 3, 4, 5, 8, 12, 20};
    for (auto x: n)
    std::cout << "factorial(" << x << ") = " << factorial(x) << std::endl;
    return 0;
}