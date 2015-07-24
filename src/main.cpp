#include "workthreadpool.h"
#include <sstream>
#include <math.h>

class MyThreadPool : public bfd::WorkThreadPool {
 public:
  MyThreadPool(int size) : bfd::WorkThreadPool(size) {
  }
  void Handle(const string &msg) {
    stringstream ss;
    ss << "worker (" << std::this_thread::get_id() << ") got msg: " << msg;
    printf("%s\n", ss.str().c_str());
    for (int i=0; i<=999999; i++) {
      double result = sqrt(sqrt(i) / 93.234);
    }
  }
};

int main() {
  printf("start running ....\n");
  MyThreadPool pool(5);
  pool.Start();
  for (int i=0; i<100; i++) {
    pool.SendMessage("msg info ----------");
  }
  pool.Stop();

  return 0;
}
