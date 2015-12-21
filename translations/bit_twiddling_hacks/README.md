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

The last expression above evaluates to sign = v >> 31 for 32-bit integers. This is one operation faster than the obvious way, sign = -(v < 0). This trick works because when signed integers are shifted right, the value of the far left bit is copied to the other bits. The far left bit is 1 when the value is negative and 0 otherwise; all 1 bits gives -1. Unfortunately, this behavior is architecture-specific.

待续。
