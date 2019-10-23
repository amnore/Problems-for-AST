# 第八周脑力风暴

某 dailao：你们上期的数学题有点简单呢ƪ(˘⌣˘)ʃ  
我们：？？？  
有一说一，确实，我们的错  
所以这次为了不让在座的各位失望，我们决定出一道稍微难一点的（渣渣hwd不会的）  
话不多说，上菜！

## 题目一：不是那么简单的微积分

设函数 $f(x)$ 定义于 $(a,+\infty)$ 上，且在每一个有限区间 $(a,b)$ 内是有界的。证明：  
$$\lim_{x\rightarrow+\infty} \frac {f(x)} x = \lim_{x\rightarrow+\infty} (f(x+1)-f(x))$$

## 题目二：愤怒的小鸟

（不知道某些童鞋看到这个题目是不是心头一紧😏）

### 题目描述

Kiana 最近沉迷于一款神奇的游戏无法自拔。  
简单来说，这款游戏是在一个平面上进行的。  
有一架弹弓位于 $(0,0)$ 处，每次 Kiana 可以用它向第一象限发射一只红色的小鸟，小鸟们的飞行轨迹均为形如 $y=ax^2+bx$ 的曲线，其中实数 $a,b$ 是 Kiana 指定的参数，且必须满足 $a<0$。  
当小鸟落回地面（即 $x$ 轴）时，它就会瞬间消失。

在游戏的某个关卡里，平面的第一象限中有 $n$ 只绿色的小猪，其中第 $i$ 只小猪所在的坐标为 $(x_i,y_i)$。  
如果某只小鸟的飞行轨迹经过了 $(x_i,y_i)$，那么第 $i$ 只小猪就会被消灭掉，同时小鸟将会沿着原先的轨迹继续飞行；  
如果一只小鸟的飞行轨迹没有经过 $(x_i,y_i)$，那么这只小鸟飞行的全过程就不会对第 $i$ 只小猪产生任何影响。

例如，若两只小猪分别位于 $(1,3)$ 和 $(3,3)$，Kiana 可以选择发射一只飞行轨迹为 $y=−x^2+4x$ 的小鸟，这样两只小猪就会被这只小鸟一起消灭。

现在，Kiana 想知道，她一次最多能打中几只小猪？

### 输入格式

第一行包含一个非负整数 $n$，分别表示该关卡中的小猪数量。接下来的 $n$ 行中，第 $i$ 行包含两个正实数 $x_i,y_i$​，表示第 $i$ 只小猪坐标为 $(x_i,y_i)$。

### 输出格式

输出包含一个正整数，表示相应的关卡中，最多一次可以打中几只小猪。

### 输入输出样例

#### 输入

    5
    1.00 5.00
    2.00 8.00
    3.00 9.00
    4.00 8.00
    5.00 5.00

#### 输出

    5

#### 解释

这组数据中有 $5$ 只小猪，但经过观察我们可以发现它们的坐标都在抛物线 $y = -x^2 + 6x$ 上，故 Kiana 发射一只小鸟最多可消灭 $5$ 只小猪。

### 数据范围

因为时间比较紧我还没写好题解。。。数据范围就作为参考就好。  
（我会说这题是我半小时内赶工出来的吗？）  
![Nervous](Images/P1.jpg)  
（简单）$n <= 300$  
（困难）$n <= 1000$  
（不可能）$n <= 3000$

### 来源

NOIP2016 Day2 愤怒的小鸟  
<https://www.luogu.org/problem/P2831>