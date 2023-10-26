#include <cxxabi.h>

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
auto getTypeName(T name) {
  int status;
  return std::string(
      abi::__cxa_demangle(typeid(name).name(), nullptr, 0, &status));
}

class Type {
 public:
  int integer_[20];
};

int main() {
  std::cout << getTypeName(int{32}) << '\n';
  std::cout << getTypeName(std::vector<std::pair<bool, int>>()) << '\n';

  Type t;
  std::cout << getTypeName(t) << '\n';
  std::cout << getTypeName(t.integer_) << '\n';
}