// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
// 
// selection sort 
// The selection sort improves on the bubble sort by making only one exchange 
// for every pass through the list. In order to do this, a selection sort 
// looks for the largest value as it makes a pass and, after completing the 
// pass, places it in the proper location. As with a bubble sort, after the 
// first pass, the largest item is in the correct place. After the second pass, 
// the next largest is in place. This process continues and requires n−1 passes 
// to sort n items, since the final item must be in place after the (n−1)st pass.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 selection.cpp -o selection
// > ./selection
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp -o selection
// > ./selection
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c selection.cpp      # produce selection.o
// > ar r libsort.a selection.o           # insert or update selection.o in libsort.a
// > ar t libsort.a                       # show objects in libsort.a 
//
/******************************************************************************
  Lab05 - Understanding a better coding in C/C++
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - Use new and delete instead of malloc(), free()
  - Use assert() after new to check the memory allocation status
  - rand() and mod operator % 
  - Learn about a better coding after all.
*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <cstdlib>

using namespace std;

void selectionsort(int *list, int n, bool (*comp)(int, int)) {
  for (int i = 0; i < n; i++) {   
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (comp(list[j], list[min])) min = j;
    int temp = list[i];
    list[i] = list[min];
    list[min] = temp;
  }
}

#if 1

bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

void printlist(int *list, int N, int show_n = 20, int per_line = 10);
void selectionsort(int *list, int n, bool (*comp)(int, int) = ::less);

int main(int argc, char *argv[]) {

  int n = 0;

  while (n <= 1) {
    cout << "Enter a number of samples to sort(q to quit): ";
    string s;
    cin >> s;

    if (s == "q" || s == "quit") break;

    int flag = 0;
    for (auto c : s) {
      if (!isdigit(c)) {
        flag = 1;
        break;
      }
    }

    if (flag) {
      cout << "Retry - \n";
      continue;
    }

    n = stoi(s);

  }

  int *list = new (nothrow) int[n];
  assert(list != nullptr);

  srand(time(nullptr));
  for (int i = 0; i < n; i++) 
    list[i] = rand() % (n+1);
  

  // use printlist() to show the list initialized
  cout << "UNSORTED(" << n << "): \n";
  printlist(list, n);

  // ascending order 
  selectionsort(list, n);
  cout << "SORTED(" << n << "): \n";
  printlist(list, n);

  selectionsort(list, n, more);
  cout << "SORTED(" << n << "): descending using fp\n";
  printlist(list, n);


  delete[] list;

  cout << "Happy Coding~~\n";
  return 0;
}
#endif 
