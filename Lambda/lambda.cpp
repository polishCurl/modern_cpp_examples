#include <iostream>
#include <string>

#define GET_VARIABLE_NAME(Variable) (#Variable)

int main() {
  // Print the size of lambda which returns const
  auto lambda_func_ptr = []() { return 4; };
  std::cout << "FUNCTION PTR lambda size: " << sizeof(lambda_func_ptr) << '\n';

  // Print the size of lambda which does not capture any variables
  auto lambda = [](std::string s, char c) {
    return s.find(c) != std::string::npos;
  };
  std::cout << "AUTO lambda size: " << sizeof(lambda) << '\n';

  // Print the size of lambda which captures a variable by copy
  std::string test_str{"tester"};
  auto lambda_capture = [test_str](char c) {
    return test_str.find(c) != std::string::npos;
  };
  std::cout << "AUTO (+capture by value) lambda size: "
            << sizeof(lambda_capture) << '\n';

  // Print the size of lambda which captures a variable by reference
  auto lambda_capture_ref = [&test_str](char c) {
    return test_str.find(c) != std::string::npos;
  };
  std::cout << "AUTO (+capture by ref) lambda size: "
            << sizeof(lambda_capture_ref) << '\n';

  // Print the size of lambda which is stored in std::function variable
  std::function<bool(char c)> lambda_functor = lambda_capture;
  std::cout << "FUNCTOR size: " << sizeof(lambda_functor) << '\n';
}