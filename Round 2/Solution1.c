// n <= 1000 时的解法, O(n^3)

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_N 1000
#define DELTA 1e-6
#define max(a, b) (a > b ? a : b)
bool my_equal(double a, double b)
{
    return fabs(a - b) < DELTA;
}

// 坐标 (x, y)
double x[MAX_N], y[MAX_N];

// 抛物线参数 a, b
double a[MAX_N][MAX_N], b[MAX_N][MAX_N];

// 由 i, j 两只小猪的坐标计算 a, b
void getab(int i, int j)
{
    // i, j 的 x 坐标相同，舍去 (取 a > 0, 之后会忽略掉)
    if (my_equal(x[i], x[j]))
    {
        a[i][j] = 1.0;
        return;
    }

    double xi2 = x[i] * x[i], xj2 = x[j] * x[j];
    double k = xi2 * x[j] - xj2 * x[i];
    a[i][j] = (x[j] * y[i] - x[i] * y[j]) / k;
    b[i][j] = (xi2 * y[j] - xj2 * y[i]) / k;
}

// 由 i, j 两只小猪确定的抛物线打中的小猪数
int result[MAX_N][MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            getab(i, j);

    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            // 要求 a < 0
            if (a[i][j] > 0.0)
                continue;

            for (int k = 0; k < n; ++k)
                if (k == i || k == j || (my_equal(a[i][j], a[i][k]) && my_equal(b[i][j], b[i][k])))
                    ++result[i][j];
            answer = max(answer, result[i][j]);
        }

    printf("%d", answer);
    return 0;
}