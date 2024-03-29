# 第十周脑力风暴答案

本来应该是上周更的  
不过因为~~我们懒~~部长爱护部员嘛  
所以就拖到这周了呢  
有没有想念我们？

## 那道不那么难的微积分

这道题在小黄书上有原题，大家刷题时可能都看见了  

我发四我是在另一本习题集上看见这题的，上边还说这是1995年题

1. 用反证法。 若存在点 $c \in (a,b)$，使 $g(c)=0$，则对 $g(c)$ 在 $[a,c]$ 和 $[c,b]$ 上分别应用罗尔定理，知存在 $\xi_1 \in (a,c)$ 和 $\xi_2 \in (c,b)$ 使  
   $g'(\xi_1)=g'(\xi_2)=0$。  
   再对 $g'(x)$ 在 $[\xi_1,\xi_2]$ 上应用罗尔定理，知存在 $\xi_3 \in (\xi_1,\xi_2)$，使 $g''(\xi_3)=0$。 这与题设 $g''(x) \neq 0$ 矛盾，故在 $(a,b)$ 内 $g(x) \neq 0$。

2. 令 $F(x)=f(x)g'(x)-f'(x)g(x)$。  
   易知 $F(a)=F(b)=0$，对 $F(x)$ 在 $[a,b]$ 上应用罗尔定理，知存在 $\xi \in (a,b)$，使 $F'(\xi)=0$，即 $f(\xi)g''(\xi)-f''(\xi)g(\xi)=0$。 因 $g(\xi) \neq 0$，$g''(\xi) \neq 0$，故得 $\frac {f(\xi)} {g(\xi)} = \frac {f''(\xi)} {g''(\xi)}$。

## 第 k 个排列

### 简单难度

这个是 STL 里面有的东西，我又有什么好说的呢。。。  
C 选手请无视我的话。  
简单来说，假设有一个数组 $A$，我们需要找出以末尾结束的最长递减子序列 $A_i,\cdots,A_{n-1}$，然后把其中大于 $A_{i-1}$ 的最小的数与 $A_{i-1}$ 交换顺序，然后把新的 $A_i,\cdots,A_{n-1}$ 从小到大排列就得到了一个排列的下一个排列。  
重复 $n$ 次就行了。

### 困难难度

我们可以这样来考虑问题：  
求 $A_1,\cdots,A_n$ 这 $n$ 个数的第 $k$ 个排列，可以先找出第一个数 $A_i$，然后求剩下 $n-1$ 个数的第 $m$ 个排列，使得他们排列的顺序刚好和直接求第 $k$ 个排列的顺序相同。

我们知道 $n$ 个数的全排列有 $n!$ 个，而对于每一个数，它放在第一个位置后剩下的数都会有 $(n-1)!$ 个排列，并且第一个数更小的排列一定先于第一个数更大的排列。  
于是，上面的 $A_i$ 其实就是这 $n$ 个数中第 $\lceil\frac k {(n-1)!}\rceil$ 大的数（注意需要向上取整），而 $m=k-(\lceil\frac k {(n-1)!}\rceil-1) \times (n-1)!$。

所以，我们可以递归地按照上面的公式找出每一个位置的数，最后就得到了答案。

需要注意的是找出第 $A_i$ 的过程。你可以先把数组 $A$ 先快速排序一次，然后去 $A_i$，这样做的话整个程序的时间复杂度是 $O(n^2\log n)$，但如果你不排序整个数组，而是只使用快速排序中的划分操作来找出 $A_i$ 的话时间复杂度会是 $O(n^2)$。至于为什么少了那个 $\log n$ 就很难解释了。。。或许 **hyh** 大佬可以把这件事情解释清楚。🙃  
思路如下：  
先把数组按照快排那样划分成 $A_1,\cdots,A_{j-1}$、$A_j$ 和 $A_{j+1},\cdots,A_n$，然后，如果 $j<i$，则对后一半再次划分；如果 $j=i$，此时 $A_j$ 就是要找的元素；如果 $j>i$，那么对前一半划分。这样递归下去，直到找到 $A_i$。  
显然一次划分之后前半部分的元素都小于 $A_j$，后半部分都大于等于 $A_j$。那么如果 $j=i$ 就找到了需要的 $A_i$。

具体实现见代码。  
<https://github.com/MrChenWithCapsule/Problems-for-AST/>
