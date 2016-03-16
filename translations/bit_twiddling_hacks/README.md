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
* [计算整数的绝对值(不使用分支指令)](#计算整数的绝对值不使用分支指令)
* [计算两个整数之间的最大值和最小值(不使用分支指令)](#计算两个整数之间的最大值和最小值不使用分支指令)
* [判断某个整数是不是2的次幂](#判断某个整数是不是2的次幂)
* [符号扩展(固定位长)](#符号扩展固定位长)
* [符号扩展(可变位长)](#符号扩展可变位长)
* [使用3次运算的符号扩展(可变位长)](#使用3次运算的符号扩展可变位长)
* [带条件判断的设置位或清除位(不使用分支指令)](#带条件判断的设置位或清除位不使用分支指令)
* [带条件判断的将变量置为相反数(不使用分支指令)](#带条件判断的将变量置为相反数不使用分支指令)
* [根据掩码对两个数值进行位合并](#根据掩码对两个数值进行位合并)
* [统计二进制位中1的个数(普通实现)](#统计二进制位中1的个数普通实现)
* [统计二进制位中1的个数(查表法)](#统计二进制位中1的个数查表法)
* [统计二进制位中1的个数(Brian Kernighan方法)](#统计二进制位中1的个数brian-kernighan方法)
* [统计二进制位中1的个数(14位字长, 24位字长, 32位字长, 64位架构下)](#统计14位字长24位字长32位字长的二进制位中1的个数64位架构下)
* [统计二进制位中1的个数(并行计算的方法)](#统计二进制位中1的个数并行计算的方法)
* [统计从最高位到指定的某位之间的二进制位1的个数](#统计从最高位到指定的某位之间的二进制位1的个数)
* [给定从某位到最高位1的个数，推算该位的位置](#给定从某位到最高位1的个数推算该位的位置)
* [计算奇偶校验位（普通实现）](#计算奇偶校验位普通实现)
* [计算奇偶校验位（查表法）](#计算奇偶校验位查表法)
* [计算单个字节的奇偶校验位（使用64位的乘法和模除）](#计算单个字节的奇偶校验位使用64位的乘法和模除)
* [计算单个字的奇偶校验位（使用乘法）](#计算单个字的奇偶校验位使用乘法)
* [计算奇偶校验位（并行计算）](#计算奇偶校验位并行计算)

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

### 符号扩展(可变位长)

有时，我们可能事先不知道位的长度，来完成符号扩展，上面的技巧就失效了。（也有可能是在某些不提供位域功能的编程语言，如Java）

```c
unsigned b; // number of bits representing the number in x
            // 变量b指定需要扩展的位长
int x;      // sign extend this b-bit number to r
            // 需要将变量x中的数值符号扩展的结果保存到r中
int r;      // resulting sign-extended number
            // 存放计算结果到变量r
int const m = 1U << (b - 1); // mask can be pre-computed if b is fixed
                             // 如果b是常量，那么这个掩码可以被预处理

x = x & ((1U << b) - 1);  // (Skip this if bits in x above position b are already zero.)
                          // (如果超过b位的部分都已经是0了，那么这步可以跳过)
r = (x ^ m) - m;
```

这段代码需要四次操作，但当位长是常量时，假设高位部分都已经清零了，那么这个技巧只需要两次操作。

还有一个更快但是略微损失移植性的方法，这个方法不需要假设位长度超过b的部分，即高位部分，都已经被清零：

```c
int const m = CHAR_BIT * sizeof(x) - b;
r = (x << m) >> m;
```

2004年6月13日，Sean A. Irvine建议我将符号扩展的方法添加进这个页面。同时他提供了这段代码m = (1 << (b - 1)) - 1; r = -(x & ~m) | x。后来我在这份代码的基础上，优化出了m = 1U << (b - 1); r = -(x & m) | x这个版本。

但是在2007年5月11日，Shay Green提出了上面的这个比我少一个操作的版本。

2008年10月15日，Vipin Sharma 建议我考虑增加一个步骤来解决如果x在除了b位长之外的二进制部分还存在1的情况。

2009年12月31日，Chris Pirazzi建议我增加目前最快的版本，这个版本对于固定位长的符号扩展，只需要2次操作；对于变长的，也只需要3次操作。

### 使用3次运算的符号扩展(可变位长)

这个技巧由于乘法和除法的关系，在某些机器上可能会慢一些。这个版本准确来说需要4次运算。如果你知道你的初始位长大于1的话，那么你就可以用r = (x * multipliers[b]) / multipliers[b]这种方法来完成符号扩展。这个技巧是基于一个事先初始化的表，它只需要3次操作。

```c
unsigned b; // number of bits representing the number in x
            // 变量b指定需要扩展的位长
int x;      // sign extend this b-bit number to r
            // 需要将变量x中的数值符号扩展的结果保存到r中
int r;      // resulting sign-extended number
            // 存放计算结果到变量r
#define M(B) (1U << ((sizeof(x) * CHAR_BIT) - B)) // CHAR_BIT=bits/byte
                                                  // CHAR_BIT是指一个字节中有多少位
static int const multipliers[] =
{
  0,     M(1),  M(2),  M(3),  M(4),  M(5),  M(6),  M(7),
  M(8),  M(9),  M(10), M(11), M(12), M(13), M(14), M(15),
  M(16), M(17), M(18), M(19), M(20), M(21), M(22), M(23),
  M(24), M(25), M(26), M(27), M(28), M(29), M(30), M(31),
  M(32)
}; // (add more if using more than 64 bits)
   // (如果需要支持到64位的话，可以继续添加)
static int const divisors[] =
{
  1,    ~M(1),  M(2),  M(3),  M(4),  M(5),  M(6),  M(7),
  M(8),  M(9),  M(10), M(11), M(12), M(13), M(14), M(15),
  M(16), M(17), M(18), M(19), M(20), M(21), M(22), M(23),
  M(24), M(25), M(26), M(27), M(28), M(29), M(30), M(31),
  M(32)
}; // (add more for 64 bits)
   // (继续添加以支持64位)
#undef M
r = (x * multipliers[b]) / divisors[b];
```

下面这个变种可能兼容性不高，但在某些支持算术右移架构，可以保持符号位的系统上，这个变种会更快一些。
```c
const int s = -b; // OR:  sizeof(x) * CHAR_BIT - b;
                  // 或者：sizeof(x) * CHAR_BIT - b;
r = (x << s) >> s;
```

2005年3月3日，Randal E.Bryant指出了一个最初版本的bug(即使用查表的版本)，当x和b都为1时，这个技巧就会失效。

### 带条件判断的设置位或清除位（不使用分支指令）

```c
bool f;         // conditional flag
                // 使用这个标志来表示条件判断
unsigned int m; // the bit mask
                // 位掩码
unsigned int w; // the word to modify:  if (f) w |= m; else w &= ~m;
                // 需要进行操作的变量

w ^= (-f ^ w) & m;

// OR, for superscalar CPUs:
// 在一些超标量架构的CPU上，也可以这样:
w = (w & ~m) | (-f & m);
```

在某些架构上，不使用分支指令会比使用分支指令多出2个甚至更多的操作。举个例子，通过非正式速度测试表明，AMD Athlon™ XP 2100+能快5-10%； Intel Core 2 Duo的超标量版本能比能比前一个快16%。
2003年12月11日，Gelnn Slayden告诉了我第一个算法。
2007年4月3日，Marco Yu给我分享了超标量版本的算法，在两天后给我提出了一处显示排版错误。

### 带条件判断的将变量置为相反数（不使用分支指令）

在不使用分支指令的情况下，你可能会需要判断某个flag是否false，来将某个变量置为其相反数：

```c
bool fDontNegate;  // Flag indicating we should not negate v.
                   // Flag标志，用于判断我们是否需要将变量v置为相反数
int v;             // Input value to negate if fDontNegate is false.
                   // 输入的数值保存在v中，当fDontNegate为false时，就将变量v置为相反数
int r;             // result = fDontNegate ? v : -v;

r = (fDontNegate ^ (fDontNegate - 1)) * v;
```

如果flag为true才将变量置为相反，那么可以用这个：
```c
bool fNegate;  // Flag indicating if we should negate v.
               // Flag标志，用于判断我们是否需要将变量v置为相反数
int v;         // Input value to negate if fNegate is true.
               // 输入的数值保存在v中，当fDontNegate为true时，就将变量v置为相反数
int r;         // result = fNegate ? -v : v;

r = (v ^ -fNegate) + fNegate;
```

2009年6月2日，Avraham Plotnitzky建议我添加第一个版本。

2009年6月8日，为了去除掉乘法，我想出了第二个版本。

2009年11月26日，Alfonso De Gregorio指出某个地方缺少括号。这是一个合理的bug，所以它得到了指出bug的赏金。

### 根据掩码对两个数值进行位合并

```c
unsigned int a;    // value to merge in non-masked bits
                   // 将变量a中没被掩码覆盖的位保留下来
unsigned int b;    // value to merge in masked bits
                   // 将变量b中被掩码覆盖的位保留下来
unsigned int mask; // 1 where bits from b should be selected; 0 where from a.
                   // 如果某一位是1，那么结果中对应的位就保存b所对应位置的值；如果是0，则保存a所对应位置的值。
unsigned int r;    // result of (a & ~mask) | (b & mask) goes here
                   // 这里保存(a & ~mask) | (b & mask)的结果

r = a ^ ((a ^ b) & mask);
```

这个算法比这种简单的实现(a & ~mask) | (b & mask)节省一次操作。然而如果掩码是一个常量，那么这两种算法实际上都差不多。

2006年2月9日，Ron Jeffery将这个算法发给我了。

### 统计二进制位中1的个数(普通实现)

```c
unsigned int v; // count the number of bits set in v
                // 计算变量v的二进制中1的个数
unsigned int c; // c accumulates the total bits set in v
                // 保存计算的结果

for (c = 0; v; v >>= 1)
{
  c += v & 1;
}
```

这个简单算法对于每一位都需要一次操作，直到结束。所以对于32位字长，且只有最高位为1时（即最坏情况），这个算法会操作32次。

### 统计二进制位中1的个数(查表法)

```c
static const unsigned char BitsSetTable256[256] =
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

unsigned int v; // count the number of bits set in v
                // 计算变量v的二进制中1的个数
unsigned int c; // c accumulates the total bits set in v
                // 保存计算的结果
// Option 1:
// 第一种：
c = BitsSetTable256[v & 0xff] +
    BitsSetTable256[(v >> 8) & 0xff] +
    BitsSetTable256[(v >> 16) & 0xff] +
    BitsSetTable256[v >> 24];

// Option 2:
// 第二种：
unsigned char * p = (unsigned char *) &v;
c = BitsSetTable256[p[0]] +
    BitsSetTable256[p[1]] +
    BitsSetTable256[p[2]] +
    BitsSetTable256[p[3]];


// To initially generate the table algorithmically:
// 使用算法来预处理表的内容
BitsSetTable256[0] = 0;
for (int i = 0; i < 256; i++)
{
  BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
}
```

2009年7月14日，Hallvard Furuseth提出了宏压缩版本的预处理表的方法。

### 统计二进制位中1的个数(Brian Kernighan方法)

```c
unsigned int v; // count the number of bits set in v
                // 计算变量v的二进制中1的个数
unsigned int c; // c accumulates the total bits set in v
                // 保存计算的结果
for (c = 0; v; c++)
{
  v &= v - 1; // clear the least significant bit set
              // 清除掉从最低位到最高位数的第一个为1的位
}
```

Brian Kernighan的方法运算次数取决于二进制位中1的个数。所以如果一个32位字长的数，只有最高位是1，那么这个算法只会执行1次。

1988年，发布于《C程序设计语言》（第二版），作者Brian W. Kernighan和Dennis M. Ritchie。在此书的练习2-9中提到了这个算法。

2006年4月19日，Don Knuth向我指出这个算法，“是被Peter Wegner首先在CACM 3 (1960), 322发表的”。（同时也被Derrick Lehmer独立发现，并且在1964年由Beckenbach编辑发表在一本书上）

### 统计14位字长，24位字长，32位字长的二进制位中1的个数(64位架构下)

```c
unsigned int v; // count the number of bits set in v
                // 计算变量v的二进制中1的个数
unsigned int c; // c accumulates the total bits set in v
                // 保存计算的结果

// option 1, for at most 14-bit values in v:
// 第一种情况，只计算统计变量v中的14位
c = (v * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;

// option 2, for at most 24-bit values in v:
// 第二种情况，只计算统计变量v中的24位
c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL)
     % 0x1f;

// option 3, for at most 32-bit values in v:
// 第三种情况，只计算统计变量v中的32位
c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) %
     0x1f;
c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
```

这个算法需要在支持快速模除的64位CPU上才能达到高性能的效果。第一种情况只需要3次操作，第二种需要10次，第三种需要15次。

Rich Schroeppel最初想出了一个和第一种类似的9位长版本，见Programming Hacks的这一章节[Beeler, M., Gosper, R. W., and Schroeppel, R. HAKMEM. MIT AI Memo 239, Feb. 29, 1972](http://www.inwap.com/pdp10/hbaker/hakmem/hakmem.html)。他的想法是收此启发，并最终由Sean Anderson完成设计。

2005年5月3日，Randal E.Byrant提了几个bug修复补丁。

2007年2月1日，Bruce Dawson对原来的12位版本做了一些调整，将其变成了兼容性更好的14位版本，并且保持操作数不变。

### 统计二进制位中1的个数(并行计算的方法)

```c
unsigned int v; // count the number of bits set in v
                // 计算变量v的二进制中1的个数
unsigned int c; // c accumulates the total bits set in v
                // 保存计算的结果
static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

c = v - ((v >> 1) & B[0]);
c = ((c >> S[1]) & B[1]) + (c & B[1]);
c = ((c >> S[2]) + c) & B[2];
c = ((c >> S[3]) + c) & B[3];
c = ((c >> S[4]) + c) & B[4];              
```

B数组，以及其二进制的形式如下：

```c
B[0] = 0x55555555 = 01010101 01010101 01010101 01010101
B[1] = 0x33333333 = 00110011 00110011 00110011 00110011
B[2] = 0x0F0F0F0F = 00001111 00001111 00001111 00001111
B[3] = 0x00FF00FF = 00000000 11111111 00000000 11111111
B[4] = 0x0000FFFF = 00000000 00000000 11111111 11111111
```

通过添加两个幻数数组B和S，就能够扩展这个方法，以适应位长更多的整数类型。如果有k位的话，那么我们只需要把数组S和B扩展到ceil(lg(k))个元素就好，同时添加对应数量的计算c的表达式。对于32位长度的v来说，一共需要16次操作。

然而对于计算32位整型数来说，最好的计算方法下面这种：

```c
v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
                                                    // 将输入变量作为临时变量重复使用
v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
                                                    // 临时变量
c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
                                                    // 计算结果
```

这种计算方法只需要12次操作，虽然和上面查表的方法差不多，但是却能够节省了内存和避免了潜在的缓存未命中而导致的额外操作。这是在并行计算方法和之前使用乘法的那种方法（在64位架构下，二进制位中1的个数那一小节中）之间的结合，然而这个方法却不需要64位架构的指令。每个比特中的1统计可以并行的计算，最终的结果计算是通过乘以0x1010101后右移24位来得出的。

这个方法还有一个推广，可以计算长度多达128位的整型数(128位整型的数据类型使用T来代替)，如下：

```c
v = v - ((v >> 1) & (T)~(T)0/3);                           // temp
v = (v & (T)~(T)0/15*3) + ((v >> 2) & (T)~(T)0/15*3);      // temp
v = (v + (v >> 4)) & (T)~(T)0/255*15;                      // temp
c = (T)(v * ((T)~(T)0/255)) >> (sizeof(T) - 1) * CHAR_BIT; // count
```

在[Ian Ashdown's nice newsgroup post](http://groups.google.com/groups?q=reverse+bits&amp;num=100&amp;hl=en&amp;group=comp.graphics.algorithms&amp;imgsafe=off&amp;safe=off&amp;rnum=2&amp;ic=1&amp;selm=4fulhm%248dn%40atlas.uniserve.com)还可以看到更多关于计算二进制位中1个数（也被人称为sideways addition）的相关信息。

### 统计从最高位到指定的某位之间的二进制位1的个数

这个方法是用来计算某一位的rank，意思是统计从最高位到指定的某位之间二进制位1的个数

```c
uint64_t v; // Compute the rank (bits set) in v from the MSB（最高位） to pos.
            // 计算v中从第pos位到最高位的rank(二进制位1的个数)
unsigned int pos; // Bit position to count bits upto.
                  // 指定某一位，向最高位统计
uint64_t r; // Resulting rank of bit at pos goes here.
            // 保存统计的结果

// Shift out bits after given position.
// 将其余的位右移出去
r = v >> (sizeof(v) * CHAR_BIT - pos);
// Count set bits in parallel.
// 并行地统计1的个数
// r = (r & 0x5555...) + ((r >> 1) & 0x5555...);
r = r - ((r >> 1) & ~0UL/3);
// r = (r & 0x3333...) + ((r >> 2) & 0x3333...);
r = (r & ~0UL/5) + ((r >> 2) & ~0UL/5);
// r = (r & 0x0f0f...) + ((r >> 4) & 0x0f0f...);
r = (r + (r >> 4)) & ~0UL/17;
// r = r % 255;
r = (r * (~0UL/255)) >> ((sizeof(v) - 1) * CHAR_BIT);
```

2009年11月21日，Juha Järvi将这个算法发给了我，这个算法是下一个算法（给定从某位到最高位1的个数，推算出该位的位置）的逆运算。

### 给定从某位到最高位1的个数，推算该位的位置

接下来这份64位的代码可以选取出从左到右第r个二进制1的位置。也就是说，如果我们从最高位往右，统计二进制位为1的个数，直到达到了预期的rank（译者：解释见上一条），那么我们停下的位置就是答案。如果超出了最低位还没有算出结果，那么会返回64。这段代码可以改编出32位版本，也可以从最右边开始统计。

```c
// Do a normal parallel bit count for a 64-bit integer,      
// 并行地统计出二进制1的个数               
 // but store all intermediate steps.       
 // 保存所有的中间结果                                 
 // a = (v & 0x5555...) + ((v >> 1) & 0x5555...);
 a =  v - ((v >> 1) & ~0UL/3);
 // b = (a & 0x3333...) + ((a >> 2) & 0x3333...);
 b = (a & ~0UL/5) + ((a >> 2) & ~0UL/5);
 // c = (b & 0x0f0f...) + ((b >> 4) & 0x0f0f...);
 c = (b + (b >> 4)) & ~0UL/0x11;
 // d = (c & 0x00ff...) + ((c >> 8) & 0x00ff...);
 d = (c + (c >> 8)) & ~0UL/0x101;
 t = (d >> 32) + (d >> 48);
 // Now do branchless select!   
 // 这里进行无分支指令的条件选取                                             
 s  = 64;
 // if (r > t) {s -= 32; r -= t;}
 s -= ((t - r) & 256) >> 3; r -= (t & ((t - r) >> 8));
 t  = (d >> (s - 16)) & 0xff;
 // if (r > t) {s -= 16; r -= t;}
 s -= ((t - r) & 256) >> 4; r -= (t & ((t - r) >> 8));
 t  = (c >> (s - 8)) & 0xf;
 // if (r > t) {s -= 8; r -= t;}
 s -= ((t - r) & 256) >> 5; r -= (t & ((t - r) >> 8));
 t  = (b >> (s - 4)) & 0x7;
 // if (r > t) {s -= 4; r -= t;}
 s -= ((t - r) & 256) >> 6; r -= (t & ((t - r) >> 8));
 t  = (a >> (s - 2)) & 0x3;
 // if (r > t) {s -= 2; r -= t;}
 s -= ((t - r) & 256) >> 7; r -= (t & ((t - r) >> 8));
 t  = (v >> (s - 1)) & 0x1;
 // if (r > t) s--;
 s -= ((t - r) & 256) >> 8;
 s = 65 - s;
```

如果在你的CPU上分支指令速度足够快，可以考虑将使用被注释掉的那些if语句，将对应的其它语句注释掉。

2009年11月21日，Juha Järvi将这个发给了我。

### 计算奇偶校验位（普通实现）

```c
unsigned int v;       // word value to compute the parity of
                      // 需要计算的值保存在变量v中
bool parity = false;  // parity will be the parity of v
                      // 变量parity保存v的奇偶校验位
while (v)
{
  parity = !parity;
  v = v & (v - 1);
}
```

上面这段代码实现使用了类似Brian Kernigan的统计二进制位中1个数的方法。二进制中有多少个1，这个算法就会计算多少次。

### 计算奇偶校验位（查表法）

```c
static const bool ParityTable256[256] = 
{
#   define P2(n) n, n^1, n^1, n
#   define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#   define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
    P6(0), P6(1), P6(1), P6(0)
};

unsigned char b;  // byte value to compute the parity of
                  // 需要计算的值保存在变量b中
bool parity = ParityTable256[b];

// OR, for 32-bit words:
// 或者，32位字长下
unsigned int v;
v ^= v >> 16;
v ^= v >> 8;
bool parity = ParityTable256[v & 0xff];

// Variation:
// 变种
unsigned char * p = (unsigned char *) &v;
parity = ParityTable256[p[0] ^ p[1] ^ p[2] ^ p[3]];
```

2005年5月3日，Randal E.Bryant提出了使用变量p的那个变种版本。

2005年9月27日，Bruce Rawles发现了表中有一处变量名拼写错误，并获得了10美刀的奖励。

2006年10月9日，Fabrice Bellard提出了32位字长的变种，这个变种只需要查表一次；最初的版本需要4次查表（每个字节一次），明显更慢一些。

2009年7月14日，Hallvard Furuseth提出用宏来精简表的长度。

### 计算单个字节的奇偶校验位（使用64位的乘法和模除）

```c
unsigned char b;  // byte value to compute the parity of
                  // 需要计算的值保存在变量b中
bool parity =
  (((b * 0x0101010101010101ULL) & 0x8040201008040201ULL) % 0x1FF) & 1;
```

这个方法只需要4次操作，然而只能计算单个字节。

### 计算单个字的奇偶校验位（使用乘法）

这个方法计算32位字长的值在使用乘法的情况下，只需要8次操作。

```c
unsigned int v; // 32-bit word
                // 32位长度的字
v ^= v >> 1;
v ^= v >> 2;
v = (v & 0x11111111U) * 0x11111111U;
return (v >> 28) & 1;
```

对于64位，仍只需要8次操作。

```c
unsigned long long v; // 64-bit word
                      // 64位长度的字

v ^= v >> 1;
v ^= v >> 2;
v = (v & 0x1111111111111111UL) * 0x1111111111111111UL;
return (v >> 60) & 1;
```

2007年9月2日，Andrew Shapira想出的这个算法，并发给了我。

### 计算奇偶校验位（并行计算）

```c
unsigned int v;  // word value to compute the parity of
                 // 需要计算奇偶校验位的字长度的值
v ^= v >> 16;
v ^= v >> 8;
v ^= v >> 4;
v &= 0xf;
return (0x6996 >> v) & 1;
```

这个方法需要9次运算，可以工作在32位字长的环境下。如果是只需要对字节进行计算，那么可以把“unsigned int v;”的下两行去掉，这样可以把操作数优化到5次。这个方法先是将这个32位值的分成8个半字节，通过右移和异或将v压缩到v的最低的半字节中。然后将二进制位0110 1001 1001 0110(十六位表示为0x6996)的数值右移，右移的位数是刚刚计算出来的v的最低半字节的值。这个幻数就像是一个16位的小型奇偶校验位的表，通过v的最低半字节的值可以查到v的奇偶校验位。最终结果存放在最低位中，代码最后通过掩码的方式计算出了结果并返回。

2002年12月15日，感谢Mathew Hendry提出了右移查表的想法。相比只使用右移和异或的方法，这个优化可以减少掉节省两次操作。
