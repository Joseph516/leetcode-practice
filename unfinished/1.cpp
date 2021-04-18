
#include <iostream>
using namespace std;
struct BiNode {
  char data;
  BiNode *lchild, *rchild;
};
char a[200];
int flag, len, k;

class BiTree {
 private:
  BiNode *root;
  BiNode *Creat(BiNode *bt) {
    char ch;
    cin >> ch;
    if (ch == '#') {
      bt = NULL;
    } else {
      len++;
      flag = 1;
      bt = new BiNode;
      bt->data = ch;
      bt->lchild = Creat(bt->lchild);
      bt->rchild = Creat(bt->rchild);
    }
    return bt;
  }
  void Release(BiNode *bt) {
    if (bt != NULL) {
      Release(bt->lchild);
      Release(bt->rchild);
      delete bt;
    }
  }

 public:
  BiTree() { root = Creat(root); }
  void LeverOrder() {
    int front, rear;
    front = rear = -1;
    BiNode *S[100], *q;
    if (root == NULL) return;
    S[++rear] = root;
    while (front != rear) {
      q = S[++front];
      cout << q->data;
      if (q->data != '#') k++;
      if (len == k) break;
      if (q->lchild != NULL)
        S[++rear] = q->lchild;
      else {
        BiNode *r = new BiNode;
        r->data = '#';
        r->lchild = NULL;
        r->rchild = NULL;
        S[++rear] = r;
      }
      if (q->rchild != NULL)
        S[++rear] = q->rchild;
      else {
        BiNode *t = new BiNode;
        t->data = '#';
        t->lchild = NULL;
        t->rchild = NULL;
        S[++rear] = t;
      }
    }
    cout << endl;
  }
  ~BiTree() { Release(root); }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    flag = len = k = 0;
    BiTree A;
    if (flag == 0) {
      cout << '#' << endl;
      continue;
    }
    A.LeverOrder();
  }
  return 0;
}