# 第2章 变量和基本类型
## 练习2.1
> 类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

C++ 规定 short 和 int 至少16位，long 至少32位，long long 至少64位。 带符号类型能够表示正数、负数和 0 ，而无符号类型只能够表示 0 和正整数。

C和C++标准没有指定float、double和long double的表示形式。这三种方法都有可能实现IEEE双精度。然而，对于大多数架构(gcc, MSVC; x86, x64, ARM)浮点数实际上是IEEE单精度浮点数(binary32)， double是IEEE双精度浮点数(binary64)。

## 练习2.2
> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

使用double或者float。需要进行浮点计算。

## 练习2.3
> 读程序写结果。
> ```cpp
> unsigned u = 10, u2 = 42;
> std::cout << u2 - u << std::endl;  
> std::cout << u - u2 << std::endl;  
> int i = 10, i2 = 42;  
> std::cout << i2 - i << std::endl;  
> std::cout << i - i2 << std::endl;  
> std::cout << i - u << std::endl;  
> std::cout << u - i << std::endl;  
> ```
输出：
> 32  
> 4294967264  
> 32  
> -32  
> 0  
> 0  

## 练习2.4
> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

## 练习2.5
> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：  
> (a) 'a', L'a', "a", L"a"  
> (b) 10, 10u, 10L, 10uL, 012, 0xC  
> (c) 3.14, 3.14f, 3.14L  
> (d) 10, 10u, 10., 10e-2  
- (a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。
- (b): 十进制整型，十进制无符号整型，十进制长整型，十进制无符号长整型，八进制整型，十六进制整型。
- (c): double, float, long double
- (d): 十进制整型，十进制无符号整型，double, double

## 练习2.6
> 下面两组定义是否有区别，如果有，请叙述之：
> int month = 9, day = 7;  
> int month = 09, day = 07;  

第一行是十进制整型，第二行是八进制整型。但是month有错误，八进制不能为9。

## 练习2.7
> 下述字面值表示何种含义？它们各自的数据类型是什么？ 
> (a) "Who goes with F\145rgus?\012"  
> (b) 3.14e1L  
> (c) 1024f  
> (d) 3.14L  

- (a) Who goes with Fergus? (换行), 字符串类型。
- (b) 31.4, long double
- (c) 无效，因为后缀f只能用于浮点字面量，而1024是整型。
- (d) 3.14, long double

## 练习2.8
> 请利用转义序列编写一段程序，要求先输出2M，然后转到新一行。修改程序使其先输出2，然后输出制表符，再输出M，最后转到新一行。
```cpp
#include <iostream>
int main()
{

    std::cout << 2 << "\x4d\012";
    std::cout << 2 << "\t\x4d\012";
    return 0;
}
```

## 练习2.9
> 解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。
> - (a) std::cin >> int input_value;
> - (b) int i = { 3.14 };
> - (c) double salary = wage = 9999.99;
> - (d) int i = 3.14;

(a): 应该先定义再使用。
```cpp
int input_value = 0;
std::cin >> input_value;
```
(b): 用列表初始化内置类型变量时，如果存在丢失的风险，则编译器将报错。
```cpp
double i = { 3.14 };
```
(c): 在这里`wage`是未定义的，应该在此之前将其定义。
```cpp
double wage;
double salary = wage = 9999.99;
```
(d): 不报错，但是小数部分会被截断。
```cpp
double i = 3.14;
```

## 练习2.10
> 下列变量的初值分别是什么？
> ```cpp
> std::string global_str;  
> int global_int;  
> int main()  
> {
>     int local_int;
>     std::string local_str;
> }
> ```

`global_str`和`global_int`是全局变量，所以初值分别为空字符串和0。  
`local_int`是局部变量并且没有初始化，它的初值是未定义的。 `local_str` 是 string 类的对象，它的值由类确定，为空字符串。

## 练习2.11
> 指出下面的语句是声明还是定义：
> - (a) extern int ix = 1024;
> - (b) int iy;
> - (c) extern int iz;

(a): 定义
(b): 定义
(C): 声明

## 练习2.12
> 请指出下面的名字中哪些是非法的？
> - (a) int double = 3.14;
> - (b) int _;
> - (c) int catch-22;
> - (d) int 1_or_2 = 1;
> - (e) double Double = 3.14;

(a), (c), (d) 非法。

## 练习2.13
> 下面程序中j的值是多少？
> ```cpp
> int i = 42;
> int main()
> {
>    int i = 100;
>    int j = i;
> }
> ```

j的值是100。

## 练习2.14
> 下面的程序合法吗？如果合法，它将输出什么？
> ```cpp
> int i = 100, sum = 0;
> for (int i = 0; i != 10; ++i)
>     sum += i;
> std::cout << i << " " << sum << std::endl;
> ```

合法。输出100 45。


