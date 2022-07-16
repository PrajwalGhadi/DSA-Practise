#include <iostream>
#include <type_traits>
#include <vector>

int main() {
  std::cout << std::boolalpha;

  std::cout << "std::remove_reference<int>::type is int? " << std::is_same<int, std::remove_reference<int>::type>::value
            << '\n';
  std::cout << "std::remove_reference<int&>::type is int? "
            << std::is_same<int, std::remove_reference<int&>::type>::value << '\n';
  std::cout << "std::remove_reference<int&&>::type is int? "
            << std::is_same<int, std::remove_reference<int&&>::type>::value << '\n';
  std::cout << "std::remove_reference<const int&>::type is const int? "
            << std::is_same<int, std::remove_reference<const int&>::type>::value << '\n';

  std::cout << "std::remove_reference<const int&>::type is const int? "
            << std::is_same<int, std::remove_cv<const int>::type>::value << '\n';
}