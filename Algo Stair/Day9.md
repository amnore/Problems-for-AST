# D9

难得一见的水题。

通过前序遍历可以求出整颗树，在改变一下前序遍历中左子树和右子树输出顺序再比较一不一样即可。当然这种方法需要将空结点也储存一下。

下面是一个 caiji 的代码。

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int val;
  struct tree *left;
  struct tree *right;
} node;

int flag = 0, store1[200] = {0}, store2[200] = {0};

void create_tree(node **pnode);
void print_tree_1(node *pnode, int *index);
void print_tree_2(node *pnode, int *index);

int main() {
  node *head1 = NULL;
  node *head2 = NULL;
  int index1 = 0, index2 = 0;
  create_tree(&head1);
  create_tree(&head2);
  print_tree_1(head1, &index1);
  print_tree_2(head2, &index2);
  int flag1 = 1;
  for (int i = 0; i < 200; i++) {
    if (store1[i] != store2[i]) {
      flag1 = 0;
      break;
    }
  }
  if (flag1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

void create_tree(node **pnode) {
  int realdata = 0;
  flag = scanf("%d", &realdata);
  if (flag == EOF) {
    return;
  }
  if (realdata == -1) {
    return;
  }
  *pnode = (node *)malloc(sizeof(node));
  (*pnode)->val = realdata;
  (*pnode)->left = NULL;
  (*pnode)->right = NULL;
  create_tree(&((*pnode)->left));
  create_tree(&((*pnode)->right));
}

void print_tree_1(node *pnode, int *index) {// 前序遍历
  if (!pnode) {
    store1[*index] = -1;
    (*index)++;
    return;
  }
  store1[*index] = pnode->val;
  (*index)++;
  print_tree_1(pnode->left, index);
  print_tree_1(pnode->right, index);
}

void print_tree_2(node *pnode, int *index) {// 后两个反过来的前序遍历
  if (!pnode) {
    store2[*index] = -1;
    (*index)++;
    return;
  }
  store2[*index] = pnode->val;
  (*index)++;
  print_tree_2(pnode->right, index);
  print_tree_2(pnode->left, index);
}
```
