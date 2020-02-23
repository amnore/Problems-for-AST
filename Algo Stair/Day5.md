# 算法天梯：Day 5

（讨厌的高精度水题#5😕  
这题没什么好说的，直接写一个高精度乘法就行了。  
（朴素）高精度乘法的本质就是把多位数相乘分解为每一位的数相乘再乘上位数，和我们手算多位数乘法的原理相同。  
具体而言，假设两个两位数相乘：

$$
\begin{aligned}
&\overline{a_1a_2} * \overline{b_1b_2}\\
&= (a_1*10+a_2)(b_1*10+b_2)\\
&= a_1b_1*10^2\\
& + (a_1b_2+a_2b_1)*10^1\\
&+a_2b_2*10^0
\end{aligned}
$$

而当我们使用数组来存储一个数的时候，这个数每一位的位数则刚好可以和数组的下标对应起来了，由此我们就可以相对简单地实现高精度乘法。  
需要注意的是，我们把一个数反过来存，比如对于 $123=3*10^0+2*10^1+1*10^2$，我们使 $a_0=3, a_1=2, a_2=3$，这样就可以刚好对应起来了。  
在进行乘法时，我们分别把每一位上的数相乘，把结果加到对应的位上。同时注意当某一位上的数大于 $10$ 之后就需要进位。  
关于高精度数四则运算的详解可自行到 OI Wiki 食用：<https://oi-wiki.org/math/bignum/>

本题具体代码如下：

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
string multiply(string a, string b)
{
    string ret;
    ret.resize(a.size() + b.size());    // 调整字符串大小，防止数组越界
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
        {
            ret[i + j] += (a[i] - '0') * (b[j] - '0');
            // 把两位的乘积加到对应位上
            // 我是用的 std::string 存的这个数对应的字符串，因此需要把一位上的字符减去 '0' 得到对应的数
            if (ret[i + j] >= 10)   // 进位
            {
                ret[i + j + 1] += ret[i + j] / 10;
                ret[i + j] %= 10;
            }
        }
    int len = 0;
    for (int i = 0; i < ret.size(); ++i)
    {
        if (ret[i])
            len = i + 1;
        ret[i] += '0';
    }
    ret.resize(len); // 调整字符串的大小，去除前导零
    return ret;
}
int main()
{
    int n;
    string num1, num2;
    cin >> n;
    cin >> num1;
    reverse(num1.begin(), num1.end());  // 把一个数反过来
    while (--n)
    {
        cin >> num2;
        reverse(num2.begin(), num2.end());
        num1 = multiply(num1, num2);
    }
    copy(num1.rbegin(), num1.rend(), ostream_iterator<char>{cout}); // 输出最后结果
}

```
