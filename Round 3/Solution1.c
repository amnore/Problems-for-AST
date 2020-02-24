#include <limits.h>
#include <stdio.h>
#define MAX_N 30000

// frac[i] = i!
int frac[MAX_N + 1] = {1};

int nums[MAX_N];
int ans[MAX_N];

// Swap nums[a] with nums[b].
void swap(int a, int b)
{
    int nc = nums[a];
    nums[a] = nums[b];
    nums[b] = nc;
}

// Part nums[begin,...,end-1] recursively to find the Kth smallest number.
void partition(int begin, int end, int k)
{
    int pivot = (begin + end) / 2;
    swap(pivot, end - 1);
    int i = begin;
    for (int j = begin; j < end; ++j)
        if (nums[j] <= nums[end - 1])
            swap(i++, j);
    if (end - begin <= 2)
        return;
    if (i < k)
        partition(i, end, k);
    else
        partition(begin, i, k);
}

// Find the Kth smallest number in num[0,...,total-1], move it to the end, and return it.
int Kth_smallest_num(int k, int total)
{
    partition(0, total, k);
    swap(k - 1, total - 1);
    return nums[total - 1];
}

void find(int depth, int n, int k)
{
    if (depth == n)
        return;
    int a = (k - 1) / frac[n - depth - 1];
    ans[depth] = Kth_smallest_num(a + 1, n - depth);
    find(depth + 1, n, k - a * frac[n - depth - 1]);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        nums[i] = i + 1;
    for (int i = 1; i <= n; ++i)
        frac[i] = (long long)frac[i - 1] * (long long)i > (long long)INT_MAX ? INT_MAX : frac[i - 1] * i;
    find(0, n, k);
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    return 0;
}
