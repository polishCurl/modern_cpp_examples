# modern_cpp_examples
Small examples of modern C++ features

This project also demonstrates minimal usage of cmake for building c++ projects.

This project is heavily inspired by Scott Meyer's 'Effective Modern C++' book.

### List of modern C++ (c++11 or newer) examples
1. Using `typeid()` for printing type information at runtime and `__cxa_demangle()` for printing demangled names.
2. Using class template without definition for printing type information at compile time.
3. Compare the memory size of different closures using lambdas.
4. Benefits of uniform (braced `{}` )initialization over `=` and `()`, together with pitfalls of braced initialization.
5. Show the benefits of using `nullptr` over `NULL` or `0`.
6. Invoking `lambda` as soon as it is defined for complex initialization of constant variables -- _Immediately Invoked Function Expression_ (IIFE)
7. Show benefits of `enum class` over c++98's _unscoped enum_
8. Using `delete`d functions to ban usage of member functions.
