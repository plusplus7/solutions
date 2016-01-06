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
* [判断两整数符号是否相反](#判断两整数符号是否相反)
* [计算整数的绝对值(不使用分支指令)](#计算整数的绝对值(不使用分支指令))
* [计算两个整数之间的最大值和最小值(不使用分支指令)](#计算两个整数之间的最大值和最小值(不使用分支指令))
* [判断某个整数是不是2的次幂](#判断某个整数是不是2的次幂)
* [符号扩展(固定位长)](#符号扩展(固定位长))

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

###判断两整数符号是否相反

```c
int x, y;               // input values to compare signs
                        // 输入的数值放在变量x和y中，用于比较符号
bool f = ((x ^ y) < 0); // true iff x and y have opposite signs
                        // 当且仅当(iff) x和y的符号相反时返回true
```

2009年11月26日，Manfred Weis建议我加入这一条内容。

### 计算整数的绝对值(不使用分支指令)
```c
int v;           // we want to find the absolute value of v
                 // 我们希望算出变量v的绝对值
unsigned int r;  // the result goes here
                 // 答案保存在这里
int const mask = v >> sizeof(int) * CHAR_BIT - 1;

r = (v + mask) ^ mask;
```

一个简单的变形:

```c
r = (v ^ mask) - mask;
```

有些CPU并不支持计算整数绝对值的指令（也可以说有些编译器没能用上这些指令）。在有的机器上，分支判断操作非常昂贵，会消耗较多计算资源。在这些机器上，上面的表达式会比 r = (v < 0) ? -(unsigned)v : v 这种简单的实现更快一些，尽管他们的操作数都是相同的。

2003年3月7日，Augus Duggan指出1989 ANSI C标准指明带符号数右移的结构是由编译器实现时定义(implementation-defined)的，所以这个技巧有可能不会正常工作。同时，我也阅读了ANSI C标准，发现ANSI C并没有要求数值一定要以二补数（two's complement，即补码）的形式表示出来，所以由于这个原因，上面的技巧（在一些极少部分仍使用一补数（one's complement）的古董机器上）也有可能不工作。

2004年3月14日，Keith H. Duggar提出了上面的变形。这个版本比我一开始想出来的初始版本更好，r=(+1|(v>>(sizeof(int)\*CHAR_BIT-1)))\*v，其中有一次乘法是没用的。

不幸的是，2000年6月6日，这个技巧已经被Vladimir Yu Volkonsky在美国申请了专利，并且归属于[Sun公司的Microsystems](http://www.sun.com/)。
2006年8月13日，Yuriy Kaminskiy告诉我这个专利可能是无效的，因为这个技巧在申请专利之前就被人公开发表了，见1996年11月9日，由Agner Fog发表的[How to Optimize for the Pentium Processor](http://www.goof.com/pcg/doc/pentopt.txt)。Yuriy同时也提到这份文档在1997年被翻译成了俄语，所以Vladimir有可能阅读过。除此之外，The Internet Archive（网站时光倒流机器）网站也收录了这个老旧的链接。

2007年1月30日，Peter Kankowski给我分享了一个他的[发现](http://www.strchr.com/optimized_abs_function)。这来源于他在观察微软的Visual C++编译器的输出时的发现。这个技巧在这里被采用为最优解法。

(译者注，Peter发现了VC++的编译器有可能使用了之前那个被Sun公司专利保护的技巧，但在评论中也同时有人指出Sun公司的这个专利是无效的)

2007年12月6日，Hai Jin提出反对意见，算法的结果是带符号的，所以在计算最大的负数时，结果会依然是负的。

2008年4月15日，Andrew Shapira指出上面的那个简单实现的版本可能会溢出，需要一个(unsigned)来做强制类型转换；为了最大程度的兼容性，他提议使用(v < 0) ? (1 + ((unsigned)(-1-v))) : (unsigned)v。但是根据2008年7月9日的ISO C99标准，Vincent Lefèvre说服我删除了这个版本，因为即便是在非基于二补数的机器上，-(unsigned)v这条语句也会做我们希望他做的事情。在计算-(signed)v时，程序会通过将负数v增加2\*\*N来得到无符号类型的数，这个数正好是v的补码表示形式，我们令U等于这个数。然后将U的符号取负，就能得出结果，有-U=0-U=2\*\*N-U=2\*\*N-(v+2\*\*N)=-v=abs(v)。

### 计算两个整数之间的最大值和最小值(不使用分支指令)

```c
int x;  // we want to find the minimum of x and y
int y;
        // 我们希望找出x和y之间的最小值
int r;  // the result goes here
        // 结果保存到变量r
r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
```

这个技巧能工作的原因是当x<y, 那么-(x<y)数值的二进制补码会是全1（-1的补码是全1），所以r = y ^ (x ^ y) & ~0 = y ^ x ^ y = x。反之，如果x>=y，那么-(x<y)会是全0，所以r = y ^ ((x ^ y) & 0) = y。在有些分支操作非常昂贵的机器，和没有提供条件跳转指令(condition move instructions)的机器上，上面的技巧会比这种常见的写法更快一些，r = (x < y) ? x : y，尽管这种常见的写法只使用了两三个指令。（虽然通常来讲，这种简单实现是最好的）。需要注意的是，在有的机器上，计算x<y的值也需要使用分支指令，所以这个时候这个技巧对比普通的实现也没有任何优势。

如果需要计算最大值，那么有

```c
r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
```

更快，更炫酷(dirty)的版本：

如果事先约定INT_MIN <= x - y <= INT_MAX，那么你就可以使用以下技巧。由于(x-y)只需要计算一次，所以这个版本会更快一些。

```c
r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // min(x, y)
r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // max(x, y)
```

注意，1989年的ANSI C标准并没有指明带符号类型变量的右移行为，所以这个版本不具备兼容性。如果计算时由于溢出而导致抛出异常，x和y的值都应该是无符号型的或者被强制转换成无符号型的，来避免由于减法而导致不必要地抛出异常。然而，当进行右移操作是需要用强制类型转换，将数值转换成带符号的，这样才能根据数值的正负来产生全0和全1。

2003年3月7日，Angus Duggan指出了右移操作的兼容性问题。
2005年5月3日，Randal E.Bryant提示我只有在INT_MIN <= x - y <= INT_MAX的先决条件下，那个炫酷版本的代码才算完善，并且他还提出了之前那个较朴实的解法。这些问题都需要在炫酷版本的代码中考虑到。
2005年7月6日，Nigel Horspoon注意到gcc在一款奔腾处理器上编译这份代码时，由于其计算(x-y)的方式，而产生了和之前的简单写法相同的代码。
2008年7月9日，Vincent Lefèvre指出上一个版本中，即r = y + ((x - y) & -(x < y))，存在减法溢出的潜在风险。
2009年6月2日，Timothy B. Terriberry建议使用异或来代替加减以避免强制类型转换和溢出的风险。
### 判断某个整数是不是2的次幂

```c
unsigned int v; // we want to see if v is a power of 2
                // 判断变量v是否是2的次幂
bool f;         // the result goes here
                // 答案保存在变量f中

f = (v & (v - 1)) == 0;
```

注意，0在这里计算出的结果是不对的。为了更严谨一些，有：
```c
f = v && !(v & (v - 1));
```

### 符号扩展(固定位长)

符号扩展(sign extension)是系统内建的自动机制，比如char型和int型之间的互相转换。但当你有一个带符号长度为b位的补码数x，你想要把x转换为长度超过b位的int型时，这个机制就不能满足需求了。诚然，简单赋值对于正数x是有效的，但是负数x都不行了，因为符号位需要被扩展。举个例子来简单说明什么是符号扩展(sign extension)，我们现在有一个4位长的变量来保存数，对于-3来说，保存下来的补码形式为1101。如果我们有8位长，那么-3保存下来的补码形式为11111101。当尝试将一个4位长的数转换为更多位长的数时，符号位会向左复制填充空出来的位，直到填满。在C语言中，使用结构体或联合体的位域很容易实现固定为长的符号扩展。比如，将长度为5位的数转换成整型。

```c
int x; // convert this from using 5 bits to a full int
       // 变量x中保存长度为5位的数
int r; // resulting sign extended number goes here
       // 转换的结果保存在变量r中
struct {signed int x:5;} s;
r = s.x = x;
```

下面的C++模版函数使用了同样的语言特性通过一次操作来转换长度为B的数到整型(当然，编译器会生成更多代码)。

```cpp
template <typename T, unsigned B>
inline T signextend(const T x)
{
  struct {T x:B;} s;
  return s.x = x;
}

int r = signextend<signed int,5>(x);  // sign extend 5 bit number x to r
                                      // 从5位长的数x转换到r
```

2005年5月2日，John Byrd找到了一处由于html格式问题导致的样式显示错误。

2006年3月4日，Pat Wood指出ANSI C标准规定带符号的位域必须要用关键字“signed”来显式地指定其带符号，否则其符号位是未定义的。
