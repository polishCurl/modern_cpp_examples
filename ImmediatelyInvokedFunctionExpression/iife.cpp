#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

class C {
 public:
  C(int a, int b) : i_{[a, b]() { return (a + b) % b; }()} {
    std::cout << "C::i_ = " << i_ << '\n';
  }

 private:
  const int i_;
};

int main() {
  srand(time(NULL));
  const auto i = rand();

  const std::string str = [i]() {
    switch (i % 4) {
      case 0:
        return "divisible by 4";
      case 1:
        return "is mod 1";
      case 2:
        return "is mod 2";
      case 3:
        return "is mod 3";
      default:
        return "invalid";
    }
  }();

  std::cout << "i is " << str << '\n';

  C c{3, 6};

  return 0;
}