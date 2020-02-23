# Codeforces Round #724 解题报告

## A. Checking the Calendar

### 解题分析

简单考虑一下两个月相差天数对星期带来的影响就能想出解法。

[Submission](http://codeforces.com/contest/724/submission/21281403)

## B. Batch Sort

### 解题分析

数据量非常小，可以先考虑每种竖列的移动方式（一共( (m+1) * m) / 2种）后，再判断是否能通过移动每行中的数字来达成有序。

[Submission](http://codeforces.com/contest/724/submission/21284824)

## C. Ray Tracing

### 解题分析

可以将判断点A(x, y)，先按照x轴和y轴分别进行轴对称后，形成4个点，然后将(-n, -m) -> (n, m)所形成的矩形区域以及其中包含的点向x轴和y轴移动，形成4\*k个点, 对于A点来说，展开后的坐标为(±x + 2ns, ±y + 2mt)。

当±x + 2ns = ±y + 2mt时，A点被射线穿过。

所以最后的答案就是求±x - ±y = 2mt - 2ns的解，取其中令±x + 2ns合法且最小的即可。

[Submission](http://codeforces.com/contest/724/submission/21341246)
