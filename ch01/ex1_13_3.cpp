#include <iostream>

int main() {
    int start = 0, end = 0;
    std::cout << "Please input two num as range: ";
    std::cin >> start >> end;
    for (;start<=end;start++) {
        std::cout << start << " ";
    }
    std::cout << std::endl;
    return 0;
}