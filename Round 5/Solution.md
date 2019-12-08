# 第十四周脑力风暴答案

我们又回来啦  
这次是真的最后一次见面了呢  
所以不管你是随意点进来的还是认真想来看的  
都请暂驻脚步...  
那，话不多说

## 一道可爱的数学题

有一说一，定积分的证明题真的很令人头疼  
害，证明题都没好到哪去  

设 $f(x)$ 是连续函数且 $a>0$ , 证明下列等式成立：  

${\textstyle \int_1^a f(x^2 +\frac{a^2}{x^2}) \frac {1}{x}\,dx} = {\textstyle \int_1^a f(x + \frac{a^2}{x}) \frac {1}{x}\,dx}$

证明：

令 $x^2 = t$,  

$$
\begin{aligned}
则左 & = {\textstyle \int_1^a f(x^2 + \frac{a^2}{x^2}) \frac {1}{x}\,dx}\\
 & = {\textstyle \int_1^{a^2} f(t + \frac{a^2}{t}) \frac {1}{\sqrt t}\,d\sqrt t}\\
 & = {\textstyle \frac{1}{2} \int_1^{a^2} f(t + \frac{a^2}{t}) \frac {1}{t}\,dt}\\
 & = {\textstyle \frac{1}{2} \int_1^{a} f(t + \frac{a^2}{t}) \frac{1}{t}\,dt} + {\textstyle \frac{1}{2} \int_a^{a^2} f(t + \frac{a^2}{t}) \frac{1}{t}\,dt}\\
\end{aligned}
$$

令 $\frac{a^2}{t} = u$, 可得  

$$
\begin{aligned}
{\textstyle \int_a^{a^2} f(t + \frac{a^2}{t}) \frac{1}{t}\,dt} & = {\textstyle \int_a^{1} f(u + \frac{a^2}{u}) \frac{u}{a^2} (-\frac {a^2}{u^2}) \,du}\\
 & = {\textstyle \int_1^{a} f(u + \frac{a^2}{u}) \frac{1}{u} \,du}\\
 & = {\textstyle \int_1^{a} f(t + \frac{a^2}{t}) \frac{1}{t} \,dt}\\
\end{aligned}
$$

故 ${\textstyle \int_1^a f(x^2 +\frac{a^2}{x^2}) \frac {1}{x}\,dx} = {\textstyle \int_1^a f(x + \frac{a^2}{x}) \frac {1}{x}\,dx}$

## 南蛮图腾
