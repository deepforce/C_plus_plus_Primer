#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 == str2)
        cout << "The two strings are equal." << endl;
    else
        cout << "The larger string is " << ((str1 > str2) ? str1 : str2) << endl;
    return 0;
}