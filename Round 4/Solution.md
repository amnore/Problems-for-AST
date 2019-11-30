# 第十二周脑力风暴答案

我们又回来啦~  
上期不是很难所以这些答案就显得无关紧要啦  
如果dalao们有别的优解一定要来群里一展风采呀~  
（**pyg** 你在看嘛？？？？就是你！）  
那话不多说，放答案  

---

## 那道不定积分

不定积分 $\large I = { \int \frac{e^{-\sin x}\sin 2x}{(1 - \sin x)^{2}}\,dx} = ?$

由于 $\large I = { 2\int \frac{e^{-\sin x}\sin x\cos x}{(1 - \sin x)^{2}}\,dx}$  

令 $\large \sin x = \upsilon$  

则有  
$$
\begin{aligned}
原式 & = { 2\int \frac{e^{-\upsilon}\upsilon}{(1 - \upsilon)^{2}}\,d\upsilon}\\
 & = {2\int \frac{e^{-\upsilon}(\upsilon - 1 + 1)}{(1 - \upsilon)^{2}}\,d\upsilon}\\
 & = {2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} + {2\int \frac{e^{-\upsilon}}{(1 - \upsilon)^{2}}\,d\upsilon}\\
 & = {2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} - {2\int e^{-\upsilon}\,d\frac{1}{\upsilon - 1}}\\
 & = {2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} - 2({\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} + e^{-\upsilon}\frac{1}{\upsilon - 1}) \\
 & = -2e^{-\upsilon}\frac{1}{\upsilon - 1} + C\\
 & = \frac{-2e^{-\sin x}}{1 - \sin x} + C
\end{aligned}
$$

---

## 斐波拉契拆分

首先大家应该会知道这东西是不能暴力解决的对吧？😂

我们首先来观察一下斐波拉契数的规律。我们知道 $Fib_i = Fib_{i-1} + Fib_{i-2} (i \ge 2)$，也就是说，每一个斐波拉契数都可以表示为它的前两项的和，而前两项又可以表示为更之前项的和......也就是说，每一个斐波拉契数可以表示为它之前的**任意一项**和其余若干项的和。

为了方便说明，我们把使得数的个数最少的分解称作“最小分解”。  
下面我们来证明这个东西：  
$\forall n \in \N^+, \exists Fib_i + A$ 为 $n$ 的一个最小分解，其中 $Fib_i$ 是小于等于 $n$ 的最大斐波拉契数，$A$ 为 $n-Fib_i$ 的一个最小分解（或者 $A$ 为空）。  
我们考虑另一个分解 $n = Fib_j + B (Fib_j \lt Fib_i)$，由于 $Fib_i$ 可以分解为 $Fib_j$ 和其他斐波拉契数的和，所以我们又有 $Fib_i + A = Fib_j + B + C$，其中 $C$ 为 $Fib_i -Fib_j$ 的一个最小分解。  
显然 $A$ 中数的个数小于等于 $B$ 和 $C$ 个数的和。由此我们证明了包含任意的 $Fib_j < Fib_i$ 的分解中数的个数不可能小于 $Fib_i + A$ 中的个数。由此，命题得证。

那么这有什么用呢？这表示对任意的 $n$，我们只需要找到小于等于它的最大的斐波拉契数 $Fib_i$，然后再找 $n-Fib_i$的最小分解就可以了。而这个 $Fib_i$ 显然是很好找的。

而现在我们再回过头来看看题目的其他条件$\cdots\cdots$这些明显就是为了这个方法出的嘛！  
当然，这其实就是著名的贪心思想。  
（其实我在做这道题的时候并没有证明这么多东西啦$\cdots\cdots$  
贪心思想正确性的证明很多时候都是一个很麻烦的事情，很少有人会在做题时去刚这些啦$\cdots\cdots$  
大部分时候都是凭自己的直觉写的。😂）

至于具体实现没有太多想要讲的。找 $Fib_i$ 的过程可以先把每一项斐波拉契数算出来存在一个数组里然后二分查找就行了。二分查找是什么？  
嗯$\cdots\cdots$还是一个一个找吧$\cdots\cdots$我没试过，不过应该不会太慢。  
自己看源码就懂了。
