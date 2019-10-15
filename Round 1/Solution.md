# 第六周脑力风暴答案

看官们脑力风暴又回来了！  
我们将在本期为你们暴力拆解上期小题  
But……  
Before we start……  
有人说上周的数学题好像是作业题  
……

![](Images/S1.jpg)

（我也没去查证……如果这是真的，大佬们求放过！！！  
那话不多说，我们已经撸好袖子了，你们呢？

## 题目一：简单的微积分

设 $a_n = (1+\frac 1 2+ \cdots + \frac 1 n)^{\frac 1 n}, n \in \N^+$, 求 $\lim_{n\rightarrow\infty} a_n$  
我们一开始的想法是，趁你们还没学夹逼准则  
Hiahiahia  
不过我们在没料到老师们推进神速

![](Images/S2.jpg)

易知 $1 < 1 +\frac 1 2+\cdots+\frac 1 n < n$;  
而 $\lim_{n \rightarrow \infty } \sqrt[n]{n}=\lim_{n\rightarrow\infty} 1 = 1$  
根据夹逼准则  
$\lim_{n\rightarrow\infty}a_n = 1$

## 题目二：接雨水

思路：显然每根柱子上能接的雨水取决于它左边最高的柱子和右边最高的柱子中最矮的一个，于是我们分别统计每根柱子左右的情况，再进行计算。  
设 $a_i$ 为第i根柱子左边最高柱子的高度，$b_i$ 为右边的高度, $h_i$ 为第i根柱子的高度。  
则 $a_i=\max\{a_{i-1},h_{i-1}\},a_i=\max\{a_{i+1},h_{i+1}\}$  
（令 $a_1 = b_n = 0$）  
如果 $\min\{a_i,b_i\}>h_i$ 则第i根柱子能接的雨水量为：$\min\{a_i,b_i\}-h_i$，否则为0。  
最后累加即可。

参考实现与测试数据：
<https://github.com/MrChenWithCapsule/2PHM-Solutions>