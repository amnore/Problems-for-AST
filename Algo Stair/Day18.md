# Day18

关于[dijkstra 算法](https://blog.csdn.net/qq_35644234/article/details/60870719?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

先抽象一下数据结构，这是一个无向有权图，最大结点数是 1000，不算大，为了时间可以使用邻接矩阵来储存数据。

然后就用 dijkstra 算法就行了，没有什么多余的措施(我不知道驾驶员干嘛用的)。

这是一个 caiji 的代码。

```c++
#include <cstdlib>
#include <iostream>

using namespace std;

class graph {
 public:
  graph(int vertex = 0, int edge = 0);
  ~graph();
  void creategraph();
  void dijkstra();
  bool *distate;
  int *dis;
  int vertex;
  int edge;
  int **matrix;
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
      cout << one.dis[i] << ' ';
    }
  }
  return 0;
}

graph::graph(int vertex, int edge) {
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

graph::~graph() {
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
    this->matrix[ori][des] = this->matrix[des][ori] = wei;
    if (!ori) {
      this->dis[des] = wei;
    } else if (!des) {
      this->dis[ori] = wei;
    }
  }
}

void graph::dijkstra() {
  int count = 1;
  while (count != this->vertex) {
    int minindex = 0, min = INF;
    for (int i = 0; i < this->vertex; i++) {
      if (this->distate[i] && this->dis[i] < min) {
        minindex = i;
        min = this->dis[i];
      }
    }
    this->distate[minindex] = false;
    count++;
    for (int i = 0; i < this->vertex; i++) {
      if (this->distate[i] && this->matrix[minindex][i] != INF &&
          (min + this->matrix[minindex][i]) < this->dis[i]) {
        this->dis[i] = min + this->matrix[minindex][i];
      }
    }
  }
}
```
