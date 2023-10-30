#include <iostream>
#include <vector>

#define PRINT_VARIABLE_NAME(name) (#name)

class C {
 private:
  int x_ = 3;

  // Forbidden
  // int y_(4);

  int z_{5};
};

class D {
 public:
  D() { std::cout << "default constructor\n"; }
  D(int a, bool b) { std::cout << "1st constuctor\n"; }
  D(int a, double d) { std::cout << "2nd constuctor\n"; }
  D(std::initializer_list<int>) {
    std::cout << "initializer_list constuctor\n";
  }
};

int main() {
  int a = 3;
  int b(5);
  int c{10};

  double d{3.1};
  // Narrowing conversion is forbidden with braced init
  // float f{d};

  // 'Copy constructor is deleted' error for C++14 or lower
  // std::atomic<int> ai3 = 0;

  std::vector<int> v_curly(4, 10);
  std::cout << PRINT_VARIABLE_NAME(v_curly) << " size: " << v_curly.size()
            << '\n';
  // With braced initializtion compilers prefer matching constructor arguments
  // with std::initializer_list.
  std::vector<int> v_braced{4, 10};
  std::cout << PRINT_VARIABLE_NAME(v_braced) << " size: " << v_braced.size()
            << '\n';

  D d1(3, false);
  D d2(3, 2.1);

  // initializer_list constructor is used
  D d3{3, false};

  // Compiler chooses D constructor with initializer_list argument but does not
  // like the narrowing of the second elemend: "type 'double' cannot be narrowed
  // to 'int' in initializer list"
  // D d4{3, 2.1};

  // Most vexing parse means a function is declared
  D d5();
  D d6{};
}