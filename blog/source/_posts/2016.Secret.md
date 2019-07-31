---
layout: post
title: Secret解题报告
date: 2016-9-17 01:21
comments: true
reward: true
tags:
    - Security
---

题目背景较多，读完题之后，发现其实就是要写一个程序来计算$$2^{year-1} \% 1000000007$$

题目要求一次计算不超过1s才能得满分，而year-1的值非常大。

显然无法使用暴力的pow(2,year-1)%1000000007来计算答案，题目提示结合密码学的相关知识，于是可以判断出有相关的数学方法可以帮助计算。

<!-- more -->

如果学过RSA公钥加密算法，应该对 费马小定理 及其推广 欧拉定理 有所了解。

欧拉定理，是一个关于同余的性质。

欧拉定理表明，若n,a为正整数，且n,a互质，即n和a最大公约数是1。那么有：
$$a^{\varphi(n)} \equiv 1\space (mod{\space}n)$$

其中，$\varphi(n)$是欧拉函数，其值是小于或等于n的正整数中与n互质的数的数量。

而在本题中，令a是2，显然a是一个质数；令n是1000000007，也是一个质数。a和n显然互质。

将其带入欧拉定理的等式，$$2^{\varphi(n)} \equiv 1\space (mod{\space}n)$$

由于1000000007是一个质数，小于或等于n的正整数中与他互质的数的数量显然是1000000006，因为只有1不与1000000007互质。
所以，可以得到$$2^{1000000006} \equiv 1\space (mod\space 1000000007)$$

现在回到本题，我们设year-1为m，于是题目变成求$2^m \% 1000000007$的值。

有了上面的推导，可以把$2^m \% 1000000007$分成$ 2^{1000000006} * 2^{1000000006} * \cdots * 2^k$

其中k是m%1000000006的值，这里需要编程写一下大数取模。

之后就是对$2^k%1000000007$的计算，其中k是一个小于$10^9+6$的正整数。

这里如果直接使用pow(2,k) %1000000007的话，1次计算的运行时间会超过1s。也就是说，如果解题到此处，并提交key，可以得到200分。那么如何得到最后100分呢？

这里可以使用快速幂模算法，这是一个密码学及数论中很常见的运算技巧，来计算便可以很快得到答案，满分！

标准代码：
```cpp
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAD 1000000006
char str[200000],num[200000];
int t[200000],tonum[200000];
int main()
{
    freopen("out.txt","r",stdin);
    scanf("%s",str);
    int ori=10,to=2;
    int i,j=0,len=strlen(str),k=len,tt=len-1;
    /// 处理减1
    if (str[tt] != '0')
        str[tt]--;
    else
    {
        while (str[tt] == '0')
            tt--;
        str[tt]--;
        for (i=tt+1; i<len; i++)
        {
            str[i]='9';
        }
    }
    /// 计算year-1 % MOD
    int st=0;
    long long t,s;
    s=0;
    while (str[st] == '0')
        st++;
    str[len]='\0';
    for (i=st; i<len; i++)
    {
        s=s*10+str[i]-'0';
        s=s%MAD;
    }
    /// 快速幂
    long long ans=1;
    long long mul=2;
    while (s != 0)
    {
        if ((s&1) == 1)
            ans=ans*mul%MOD;
        mul=mul*mul%MOD;
        s>>=1;
    }
    printf("%I64d\n",ans);
    return 0;
}
```

