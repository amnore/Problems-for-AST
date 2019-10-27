// n <= 2000 时解法，O(n^2logn)
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>

#define MAX_N 2000
#define DELTA 1e-6
bool my_equal(double a, double b)
{
    return fabs(a - b) < DELTA;
}
bool my_less(double a, double b)
{
    return a - b < -DELTA;
}

// 坐标 (x, y)
double x[MAX_N], y[MAX_N];

// 抛物线参数 (a, b)
struct MyPair
{
    double a;
    double b;

    // 重载小于运算符
    friend bool operator<(MyPair p1, MyPair p2)
    {
        return my_less(p1.a, p2.a) || (my_equal(p1.a, p2.a) && my_less(p1.b, p2.b));
    }
};

// 由 i, j 两只小猪的坐标计算 a, b
MyPair getab(int i, int j)
{
    MyPair ret;
    // i, j 的 x 坐标相同，舍去 (取 a > 0, 之后会忽略掉)
    if (my_equal(x[i], x[j]))
    {
        ret.a = 1.0;
        return ret;
    }

    double xi2 = x[i] * x[i], xj2 = x[j] * x[j];
    double k = xi2 * x[j] - xj2 * x[i];
    ret.a = (x[j] * y[i] - x[i] * y[j]) / k;
    ret.b = (xi2 * y[j] - xj2 * y[i]) / k;
    return ret;
}
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];

    std::map<MyPair, int> m;
    std::map<int, int> inv;
    // 由对数反算只数
    for (int i = 1; i <= n; ++i)
        inv[i * (i - 1) / 2] = i;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            MyPair tmp = getab(i, j);
            if (tmp.a > 0.0)
                continue;
            ++m[tmp]; // 将抛物线 (a, b) 在 map 中对应计数 +1
        }
    int answer = 0;
    for (std::map<MyPair, int>::iterator it = m.begin(); it != m.end(); ++it)
        answer = std::max(inv[it->second], answer);
    std::cout << answer;
    return 0;
}