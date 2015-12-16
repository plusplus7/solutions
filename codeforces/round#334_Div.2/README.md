# Codeforces Round #334 (Div.2)解题报告

## A - Uncowed Forces

##### 解题分析

其实就是按照公式计算最后得分...

记得要把有除法的地方事先约掉，不然算出浮点数可能会有坑。

[Submission](http://codeforces.com/contest/604/submission/14685347)

## B - More Cowbell

分析一下，可以知道本题是要求箱子尺寸的最小值s使得以最多2个cowbells放进1个箱子的方式，可以把所有的cowbells放进k个箱子里。

求可行解内的最大最小值，通常会想到用二分来求这个值。

判断某个值是否为可行解时，注意判断边界就好了。

[Submission](http://codeforces.com/contest/604/submission/14685562)

## C - Alternative Thinking

给定一个10串s，将连续1和连续0压缩在一起，统计长度。选择某个连续的区间，将区间内的01翻转，使得最后统计长度最长。

先统计一下长度，记为l。

如果原始串里面出现了两个或以上的00或者11，那么翻转后一定能到l+2。随便选择两个00或者11，然后以翻转以他们为收尾的区间，即可。

如果原始串里面出现了一个00或者11，那么翻转后也能得到l+2。选择00或者11为端点，选择串的首或者尾为另一个端点翻转，即可。

所以最后答案是min(len(s), l+2)

[Submission](http://codeforces.com/contest/604/submission/14686023)
