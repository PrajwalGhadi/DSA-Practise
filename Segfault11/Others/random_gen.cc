#include <iostream>
#include <random>

int main() {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_real_distribution<> distribution(-1, 1);

  for (int i = 0; i < 10; ++i) {
    std::cout << distribution(gen) << "\n";
  }
  return 0;
}