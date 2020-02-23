# 算法天梯：Day 11

（并不讨厌的队列模拟水题 😙

这题就是模拟，我们按照列车出站的顺序考虑，具体的模拟逻辑如下：

1. 如果当前出站的列车恰好是进站的列车，那么就让这辆车直接过。
2. 如果当前出站的列车恰好是站内的第一辆车，就让这辆车出站。
3. 排除以上两种情况，则让当前进站的列车进站。

而当一下情况出现的时候，那么就不能实现相应的顺序：

1. 最后一辆列车已经进站，但是站内的第一辆列车并不是需要出站的车。
2. 需要某辆列车进站时，车站已满。

根据上面的逻辑，我们就可以写出相应的代码了：

```c++
#include <iostream>
#include <queue>
using namespace std;
int out[1000];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> out[i];
    queue<int> qu;  // 车站内停靠的列车，用队列表示
    int i = 0, j = 0;   // 进、出站的车
    bool sgn = true;    // 表示能否满足给定的顺序
    while (i < n || !qu.empty())
    {
        while (!qu.empty() && qu.front() == out[j]) // 站内第一辆车是需要出站的车
        {
            qu.pop();
            ++j;
        }
        if (i < n)
        {
            if (i == out[j])    // 正要进站的车是需要出站的车
            {
                ++i;
                ++j;
            }
            else    // 不满足上述情况
                qu.push(i++);
        }
        if (qu.size() > m)  // 站内的车总数大于车站容量
        {
            sgn = false;
            break;
        }
        if (i == n && !qu.empty() && qu.front() != out[j])  // 列车已经全部进站但仍然无法满足
        {
            sgn = false;
            break;
        }
    }
    cout << (sgn ? "YES" : "NO");
    return 0;
}
```
