原文链接：[Bit Twiddling Hacks](http://graphics.stanford.edu/~seander/bithacks.html)

Bit Twiddling Hacks
===================

```
原文名：Bit Twiddling Hacks
作者：Sean Eron Anderson, seander@cs.stanford.edu
翻译：plusplus7
```

本文的收集整理工作由Sean Eron Anderson在1997-2005年完成，除非有特别注明，本文所包含的代码片段不受著作权法的限制，任何人可以自由使用。希望这篇文章以及这些代码能帮助到读者，但是在使用这些代码时，请注意：这些代码不提供任何担保。截止到2005年5月5日，很多人阅读过本文，而这些代码也已经被完整地测试过了。除此之外，卡内基梅隆大学计算机科学学院院长Randal Bryant教授使用他的Uclid代码检验系统亲自为大部分代码进行了测试。对于其他没有被测试覆盖到的部分，我在我的32位计算机上测试了所有可行的输入。对于第一个在代码中发现一个合理bug的人，我愿意悬赏10美刀（支票或者Paypal）。如果发现者有意将赏金捐献给慈善机构，那么我愿意支付20美刀。

###目录
* [关于运算次数的统计方法](#关于运算次数的统计方法)
* [计算整数的符号](#计算整数的符号)

###关于运算次数的统计方法

当讨论到计算某个算法的运算次数时，任何一个C语言的运算符都会被统计为一次运算。中间变量的赋值，即不需要写入到内存中的赋值操作，不会被统计在内。当然，这种统计方法只能得到综合机器指令和CPU时间的一个近似值。影响一段程序在系统中的运行时间的因素非常多，比如缓存大小，内存带宽，不同的指令集等等。所有运算消耗的时间相同在现实中是不成立的，但是CPU技术随着时间的推移，正在往这个方向飞速发展。总的来说，想要判断一种方法比另一种方法更快，最好的方式是直接到你的目标机器上去跑基准测试，测试性能的优异。

###计算整数的符号


```c
int v;      // we want to find the sign of v
            // 我们希望得出v的符号（正负）
int sign;   // the result goes here 
            // 结果保留在这个变量里

// CHAR_BIT is the number of bits per byte (normally 8).
// 常量CHAR_BIT指是一个比特里包含多少位（通常情况下是8位）
sign = -(v < 0);  // if v < 0 then -1, else 0. 
// or, to avoid branching on CPUs with flag registers (IA32):
// 或者，为了防止在使用flag registers的CPU(IA32架构上)上出现分支指令
sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
// or, for one less instruction (but not portable):
// 或者，牺牲移植性来减少一个指令
sign = v >> (sizeof(int) * CHAR_BIT - 1); 

```

（译者注: [关于这段代码为何能够防止出现分支指令的讨论](http://stackoverflow.com/questions/25623721/why-does-this-method-of-computing-the-sign-of-an-integer-avoids-branching-on-cpu)）

对于32位整型数来说，上面的最后一条语句会计算sign=v>>31。这样的方式比sign=-(v<0)这种直接的方式更快一次运算左右。由于右移时，最左端的符号位会被填充到多出来的位中，所以在这个技巧（指v>>31）能够工作。如果最左端的符号位是1，那么结果就是-1，否则就是0；因为右移时，负数的所有位都会被填充为1，而二进制位全1正好是是-1的补码。不过不幸的是，这个操作是依赖底层实现的（所以是说牺牲了移植性）。

（译者注：[关于右移操作自动填充符号位的讨论](http://stackoverflow.com/questions/141525/what-are-bitwise-shift-bit-shift-operators-and-how-do-they-work)）

也许你可能更喜欢，对于正数返回1，对于负数返回-1，那么有：
```c
sign = +1 | (v >> (sizeof(int) * CHAR_BIT - 1));  // if v < 0 then -1, else +1
```

更或者，还有对于负数零正数而返回-1, 0, 1的方案，那么有：

```c
sign = (v != 0) | -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
// Or, for more speed but less portability:
// 或者，牺牲移植性来提升速度
sign = (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1));  // -1, 0, or +1
// Or, for portability, brevity, and (perhaps) speed:
// 或者，更易移植，更加简洁，或者(有可能)更快的方案
sign = (v > 0) - (v < 0); // -1, 0, or +1
```

反之，如果你希望对于负数返回0，非负数返回+1，那么有：
```c
sign = 1 ^ ((unsigned int)v >> (sizeof(int) * CHAR_BIT - 1)); // if v < 0 then 0, else 1
```

附加说明：

2003年3月7日，Augus Duggan指出1989 ANSI C标准指明带符号数右移的结构是由编译器实现时定义(implementation-defined)的，所以这个技巧有可能不会正常工作。

2005年9月28日，Toby Speight为了提高移植性，他提议实用CHAR_BIT常量表示比特的长度，而不是简单地假设比特长度是8位。

2006年3月4日，Augus提出了几种更具移植性的代码版本，包括类型转换。

2009年9月12日，[Rohit Gary](http://rpg-314.blogspot.com/)提出了集中支持非负数的代码版本。
