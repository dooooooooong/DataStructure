// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

#include <iostream>
#include <map>

using namespace std;

int main() {
    std::cout << "declare a map variable called table\n"; 
    std::map<std::string, int> table;


    std::cout << "initialize table using array[], insert(), pair<>, make_pair()\n"; 
    table["John"] = 21;
    table["Paul"] = 15;
    table.insert(std::pair <std::string, int>("Pete", 10));
    table.insert(std::make_pair("Adam", 11));


    std::cout << "print table using range-based for loop\n"; 
    for (auto i : table) {
        std::cout << "name: " << i.first << "\t";
        std::cout << " age: " << i.second << std::endl;
    }


    std::cout << "print table using iterator\n"; 
    for (auto iter = table.begin(); iter != table.end(); iter++) {
        std::cout << "name: " << iter->first << "\t";
        std::cout << " age: " << iter->second << std::endl;
    }


    std::cout << "define and initialize chart using pair<> and make_pair() only\n"; 
    std::map < char, int > chart {
        std::pair < char, int > ('A', 65),
        std::pair < char, int > ('C', 67),
        std::make_pair('D', 68),
        std::make_pair('B', 66)
    };

    std::cout << "print chart using range-based for loop\n"; 
    for (auto item : chart) {
        std::cout << "ascii: " << item.first << "\t";
        std::cout << " code: " << item.second << std::endl;
    }

    std::cout << chart['B'] << std::endl;

    return 0;
    
    return 0;
}
