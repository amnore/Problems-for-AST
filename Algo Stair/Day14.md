# 算法天梯：Day 14

（还行的拓扑排序水题😵

本讲解默认读者具有图论和拓扑排序的基本知识，否则请到 OI Wiki 或《离散数学结构》自行食用。  
图论基本概念：<https://oi-wiki.org/graph/concept/>、《离散数学结构》4.2、4.3  
拓扑排序：<https://oi-wiki.org/graph/topo/>

知道了上面的东西这题也就自然解决了吧？我们把每个人看作一个点，把一个人排在另一个人的前面这个关系作为一条有向边，之后拓扑排序即可得到结果。  
不过由于需要字典序最小，我们可以使用一个优先队列来代替拓扑排序中原本所用的队列。

具体代码如下：

```c++
#include <queue>
#include <iostream>
using namespace std;
const int maxn = 600000;
vector<int> nodes[maxn];    // 某个学生所连的边
int in[maxn];   // 入度
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int f, t;
        cin >> f >> t;
        nodes[f].emplace_back(t);
        ++in[t];
    }
    // 下面在拓扑排序的过程中输出结果
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
        if (in[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        int n = pq.top();
        pq.pop();
        for (int t : nodes[n])
        {
            --in[t];
            if (in[t] == 0)
                pq.push(t);
        }
        cout << n << (pq.empty() ? "" : " ");
    }
    return 0;
}
```
