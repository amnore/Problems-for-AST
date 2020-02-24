#include <limits.h>
#include <stdio.h>
long long fib[100] = {1, 2};
long long ans[10000] = {0};
int upper_bound(int n, int end) {
  int begin = 0;
  while (end - begin > 1) {
    int mid = (begin + end) / 2;
    if (fib[mid] > n)
      end = mid;
    else
      begin = mid;
  }
  return end;
}
int main() {
  int n, t, end;
  scanf("%d", &t);
  for (int i = 2; i < n; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] > (long long)INT_MAX) {
      end = i;
      break;
    }
  }
  while (t--) {
    scanf("%d", &n);
    int k = 0;
    printf("%d =", n);
    while (n != 0) {
      int pos = upper_bound(n, end) - 1;
      ans[k++] = fib[pos];
      n -= fib[pos];
    }
    --k;
    printf(" %lld", ans[k]);
    --k;
    while (k >= 0) {
      printf(" + %lld", ans[k]);
      --k;
    }
    printf("\n");
  }
  return 0;
}
