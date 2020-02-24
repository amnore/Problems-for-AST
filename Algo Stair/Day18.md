# D18

关于[dijkstra 算法](https://blog.csdn.net/qq_35644234/article/details/60870719?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

先抽象一下数据结构，这是一个无向有权图，最大结点数是 1000，不算大，为了时间可以使用邻接矩阵来储存数据。

然后就用 dijkstra 算法就行了，除了判断这条路能不能走(不能把驾驶员累着)，没有什么多余的措施。

这是一个 caiji 的代码。

```c++
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

class graph {// 图，邻接矩阵
 public:
  graph(int vertex = 0, int edge = 0);
  ~graph();
  void creategraph();
  void dijkstra();
  bool *distate;// 是否已经确定0 到这个点的最短路径
  int *dis;// 最短路径存储数组，不一定是确定值，正数表示驾驶员1可以走，负数反之
  int vertex;
  int edge;
  int **matrix;// 矩阵
};

const int INF = __INT_MAX__;

int main() {
  int vertex, edge;
  cin >> vertex >> edge;
  graph one(vertex, edge);
  one.creategraph();
  one.dijkstra();
  for (int i = 0; i < one.vertex; i++) {
    if (one.dis[i] == INF) {
      cout << -1 << ' ';
    } else {
      cout << abs(one.dis[i]) << ' ';
    }
  }
  return 0;
}

graph::graph(int vertex, int edge) {// 构造函数
  this->vertex = vertex;
  this->edge = edge;
  this->matrix = new int *[vertex];
  for (int i = 0; i < vertex; i++) {
    this->matrix[i] = new int[vertex];
  }
  this->dis = new int[vertex];
  this->distate = new bool[vertex];
  for (int i = 0; i < vertex; i++) {
    this->dis[i] = INF;
    this->distate[i] = true;
    for (int j = 0; j < vertex; j++) {
      this->matrix[i][j] = INF;
    }
  }
  this->dis[0] = 0;
  this->distate[0] = false;
}

graph::~graph() {// 析构函数
  for (int i = 0; i < this->vertex; i++) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;
  delete[] this->dis;
  delete[] this->distate;
}

void graph::creategraph() {
  for (int i = 0; i < this->edge; i++) {
    int ori, des, wei, who;
    cin >> ori >> des >> wei >> who;
    this->matrix[ori][des] = this->matrix[des][ori] = (who == 1) ? wei : -wei;// 驾驶员
    if (!ori) {
      this->dis[des] = wei;
    } else if (!des) {
      this->dis[ori] = wei;
    }
  }
}

void graph::dijkstra() {
  int count = 1;// count表示已经确定几个结点，1表示确定了0自己
  while (count != this->vertex) {
    int minindex = 0, min = INF;
    for (int i = 0; i < this->vertex; i++) {
      if (this->distate[i] && abs(this->dis[i]) < abs(min)) {// 找到当前最小
        minindex = i;
        min = this->dis[i];
      }
    }
    this->distate[minindex] = false;// 找到后确认最短路径
    count++;
    for (int i = 0; i < this->vertex; i++) {// 判断以该节点为中介，可不可以得到通向别的结点的最小值
      if (this->distate[i] && this->matrix[minindex][i] != INF &&
          min * this->matrix[minindex][i] < 0 &&
          (abs(min) + abs(this->matrix[minindex][i])) < abs(this->dis[i])) {
        int tmp = abs(min) + abs(this->matrix[minindex][i]);
        this->dis[i] = (min > 0) ? -tmp : tmp;// 保持正负号以便判断接下来走向
      }
    }
  }
}
```
