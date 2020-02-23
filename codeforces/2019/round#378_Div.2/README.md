# Codeforces Round #378 (Div. 2) 解题报告

## A. Grasshopper And the String

### 解题分析

O(n)遍历一下就好了

注意要处理最大跨度的端点在终点的情况

Tricky case:

RERRRRRRR

[Submission](http://codeforces.com/contest/733/submission/21965598)


## B. Parade

### 解题分析

O(n)遍历一下，尝试翻转每一对士兵，记录最大值

[Submission](http://codeforces.com/contest/733/submission/21924729)


## C. Epidemic in Monstropolis

### 解题分析

因为每个怪兽都只能吃相邻的怪兽，所以在最终形成的局面，每个怪兽都一定是吃掉了队列上的一段怪兽。

由于怪物体重是固定的，所以可以用O(n)来遍历一下，找出最终每个怪兽都吃掉了哪些怪兽。

对于每个最终怪兽，它吃掉了队列上从s到e的怪兽，令dp[i][j]为是否存在方案使得编号i到j被一只怪兽吃掉，mark[i][j]表示i到mark[i][j]被吃成一只怪兽，mark[i][j]+1到j被吃成一只怪兽，最后这两只怪兽互相可以吃掉。

dp[i][j] = dp[i][m] + dp[m+1][j]，i <= m < j，当且仅当dp[i][m] != dp[m+1][j], dp[i][m] 和 dp[m+1][j]均存在方案。

同时记录mark[i][j]的值用于回溯出答案。

最后dfs一下就能回溯出吃怪兽的方案。

[Submission](http://codeforces.com/contest/733/submission/21937835)

## D. Kostya the Sculptor

### 解题分析

对每个方块的长宽高进行排序，排序后的结果用a, b, c表示。

思考一下可以知道，对于两个方块(a1, b1, c1) (a2, b2, c2)，只有当b1 c1面和b2 c2面粘在一起，最终获得的收益最大。

所以对所有的方块进行排序，按照c b a的顺序从大到小排序。对于c 和 b相同的两个方块，把a的值加起来算一下能获取到的球体积最大为多少，取最大值就好。

由于已经排过序了，所以对于同样的c 和 b，只需要把最大的两个a加起来就可以了，其他的结果必然比这个小，可以忽略。

注意，C/C++的sort，qsort函数，重写cmp函数时，注意当两个数相等时不要返回true。有的STL实现，并没有判断边界条件，会导致数组越界Runtime Error。

[Submission](http://codeforces.com/contest/733/submission/21965392)
