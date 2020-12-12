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
    if (str1.size() == str2.size())
        cout << "The two strings have the same length." << endl;
    else
        cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2 ) << endl;
    return 0;
}