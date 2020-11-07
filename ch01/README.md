# 第1章 开始
## 练习1.1
> 查阅你使用的编译器的文档，确定它所使用的文件名约定。编译并运行第2页的main程序。
 * [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions) 
 * [File Types Created for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

## 练习1.2
> 改写程序，让它返回-1。返回值-1通常被当做程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。
### Unix
状态返回255? 原因是[这个](https://tldp.org/LDP/abs/html/exitcodes.html)。

## 练习1.3
> 编写程序，在标准输出上打印Hello，World。
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## 练习1.4
> 我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符＊，来打印两个数的积。
```cpp
#include <iostream>

int main() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```

## 练习1.5
> 我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

## 练习1.6
> 解释下面程序片段是否合法。
> ```cpp
> std::cout << "The sum of " << v1;
>           << " and " << v2;
>           << " is " << v1 + v2 << std::endl;
> ```
不合法。第二行多了个分号。修正：将分号去掉。

## 练习1.7
> 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息

如下：
```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}
```
错误信息：
![](../ch01/imgs/ex1_7.png)

## 练习1.8
> 指出下列哪些输出语句是合法的（如果有的话）：
> ```cpp
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /* "*/" /* "/*" */;
> ```
> 预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案（编写一个小程序，每次将上述一条语句作为其主体），改正每个编译错误。

只有第三行是错的。改成如下：
```cpp
std::cout << /* "*/" */";
```