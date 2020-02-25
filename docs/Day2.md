# 算法天梯：Day 2

（水题 😁  
这题我们把 1000 以内的整数一个一个遍历一遍就好了，然后每个整数进行检验，如果满足条件就输出。  
至于具体的检验方法，我们可以把这个数分解成个位、十位和百位，然后对 0~9 的每个数字设置一个标志，当这个数字出现的时候就把标志置为一。如果某一个标志已经被置为一了说明对应的数字已经出现了两次，那么这个数就不满足要求。

具体代码见下：

```c++
#include <iostream>
using namespace std;
bool check(int num)
{
    bool used[10] = {false};    // 标志
    for (int i = 1; i < 4; ++i)
    {
        int n = num * i;
        for (int j = 0; j < 3; ++j) // 依次检查个位、十位和百位
        {
            int m = n % 10;
            if (m == 0 || used[m])  // 0 不允许出现在数字中
                return false;
            used[m] = true;
            n /= 10;
        }
    }
    return true;
}
int main()
{
    for (int i = 123; i < 333; ++i)
        if (check(i))   // 检查这个数是否符合要求
            cout << i << ' ' << i * 2 << ' ' << i * 3 << '\n';
    return 0;
}
```
