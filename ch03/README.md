# 第3章 字符串、向量和数组

## 练习3.1
> 使用恰当的using声明重做1.4.1节（第11页）和2.6.2节（第67页）的练习。

```cpp
// 1.4.1
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Enter two numbers:" << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << endl;
    return 0;
}
```

```cpp
// 2.6.2
#include <iostream>
#include <string>
#include "../ch02/include/ex2_42.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_data data1, data2;

    // code to read into data1 and data2
    double price = 0;  // price per book, used to calculate total revenue

    // read the first transactions: ISBN, number of books sold, price per book 
    cin >> data1.bookNo >> data1.units_sold >> price;
    // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price;

    // read the second transaction
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    // code to check whether data1 and data2 have the same ISBN
    //        and if so print the sum of data1 and data2
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print: ISBN, total sold, total revenue, average price per book
        cout << data1.bookNo << " " << totalCnt
            << " " << totalRevenue << " ";
        if (totalCnt != 0)
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;

        return 0;  // indicate success
    }
    else
    {  // transactions weren't for the same ISBN
        cerr << "Data must refer to the same ISBN" << endl;
        return -1; // indicate failure
    }
}
```

## 练习3.2
> 编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。

读入一行
```cpp
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
```
读入一个词
```cpp
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;

int main()
{
    string word;
    while(cin >> word) {
        cout << word << endl;
    }
    return 0;
}
```

## 练习3.3
> 请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

- 类似`is >> s`的读取：string对象会**忽略开头的空白**并从第一个真正的字符开始，直到遇见下一空白为止。
- 类似`getline(is, s)`的读取：string对象会从输入流中读取字符，直到遇见**换行符**为止。

## 练习3.4
> 编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

比较字符串相等
```cpp
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
```

比较等长
```cpp
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
```

## 练习3.5
> 编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。

连接字符串 (未隔开)
```cpp
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
```

连接字符串 (隔开)
```cpp
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
        concatenated += str + (str.empty() ? "" : " ");
    };
    cout << concatenated << endl;
    return 0;
}
```

## 练习3.6
> 编写一段程序，使用范围for语句将字符串内的所有字符用X代替。

```cpp
#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s = "this is a string";

    for (auto &x : s)
    {
        x = 'X';
    }
    cout << s << endl;
    return 0;
}
```

## 练习3.7
> 就上一题完成的程序而言，如果将循环控制变量的类型设为char将发生什么？先估计一下结果，然后实际编程进行验证。
如果设置为char，那么原来的字符串不会发生改变。

## 练习3.8
> 分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？
范围for循环更好，不用操作索引。
```cpp
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main()
{
    string str("a simple string");
    
    // while
    decltype(str.size()) i = 0;
    while (i < str.size()) str[i++] = 'X';
    cout << str << endl;

    // for
    for (i = 0; i < str.size(); str[i++] = 'Y');
    cout << str << endl;

    // I like range for.
    return 0;
}
```

## 练习3.9
> 下面的程序有何作用？它合法吗？如果不合法，为什么？

```cpp
string s;
cout << s[0] << endl;
```
不合法，使用下标访问空字符串是非法的行为。

## 练习3.10
> 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

```cpp
#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s = "this, is. a :string!";
	string result;

	for (auto x : s)
	{
		if (!ispunct(x))
		{
			result += x;
		}
	}
	
	cout << result << endl;
    return 0;
}
```

## 练习3.11
> 下面的范围for语句合法吗？如果合法，c的类型是什么？

```cpp
const string s = "Keep out!";
for(auto &c : s){ /* ... */ }
```

要根据for循环中的代码来看是否合法，c是string 对象中字符的引用，s是常量。因此如果for循环中的代码重新给c赋值就会非法，如果不改变c的值，那么合法。