#include <string>
#include <vector>

// Removing the comments from main() and building this file should show a
// compiler error, e.g.:
// "error: implicit instantiation of undefined template
// 'ShowType<std::vector<std::pair<int, std::string>>>' ShowType<decltype(x)>
// x_type;"

template <typename T>
class ShowType;

using Fraction = double;

int main() {
  // ShowType<decltype(75)> int_type;
  std::vector<std::pair<int, std::string>> x;
  // ShowType<decltype(x)> x_type;
  Fraction fraction;
  // ShowType<decltype(fraction)> fraction_type;
}