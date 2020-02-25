# 算法天梯：Day 12

这道题有很多种做法，但是很遗憾，作为小白只能使用最简单最无脑的做法--直接按层遍历。

如果不会二叉树按层遍历，google 欢迎您。

这道题别的做法有的突破点是结点是按顺序编号的，并且可以通过计算深度来判断层数。

下面是一个 caiji 的代码(按层遍历那个，c 语言选手什么都得自己实现，体谅一下，那一大堆函数除了 BFS 别的都不重要)。

```c
#include <stdio.h>

typedef struct tree {
  int self;
  int left;
  int right;
} node;// 自己，左子树，右子树

typedef struct queue {
  node data[64];
  int front;
  int rear;
  int size;
} queue;

int maxsize = 0, real[30][15] = {0};

void BFS(node store[], queue aqueue);
void create_queue(queue *target, int max);
void enter_queue(queue *target, node thedata);
void delete_queue(queue *target, node *store);
int is_full(queue target);
int is_empty(queue target);

int main() {
  int sum = 0, count = 0, realresult[31] = {0};
  scanf("%d", &sum);
  queue aqueue;
  create_queue(&aqueue, 64);
  node store[sum + 1];
  for (int i = 1; i < sum + 1; i++) {
    store[i].self = i;
    scanf("%d %d", &store[i].left, &store[i].right);
  }
  store[0].self = 0;
  BFS(store, aqueue);// real[]里边已经存有各行的结点
  for (int i = 0; i < 30; i++) {
    int store = -1;
    for (int j = 0; j < 15; j++) {
      if (real[i][j] != 0) {
        store = real[i][j];
        realresult[count] = store;
        count++;
        break;
      }
    }
    for (int j = 14; j >= 0; j--) {
      if (real[i][j] != 0) {
        if (real[i][j] != store) {
          realresult[count] = real[i][j];
          count++;
        }
        break;
      }
    }
  }// 寻找边界结点
  for (int i = 0; i < 30; i++) {
    if (!realresult[i + 1]) {
      printf("%d", realresult[i]);
      break;
    }
    printf("%d ", realresult[i]);
  }
  return 0;
}

void BFS(node store[], queue aqueue) {// 最基本的按层遍历
  int count1 = 0, count2 = 0;
  enter_queue(&aqueue, store[1]);// root 结点
  enter_queue(&aqueue, store[0]);// 换层标志
  while (!is_empty(aqueue)) {
    node tmp;
    delete_queue(&aqueue, &tmp);// 出队列
    if (tmp.self) {// 不是换层标志
      real[count1][count2] = tmp.self;// count1层，第count2个
      count2++;
    } else {
      count2 = 0;
      count1++;
      if (!is_empty(aqueue)) {// 队列没空
        enter_queue(&aqueue, store[0]);// 换层标志
      }
      continue;
    }
    if (tmp.left != -1) {// 左子树不空
      enter_queue(&aqueue, store[tmp.left]);
    }
    if (tmp.right != -1) {// 右子树不空
      enter_queue(&aqueue, store[tmp.right]);
    }
  }
}

void create_queue(queue *target, int max) {
  maxsize = max;
  target->front = 0;
  target->rear = 0;
  target->size = 0;
}

void enter_queue(queue *target, node thedata) {
  if (is_full(*target)) {
    return;
  }
  target->data[target->rear] = thedata;
  target->size++;
  target->rear++;
  target->rear = target->rear % maxsize;
}

void delete_queue(queue *target, node *store) {
  if (is_empty(*target)) {
    return;
  }
  *store = target->data[target->front];
  target->front++;
  target->front = target->front % maxsize;
  target->size--;
}

int is_full(queue target) {
  if (target.size == maxsize) {
    return 1;
  }
  return 0;
}

int is_empty(queue target) {
  if (target.size == 0) {
    return 1;
  }
  return 0;
}
```

