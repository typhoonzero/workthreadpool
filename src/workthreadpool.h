// workthreadpool.h
// 一个用于将消息分发给多个进程，并使用多个进程处理的库，工作进程并不返回数据
#ifndef __WORK_THREAD_POOL__
#define __WORK_THREAD_POOL__

#include <stdio.h>
#include <thread>
#include <queue>
#include <string>
#include <vector>
#include "lckfree.h"

using namespace std;
namespace bfd {

class WorkThreadPool {
 public:
  WorkThreadPool(int size);
  virtual ~WorkThreadPool();

  // 需要子类继承并实现的函数，每个线程实际执行的内容
  virtual void Init() {};
  virtual void Finish() {};
  virtual void Handle(const string &msg)=0;

  // 将消息放入处理队列, 消息只支持string类型
  int SendMessage(const string &msg);

  int Start();
  int Stop();

 private:
  void Worker();

  int size_;
  LckFreeQueue msg_queue_; // 线程池的协作基于这个无锁队列
  vector<thread> thread_pool_;
};
} // namespace
#endif
