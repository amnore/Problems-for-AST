# 算法天梯：Day 8

（不这么讨厌的 dfs 水题 🤣

本讲解默认读者具有 dfs 的基础知识，还不会 dfs 的人请到 OI Wiki 自行食用：<https://oi-wiki.org/search/dfs/>

由于这题的数据规模非常小（$n \le 20$），我们可以直接考虑暴搜。
我们先把每两个字符串拼接后减少的长度算出来（如果无法拼接则设为一个不可能的值，比如我设为 $0$），之后直接 dfs 找最大的长度就行了。  
由于每个字符串最多只能用两次，我们也设置一个数组来存储使用的次数，当碰到已经用过两次的就直接跳过。同时，在 dfs 过程中也要维护这个数组的内容。

具体代码如下：

```c++
#include <iostream>
#include <string>
using namespace std;
int n;
string str[20];
int cat_len[20][20];
int mlen(string str1, string str2)  // 计算两个字符出拼接后减少的长度，如果可以拼接则返回一个负数，如果不能则返回 0
{
    int minlen = min(str1.length(), str2.length());
    for (int i = 1; i < minlen; ++i)
        if (str1.compare(str1.length() - i, i, str2, 0, i) == 0)
        // 比较第一个字符串的末尾 length - i 个字符与第二个字符串的前 length - i 个字符
            return -i;
    return 0;
}
int usecnt[20]; // 每个字符使用的次数，dfs 过程中会更新
int dfs(int curr)
{
    ++usecnt[curr]; // 表示该字符串使用了一次
    int maxlen = 0; // 以当前字符串开头的最大长度
    for (int i = 0; i < n; ++i)
        if (usecnt[i] < 2 && cat_len[curr][i] != 0)
            maxlen = max(maxlen, dfs(i) + cat_len[curr][i]);
            // 更新最大长度
    --usecnt[curr]; // 退出一层递归的时候要把对应字符串的使用次数 - 1
    return maxlen + str[curr].length();
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> str[i];
    char first;
    cin >> first;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cat_len[i][j] = mlen(str[i], str[j]);
    int maxlen = 0;
    for (int i = 0; i < n; ++i)
        if (str[i].front() == first)
            maxlen = max(maxlen, dfs(i));   // 计算以第 i 个字符串开头的最大长度，并与之前所得的结果作比较
    cout << maxlen;
    return 0;
}
```
