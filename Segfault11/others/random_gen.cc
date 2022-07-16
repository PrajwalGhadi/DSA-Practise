#include <iostream>
#include <random>

int main() {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_int_distribution<> distribution(1, 9);

  for (int i = 0; i < 10; ++i) {
    std::cout << distribution(gen) << "\n";
  }
  return 0;
}