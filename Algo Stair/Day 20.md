# 算法天梯：Day 20

（可能是全场最难的树的直径水题 🤢  
我们先从一个看起来和这道题毫不相关的点开始：  
在一棵树中，从一个结点出发，遍历这棵树的所有节点，最后回到这个节点，所经过的边数最少是多少？  
答案是 $2(n-1)$ 条，其中 $n$ 是这棵树的节点个数。  
我们考虑从一个父节点到一个子节点再回来，那么这个父节点与子节点之间的那条边就经过了两次；逐层递归可得从开始的那个节点（根节点）经过这个过程，树的每一条边都经过了两次。

那么这和我们的这道题有什么关系呢？  
这道题中我们依然要遍历所有的节点，唯一的差别是不需要回到开始的那个节点。容易证明这样我们最多可以少经过从开始节点到结束节点的那条路径上的所有的边一次。  
于是这道题就转化成了找出合适的开始和结束节点使得他们之间的距离是一棵树上最长的一条简单路径（即树的直径）。

关于树的直径的求法，有以下定理：

到树上任意一点的距离最长的一点必定是直径的一个端点。

这个定理的具体证明见这个网页：  
<https://ikely.me/2014/09/21/%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84/>

于是我们先从任意一点 dfs 或 bfs 找出距离最大的一个点，然后从这个点重复一次，就可以找出直径的长度了。

具体代码如下：

```c++
#include <iostream>
using namespace std;
struct Node
{
    int edges[3] = {-1, -1, -1};    // 与一个二叉树上的一个节点所连的点最多有三个
    int parent = -1;
    int depth = 0;  // 到根节点的距离
};
Node arr[100000];
int dfs(int curr, int depth, int parent)    // 第二次 dfs
{
    int maxd = depth;
    for (int i = 0; i < 3 && arr[curr].edges[i] != -1; ++i)
    {
        if (arr[curr].edges[i] == parent)
            continue;
        maxd = max(maxd, dfs(arr[curr].edges[i], depth + 1, curr));
    }
    return maxd;
}
int main()
{
    int n;
    cin >> n;
    int maxd = 0, maxdi;
    for (int i = 0; i < n; ++i)
    {
        int t;
        int k = 1;
        arr[i].edges[0] = arr[i].parent;    // 添加父节点与子节点之间连的边
        for (int j = 0; j < 2; ++j)
        {
            cin >> t;
            if (t != -1)
            {
                // 我在输入数据的同时也在进行第一次遍历，大家不要学我
                arr[i].edges[k++] = t;
                arr[t].parent = i;
                arr[t].depth = arr[i].depth + 1;
                if (arr[t].depth > maxd)    // 找出到根节点距离最大的节点
                {
                    maxd = arr[t].depth;
                    maxdi = t;
                }
            }
        }
    }
    swap(arr[0].edges[0], arr[0].edges[1]); // 两次魔法操作（其实是把根节点的两条边换到前面去）
    swap(arr[0].edges[1], arr[0].edges[2]);
    cout << 2 * (n - 1) - dfs(maxdi, 0, -1);
    // 以第一次找到的节点为根节点遍历，找到距离最大的节点；
    // 2 (n - 1) - 直径长度即为最短距离
    return 0;
}
```
