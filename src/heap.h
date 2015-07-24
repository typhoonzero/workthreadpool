#include <vector>
#include <stdio.h>

using namespace std;

class Heap {
 public:
  Heap(const vector<int> &array) {
    size_ = array.size();
    printf("size: %d\n", size_);
    array_ = array;
    // 产生一个最大堆
    for (int i = size_/2; i >= 0; i--) {
    int y = array_[i]; // 地一个有孩子的子树的根
    // 寻找放置 y的位置
    int c = 2*i; // c的父节点是 y的目标位置(child)
    while (c <= size_) {
      // heap[c] 应是较大的同胞节点
      if (c < size_ && array_[c] < array_[c+1]) c++;
      // 能把 y 放入h e a p [ c / 2 ]吗?
      if (y >= array_[c]) break; // 能
      // 不能
      array_[c/2] = array_[c]; // 将孩子上移
      c *= 2; // 下移一层
    }
    array_[c/2] = y;
    }
  }
  void show() {
    for (int i=0; i<size_; i++) {
      printf("%d ", array_[i]);
    }
    printf("\n");
  }

 private:
  unsigned int size_;
  vector<int> array_;

};

//int main() {
//  int a[10] = {10, 39, 2, 21, 30, 15, 20, 49, 36, 1};
//  vector<int> ar;
//  for (int i=0; i<10; i++) {
//    ar.push_back(a[i]);
//  }
//  Heap hp(ar);
//  hp.show();
//}
