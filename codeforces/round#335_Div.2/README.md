# Codeforces Round #335 (Div.2)解题报告

## A - Magic Spheres

##### 解题分析

数据量非常小，考虑手工模拟把多出来的球合并成缺少的球的过程，这样不容易出错。

[Submission](http://codeforces.com/contest/606/submission/14938368)

## B - Testing Robots

##### 解题分析

此题题意比较难理解。

机器人从(x0, y0)出发，问按照长度为n的指令序列走。走到k步时，正好走到炸弹上或者走完了n步爆炸的情况有多少种。

模拟每走一步时的情况，同时标记某个方块是否走过。如果走过，那么输出0；反之，输出1。

最后再统计一下有多少方块没有走过就好了。

[Submission](http://codeforces.com/contest/606/submission/14938327)

## C - Sorting Railway Cars

##### 解题分析

分析一下，如果取出所有需要移动的车厢，那么剩下的车厢一定有序且递增1的。那么要使移动的车厢最少，其实就是求一个数列的单调递增为1的最长子序列。

[Submission](http://codeforces.com/contest/606/submission/15073001)
