# Day6

这个长生不老的筒子看漫画很有特点--一本漫画必须在整数个小时内看完，而且非常专一--在单位时间内(小时)内不会看第二本书。

此外，这位筒子奢望可以享受阅读，尽可能要读得慢，于是最慢的速度是 1，最快的速度是 max(page[i])，所有答案不过是在这两个数之间，包括这两个数的整数。

于是可以想到用搜索算法找出最小正解即可。因为时间复杂度的要求，时间要尽可能缩短，所以二分搜索是好朋友。

下面是一位 caiji 的垃圾代码(这份代码的二分搜索其实很成问题，如果 begin > end, return 回来的无法确定是比答案大还是小，于是处理复杂了点)。

```c
#include <stdio.h>

int num = 0, leavetime = 0, page[10001] = {0};

int binary_search(int begin, int end);
int judge(int minpage);

int main() {
  scanf("%d %d", &num, &leavetime);
  int max = 0;
  for (int i = 1; i < num + 1; i++) {
    scanf("%d", &page[i]);
    if (page[i] > max) {
      max = page[i];
    }
  }
  int result = binary_search(1, max);
  if (result > 0) {
    while (result > 1 && !judge(result - 1)) {
      result--;
    }  //确保找到最小的那个
    printf("%d\n", result);
  } else {
    int trial = -result;
    int count1 = judge(trial + 1), count2 = judge(trial);
    while (trial >= 1 && !(count1 > 0 && count2 < 0)) {
      if (count2 > 0) {
        trial--;
      } else {
        trial++;
      }
      if (trial < 1) {
        break;
      }
      count1 = judge(trial + 1);
      count2 = judge(trial);
    }
    printf("%d\n", trial + 1);
  }
  return 0;
}

int binary_search(int begin, int end) {
  int medium = begin + (end - begin) / 2;
  if (begin > end) {
    return -(end + 1);
  }
  int result = judge(medium);
  if (result == 0) {
    return medium;
  } else if (result < 0) {
    return binary_search(medium + 1, end);
  } else {
    return binary_search(begin, medium - 1);
  }
}

int judge(int minpage) {
  int count = 0;
  for (int i = 1; i < num + 1; i++) {
    if (page[i] % minpage == 0) {
      count = count + page[i] / minpage;
    } else {
      count = count + page[i] / minpage + 1;
    }
  }
  return leavetime - count;
}
```
