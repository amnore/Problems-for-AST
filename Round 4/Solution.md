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

大家应该会知道这东西是不能暴力解决的对吧？😂  
这是著名的贪心思想。  
贪心思想正确性的证明很多时候都是一个很麻烦的事情，很少有人会在做题时去刚这些啦$\cdots\cdots$  
大部分时候都是凭自己的直觉写的。😂）  
具体实现没有太多想要讲的。找 $Fib_i$ 的过程可以先把每一项斐波拉契数算出来存在一个数组里然后二分查找就行了。二分查找是什么？  
嗯$\cdots\cdots$还是一个一个找吧$\cdots\cdots$我没试过，不过应该不会太慢。  
自己看源码就懂了。
