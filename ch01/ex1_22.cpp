#include <iostream>
#include "include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item sum;
    if (cin >> sum) {
        Sales_item temp;
        while (cin >> temp) {
            if (sum.isbn() == temp.isbn()) {
                sum += temp;
            } else {
                cout << sum << endl;
                sum = temp;
            }
        }
        cout << sum << endl;
    } else {
        std::cerr << "No data" << endl;
        return -1;
    }
    return 0;
}