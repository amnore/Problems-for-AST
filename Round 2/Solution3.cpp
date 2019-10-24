// n <= 3000 时解法
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>

#define MAX_N 3000
#define DELTA 1e-6
bool my_equal(double a, double b)
{
    return fabs(a - b) < DELTA;
}

// 坐标 (x, y)
double x[MAX_N], y[MAX_N];

// 抛物线参数 (a, b)
struct MyPair
{
    double a;
    double b;
    friend bool operator==(MyPair p1, MyPair p2)
    {
        return my_equal(p1.a, p2.a) && my_equal(p1.b, p2.b);
    }
};

// 由 i, j 两只小猪的坐标计算 a, b
MyPair getab(int i, int j)
{
    // i, j 的 x 坐标相同，舍去 (取 a > 0, 之后会忽略掉)
    if (my_equal(x[i], x[j]))
        return MyPair{1.0, 0.0};

    double xi2 = x[i] * x[i], xj2 = x[j] * x[j];
    double k = xi2 * x[j] - xj2 * x[i];
    return MyPair{(x[j] * y[i] - x[i] * y[j]) / k, (xi2 * y[j] - xj2 * y[i]) / k};
}
struct MyHash
{
    using argument_type = MyPair;
    using result_type = std::hash<double>::result_type;
    const std::hash<double> _hash;
    result_type operator()(argument_type pr) const
    {
        return _hash(floor(pr.a / DELTA)) ^ _hash(floor(pr.b / DELTA));
    }
};
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];

    std::unordered_map<MyPair, int, MyHash> m;
    std::unordered_map<int, int> inv; // i * (i - 1) / 2 -> i
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
    for (auto &pr : m)
        answer = std::max(inv[pr.second], answer);
    std::cout << answer;
    return 0;
}