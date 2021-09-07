#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "arange.h"

int main(void) {
  std::cout << "Arange examples.\n";
  std::cout << std::fixed << std::setprecision(1);

  std::cout << "\nIncreasing range: ";
  for (auto x : make_arange(0.0, 1.0, 0.1))
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "\nDecreasing range: ";
  for (auto x : make_arange(0.0, -1.0, -0.1))
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "\nstd::copy() from generator to vector...\n";
  auto gen = make_arange(0, 10);
  std::vector<size_t> res;
  std::copy(gen.begin(), gen.end(), std::back_inserter(res));

  std::cout << "Vector contents:\n";
  for (auto x : res)
    std::cout << x << " ";
  std::cout << "\n";

  // Reset gen and do dtype conv by inserting to a float container
  gen = make_arange(0, 10);
  std::vector<float> res1;
  std::copy(gen.begin(), gen.end(), std::back_inserter(res1));

  std::cout << "Float vector contents:\n";
  for (auto x : res1)
    std::cout << x << " ";
  std::cout << "\n";
}

