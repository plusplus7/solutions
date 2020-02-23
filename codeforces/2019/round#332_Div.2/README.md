# Codeforces Round #332 (Div. 2)解题报告

## A. Patrick and Shopping

### 解题分析

想想就能知道，Patrick只有4种路线。

```
家  商店1  商店2  家
家  商店1  商店2  商店1  家
家  商店2  家  商店1  家
家  商店2  商店1  商店2  家
```


直接加一下，然后比较就好了

[Submission](http://codeforces.com/contest/599/submission/14366841)

## B. Spongebob and Joke

### 解题分析

如果有f中有两个相同元素并且在b中存在，说明ai可以有两种选择，那么答案就是Ambiguity。

如果f中不存在某个元素并且这个元素在b中存在，说明ai不可能存在，那么答案就是Impossible。

判断完两种情况，那么答案就一定唯一且存在，顺着推一遍就好了，最后需要注意的一点是Impossible的优先级大于Ambiguity。

[Submission](http://codeforces.com/contest/599/submission/14470333)

## C. Day at the Beach

### 解题分析

对h中的每个元素求前缀最大prefmax和

后缀最小suffmin。



只有当某个元素的prefmax <= suffmin时，那么就说明能从这里分组

[Submission](http://codeforces.com/contest/599/submission/14473234)

## D. Spongebob and Squares

### 解题分析

很容易发现，若n＊m的矩形包含x个不同的正方形，那么当n < m, 

有![](http://latex.codecogs.com/gif.latex?x = n*m + (n-1)*(m-1)+...+(n-n)*(m-n))

可得![](http://latex.codecogs.com/gif.latex?x = n^2*m-(n+m)*\\Sigma^{n-1}_{i=0}i+\\Sigma^{n-1}_{i=0}i^2)

通过运算可以得到

![](http://latex.codecogs.com/gif.latex?6x = 3mn^2+3mn-n^3+n)

可知n最大不会超过![](http://latex.codecogs.com/gif.latex?2\\sqrt[3]{X})

所以暴力找一下n就好了。

[SourceCode](http://codeforces.com/contest/599/submission/14474362)
