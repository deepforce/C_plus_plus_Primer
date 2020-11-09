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

## 练习2.15
> 下面的哪个定义是不合法的？为什么？
> - (a) int val = 1.01;
> - (b) int &rval1 = 1.01;
> - (c) int &rval2 = ival;
> - (d) int &rval3;

(b)和(d)不合法，(b)引用必须绑定在对象上，(d)引用必须初始化。

## 练习2.16
> 考查下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操作？
> ```cpp
> int i = 0, &r1 = i; 
> double d = 0, &r2 = d;
> ```
> - (a) r2 = 3.14159;
> - (b) r2 = r1;
> - (c) i = r2;
> - (d) r1 = d;


- (a): 合法。会给d赋值3.14159。
- (b): 合法。会给d赋值并执行自动转换（int -> double）。
- (c): 合法。会发生小数截取。
- (d): 合法。会发生小数截取。

## 练习2.17
> 执行下面的代码段将输出什么结果？
> ```cpp
> int i, &ri = i;
> i = 5; ri = 10;
> std::cout << i << " " << ri << std::endl;
> ```

输出`10 10`。

## 练习2.18
> 编写代码分别更改指针的值以及指针所指对象的值。

```cpp
#include <iostream>

int main() 
{
    int a = 0, b = 1;
    int *p1 = &a, *p2 = p1;

    // change the value of a pointer.
    p1 = &b;
    // change the value to which the pointer points
    *p2 = b;
}
```

## 练习2.19
> 说明指针和引用的主要区别。

引用是另一个对象的别名，而指针本身就是一个对象。 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

## 练习2.20
> 请叙述下面这段代码的作用。
> ```cpp
> int i = 42;
> int *p1 = &i;
> *p1 = *p1 * *p1;
> ```

让指针p1指向i，然后将i的值重新赋值为42 * 42。

## 练习2.21
> 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？  
> `int i = 0;`
> - (a) double* dp = &i;
> - (b) int *ip = i;
> - (c) int *p = &i;

(a) 非法。指针类型不一致。
(b) 非法。不能将变量本身赋值给指针。
(c) 合法。

## 练习2.22
> 假设p是一个int型指针，请说明下述代码的含义。
> if (p) // ...
> if (*p) // ...

第一句判断 p 是不是一个空指针。  
第二句判断 p 所指向的对象的值是不是为0。

## 练习2.23
> 给定指针p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能。因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。

## 练习2.24
> 在下面这段代码中为什么p合法而lp非法？
> ```cpp
> int i = 42;
> void *p = &i;
> long *lp = &i;
> ```

因为p是`void*`指针，`void*`指针可以指向任何类型的对象。 而lp是`long`指针，只能指向long类型的对象。

## 练习2.25
> 说明下列变量的类型和值。
> - (a) int* ip, i, &r = i;
> - (b) int i, *ip = 0;
> - (c) int* ip, ip2;

(a): ip是指向int的指针，i是一个int，r是i的引用。  
(b): i是一个int，ip是一个空指针。
(c): ip是一个指向int的指针，ip2是一个int。

## 练习2.26
> 下面哪些句子是合法的？如果有不合法的句子，请说明为什么？
> - (a) const int buf;      
> - (b) int cnt = 0;        
> - (c) const int sz = cnt; 
> - (d) ++cnt; 
> - (e) ++sz;

(a) 不合法, const 对象必须初始化。  
(b) 合法。  
(c) 合法。  
(d) 合法。
(d) 不合法。 const对象无法被修改。

## 练习2.27
> 下面的哪些初始化是合法的？请说明原因。
> - (a) int i = -1, &r = 0;
> - (b) int *const p2 = &i2;        
> - (c) const int i = -1, &r = 0;   
> - (d) const int *const p3 = &i2;  
> - (e) const int *p1 = &i2;        
> - (f) const int &const r2;        
> - (g) const int i2 = i, &r = i;   

(a) 不合法。r必须引用一个对象。  
(b) 合法。  
(c) 合法。  
(d) 合法。  
(e) 合法。   
(f) 不合法。 r2是引用，引用没有顶层const。  
(g) 合法。

## 练习2.28
> 说明下面的这些定义是什么意思，挑出其中不合法的。
> - (a) int i, *const cp;   
> - (b) int *p1, *const p2;     
> - (c) const int ic, &r = ic;  
> - (d) const int *const p3;  
> - (e) const int *p;

(a) 不合法。 const指针必须初始化。  
(b) 不合法。 const指针必须初始化。  
(c) 不合法。 const int 必须初始化。  
(d) 不合法。 const 指针必须初始化。  
(e) 合法。一个指向const int的指针。

## 练习2.29
> 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
> - (a) i = ic;
> - (b) p1 = p3;
> - (c) p1 = &ic;
> - (d) p3 = &ic;
> - (e) p2 = p1;
> - (f) ic = *p3;

(a) 合法，常量赋值给普通变量。  
(b) 不合法，p3是const指针不能赋值给普通指针。  
(c) 不合法，普通指针不可以指向常量。  
(d) 不合法，p3是指向常量的const指针，不可改变。  
(e) 不合法， p2是const指针,不可改变。  
(f) 不合法， ic是常量，不可改变。  

## 练习2.30
> 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
> ```cpp
> const int v2 = 0; int v1 = v2;
> int *p1 = &v1, &r1 = v1;
> const int *p2 = &v2, *const p3 = &i, &r2 = v2;
> ```

v2是顶层const，p2是底层const， p3是底层const又是顶层const，r2是底层const。

## 练习2.31
> 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
> ```cpp
> r1 = v2; // 合法, 顶层const在拷贝时不受影响
> p1 = p2; // 不合法, p2 是底层const，如果要拷贝必须要求 p1 也是底层const
> p2 = p1; // 合法, int* 可以转换成const int*
> p1 = p3; // 不合法, p3 是一个底层const，p1 不是
> p2 = p3; // 合法, p2 和 p3 都是底层const，拷贝时忽略掉顶层const
> ```

## 练习2.32
> 下面的代码是否合法？如果非法，请设法将其修改正确。
> ```cpp
> int null = 0, *p = null;
> ```

不合法。修改如下：
```cpp
int null = 0, *p = &null;
int null = 0, *p = nullptr;
```

