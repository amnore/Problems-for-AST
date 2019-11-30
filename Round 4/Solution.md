# 第十二周脑力风暴答案

我们又回来啦~  
上期不是很难所以这些答案就显得无关紧要啦    
如果dalao们有别的优解一定要来群里一展风采呀~    
(pyg你在看嘛？？？？就是你！)  
那话不多说，放答案  

---

## 那道不定积分

不定积分 $I = {\textstyle \int \frac{e^{-\sin x}\sin 2x}{(1 - \sin x)^{2}}\,dx} = ?$

由于$I = {\textstyle 2\int \frac{e^{-\sin x}\sin x\cos x}{(1 - \sin x)^{2}}\,dx}$  

令 $\sin x = \upsilon$  

则有 原式 $= {\textstyle 2\int \frac{e^{-\upsilon}\upsilon}{(1 - \upsilon)^{2}}\,d\upsilon} = {\textstyle 2\int \frac{e^{-\upsilon}(\upsilon - 1 + 1)}{(1 - \upsilon)^{2}}\,d\upsilon} = {\textstyle 2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} + {\textstyle 2\int \frac{e^{-\upsilon}}{(1 - \upsilon)^{2}}\,d\upsilon} = {\textstyle 2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} - {\textstyle 2\int e^{-\upsilon}\,d\frac{1}{\upsilon - 1}} = {\textstyle 2\int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} - 2({\textstyle \int \frac{e^{-\upsilon}}{\upsilon - 1}\,d\upsilon} + e^{-\upsilon}\frac{1}{\upsilon - 1}) = -2e^{-\upsilon}\frac{1}{\upsilon - 1} + C = \frac{-2e^{-\sin x}}{1 - \sin x} + C$

---
