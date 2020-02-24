# D3

提示正解：[约瑟夫环问题](https://blog.csdn.net/u011500062/article/details/72855826)。

当然，事实上不用管这是什么问题--如果用数组，需要解决的是数组到了头怎么继续循环，即一个判断；如果用链表，那么用循环链表也可以很方便解决。

解决了框架，细节就是怎么把已经被抛弃的学生踢出去，注意顺序。

下面是一个caiji的代码(大家尽情骂他吧)。

```c

#include <stdio.h>

int main() {
  int len = 0, k = 0, m = 0;
  scanf("%d %d %d", &len, &k, &m);
  int store[len];// 存储编号
  for (int i = 0; i < len; i++) {
    store[i] = i + 1;
  }
  int currentk = 0, currentm = len - 1, count = 0;
  // currentk指以k为单位的循环指向哪个学生，currentm类似
  // count指已经踢掉多少个学生
  while (1) {
    if (count == len) {
      break;
    }
    int countk = 1, countm = 1;
    // countk指本次循环已经数了多少个同学
    while (1) {
      if (countk == k) {// 数了k个
        if (store[currentk] < 0) {// 指向的学生是已经被踢掉的
          if (currentk == len - 1) {
            currentk = 0;
          } else {
            currentk++;
          }
          continue;// 继续循环
        } else {
          break;// 找到本次循环目标
        }
      }
      if (store[currentk] > 0) {// 指向的学生未被踢出
        countk++;
      }
      if (currentk == len - 1) {// 数组到头了
        currentk = 0;
      } else {
        currentk++;
      }
    }
    while (1) {// 和上面循环类似
      if (countm == m) {
        if (store[currentm] < 0) {
          if (currentm == 0) {
            currentm = len - 1;
          } else {
            currentm--;
          }
          continue;
        } else {
          break;
        }
      }
      if (store[currentm] > 0) {
        countm++;
      }
      if (currentm == 0) {
        currentm = len - 1;
      } else {
        currentm--;
      }
    }
    if (currentk == currentm) {// 找到班长了
      printf("%d", store[currentk]);
      break;
    } else {
      printf("%d %d", store[currentk], store[currentm]);
      store[currentk] = -store[currentk];
      store[currentm] = -store[currentm];// 踢人
      count = count + 2;// 踢了俩
      if (count != len) {
        printf(" ");
      }
      if (currentk == len - 1) {
        currentk = 0;
      } else {
        currentk++;
      }
      if (currentm == 0) {
        currentm = len - 1;
      } else {
        currentm--;
      }
    }
  }
  return 0;
}
```