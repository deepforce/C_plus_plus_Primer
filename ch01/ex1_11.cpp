#include <iostream>

int main() {
    int start = 0, end = 0;
    std::cout << "Please input two num as range: ";
    std::cin >> start >> end;
    while (start <= end) {
        std::cout << start << " ";
        start++;
    }
    std::cout << std::endl;
    return 0;
}