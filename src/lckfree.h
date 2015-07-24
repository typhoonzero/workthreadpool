// lckfree.h
// Implementation of lock free queue using CAS operations
// for simple multi-threading use cases like:
// 1. multiple worker to process incoming messages
// 2. async processing using a thread pool
// 3. simple tcp server deal with async requests
// Author: typhoon_1986@163.com
// Refrence: http://coolshell.cn/articles/8239.html

#ifndef __LCKFREE_H__
#define __LCKFREE_H__

#include <string>
using namespace std;

namespace bfd {

struct LinkNode {
  string data;
  LinkNode* next;
};
typedef struct LinkNode LinkNode;

class LckFreeQueue {
 public:
  LckFreeQueue();
  ~LckFreeQueue();

  int push(const string &msg);
  string pop();  // non-block pop method
//  string bpop(); // block pop method
  bool empty();
 private:
  LinkNode * head_;
  LinkNode * tail_;
  bool empty_;
  unsigned int length_;
};

} // namespace bfd
#endif
