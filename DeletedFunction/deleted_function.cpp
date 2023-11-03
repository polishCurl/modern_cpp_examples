#include <iostream>

// c++98 way of banning copy constructor and copy assignment
class C {
 public:
  C(){};

 private:
  C(const C& c);
  C& operator=(const C& c);
};

// c++11 way of banning copy constructor and copy assignment
class D {
 public:
  D() = default;
  D(const D& d) = delete;
  D& operator=(const D& d) = delete;
};

// Use 'delete' to ban implicit casts
void square(int n) { std::cout << "Square: " << (n * n) << '\n'; };
void square(float n) = delete;
void square(bool n) = delete;

int main() {
  C c1{};

  // calling a private constructor of class 'C'
  // C c2{c1};

  D d1{};

  // call to deleted constructor of 'D'
  // D d2{d1};

  square(2);

  // Calling square() with floar or bool is forbidden
  // square(false);
  // square(5.4);
}