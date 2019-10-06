#include <stdio.h>
#define MAX_N 100000
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a < b ? a : b)
int left_max_height[MAX_N];
int right_max_height[MAX_N];
int height[MAX_N];
int main()
{
    int n;
    int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &height[i]);
    for (int i = 1; i < n; ++i)
        left_max_height[i] = max(left_max_height[i - 1], height[i - 1]);
    for (int i = n - 2; i > 0; --i)
        right_max_height[i] = max(right_max_height[i + 1], height[i + 1]);
    for (int i = 0; i < n; ++i)
        result += max(min(left_max_height[i], right_max_height[i]) - height[i], 0);
    printf("%d", result);
    return 0;
}