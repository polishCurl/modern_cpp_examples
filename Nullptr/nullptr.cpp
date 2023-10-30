#include <iostream>

void f(int) { std::cout << "f(int)\n"; }
void f(bool) { std::cout << "f(bool)\n"; }
void f(void*) { std::cout << "f(void*)\n"; }

int main() {
  f(3);
  f(false);

  // call to 'f' is ambiguous
  // f(NULL);

  f(nullptr);
}