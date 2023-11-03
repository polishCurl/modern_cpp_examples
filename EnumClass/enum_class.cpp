
#include <iostream>

int square(int n) { return n * n; }

// Forward reference of 'enum' type is forbidden unless size is specified
// enum Direction;
enum Direction : std::uint8_t;

// Forward reference of 'enum class' type is allowed
enum class GermanBrand : bool;

int main() {
  enum Direction { west, east, north, south };

  // Error: redefinition of 'west' as different kind of symbol
  // int west{3};
  // std::string south{"south"};

  // Enums are implicitly converted to integers
  std::cout << "Enum 'squared': " << square(north) << '\n';

  enum class GermanBrand { mercedes, bmw, audi, volkswagen, porsche, opel };

  // Enum class have values defined only within the scope of the enum
  std::string porsche{"911"};

  // Implicit cast is forbidden. Explicit casts to integers are possible.
  // std::cout << "Enum class 'squared': " << square(GermanBrand::bmw) << '\n';
  std::cout << "Enum class 'squared': "
            << square(static_cast<int>(GermanBrand::bmw)) << '\n';

  return 0;
}