#include <stdio.h>
#define MAX_N 10000000
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a < b ? a : b)
long long left_max_height[MAX_N];
long long right_max_height[MAX_N];
int height[MAX_N];
int main()
{
    int n;
    long long result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &height[i]);
    for (int i = 1; i < n; ++i)
        left_max_height[i] = max(left_max_height[i - 1], height[i - 1]);
    for (int i = n - 2; i > 0; --i)
        right_max_height[i] = max(right_max_height[i + 1], height[i + 1]);
    for (int i = 0; i < n; ++i)
        result += max(min(left_max_height[i], right_max_height[i]) - height[i], 0);
    printf("%lld", result);
    return 0;
}