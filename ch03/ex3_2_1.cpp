#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;

int main()
{
    string line;
    while(getline(cin, line)) {
        cout << line << endl;
    }
    return 0;
}