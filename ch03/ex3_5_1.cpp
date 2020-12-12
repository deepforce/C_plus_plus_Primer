#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;

int main()
{
    string str, concatenated;;
    while (cin >> str) {
        concatenated += str;
    };
    cout << concatenated << endl;
    return 0;
}