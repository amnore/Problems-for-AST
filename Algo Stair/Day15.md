# Day15

这是一道深搜。只要不断地切割字符串，然后判断是否有不符合条件的数字存在，不符合条件就 return，最后自然会剩下一个解，输出即可。

切割字符串的长度是 1 或者 2，如果出现有数字>m 的，或者出现重复数字的，就是不符合要求。为了节省时间，设一个 flag，只要已经找到了，一路退出，不在别的查找上浪费时间。

下面是一个 caiji 的代码。

```c
#include <stdio.h>

const int maxsize = 50, maxcapacity = 100;
int state[50], result[50], flag = 0, max = 0;
// state存储数字是否已经存在，result存储当前找到的
void slice(char store[], int index, int sum);

int main() {
  char store[100] = {0};
  scanf("%s", store);
  slice(store, 0, 0);
  return 0;
}

void slice(char store[], int index, int sum) {
  if (flag) {
    return;
  }
  if (max == sum && (index > maxcapacity - 1 || !store[index])) {
    for (int i = 0; i < sum - 1; i++) {
      printf("%d ", result[i]);
    }
    printf("%d", result[sum - 1]);
    flag = 1;
    return;
  }
  int count1 = 0;
  for (int i = index; i < index + 1 && store[i]; i++) {
    count1 = count1 * 10 + store[i] - '0';
  }
  if (count1 && count1 <= maxsize && !state[count1]) {
    int tmp = max;
    if (count1 > max) {
      max = count1;
    }
    state[count1] = 1;
    result[sum] = count1;
    slice(store, index + 1, sum + 1);
    if (flag) {
      return;
    }
    max = tmp;
    state[count1] = 0;
    result[sum] = 0;
  }
  int count2 = 0;
  for (int i = index; i < index + 2 && store[i]; i++) {
    count2 = count2 * 10 + store[i] - '0';
  }
  if (count2 >= 10 && count2 <= maxsize && !state[count2]) {
    int tmp = max;
    if (count2 > max) {
      max = count2;
    }
    state[count2] = 1;
    result[sum] = count2;
    slice(store, index + 2, sum + 1);
    if (flag) {
      return;
    }
    max = tmp;
    state[count2] = 0;
    result[sum] = 0;
  }
}
```
