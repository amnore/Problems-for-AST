# 算法天梯：Day 17

（有点难的二分图水题 🥴

本题解假设读者具有图论、二分图和二分猜答案的基本知识，否则请到 OI Wiki、《离散数学结构》自行食用。  
图论：参见 Day 14 题解  
二分图：<https://oi-wiki.org/graph/bi-graph/>  
二分猜答案：<https://oi-wiki.org/basic/binary/>

这题的描述再清楚不过了，你们就不用我说该怎么写了吧？  
（显然如果某个比较小的破坏值可以满足要求，那么比较大的破坏值一定可以满足，于是我们可以猜答案然后用二分图来验证

具体代码如下：

```c++
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge
{
    int to; // 所连另一位同学的编号
    int destruction;    // 这一对的破坏值
};
vector<Edge> stu[20001];    // 班级里的同学
int n, m;
int sat[20001]; // 某个同学是在第一组还是第二组
bool chk(int max_des)
{
    fill_n(sat, 20001, -1); // 所有同学最初都未分配
    for (int i = 1; i <= n; ++i)
        if (sat[i] == -1)
        {
            sat[i] = 0; // 未分配的可以任意分配，这里分配到第一组
            queue<int> qu;
            qu.push(i);
            while (!qu.empty())
            {
                int t = qu.front();
                qu.pop();
                for (Edge e : stu[t])
                {
                    if (e.destruction <= max_des)   // 由于每个同学的边已经按照破坏值排序，所以直接跳过
                        break;
                    if (sat[e.to] == 1 - sat[t])    // 所连的同学已经被分配到了另一个组；跳过
                        continue;
                    if (sat[e.to] == sat[t])    // 两者分配到了同一个组，不满足要求
                        return false;
                    sat[e.to] = 1 - sat[t]; // 分配到另一个组
                    qu.push(e.to);
                }
            }
        }
    return true;
}
int main()
{
    cin >> n >> m;
    int maxd = 0, mind = INT32_MAX; // 二分的上下界
    for (int i = 0; i < m; ++i)
    {
        int x, y, p;
        cin >> x >> y >> p;
        stu[x].push_back({y, p});
        stu[y].push_back({x, p});
        maxd = max(maxd, p);
        mind = min(mind, p);
    }
    for (int i = 1; i <= n; ++i)
        sort(stu[i].begin(), stu[i].end(), [](Edge a, Edge b) { return a.destruction > b.destruction; });
        // 将一个同学所连的边按照破坏值从大到小排序
    mind = -1;
    int mid;
    for (mid = (maxd + mind) / 2; mind < maxd - 1; mid = (maxd + mind) / 2)
    // 二分猜
    {
        if (chk(mid))
            maxd = mid;
        else
            mind = mid;
    }
    cout << maxd;
    return 0;
}
```
